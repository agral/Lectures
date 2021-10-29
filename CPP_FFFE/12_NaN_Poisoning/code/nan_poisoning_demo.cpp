#include <cmath>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

struct Point {
  double time_seconds;
  double distance_from_origin_meters;
};

std::vector<Point> raw_gps_points;

int main()
{
  // Read odometer data from file:
  std::ifstream raw_data_stream("../code/gps_data.txt");
  if (!raw_data_stream.good()) {
    std::cerr << "Error: file gps_data.txt can not be opened. Aborting.\n";
    exit(1);
  }
  Point p;
  while (raw_data_stream >> p.time_seconds >> p.distance_from_origin_meters) {
    raw_gps_points.push_back(p);
  }
  std::cout << "Read " << raw_gps_points.size() << " points.\n";

  // Compute vector of velocities: dv = ds / dt.
  std::vector<double> velocities;

  // For first measurement point, the velocity is always 0:
  velocities.push_back(0.0);

  // Then the transient velocity is calculated as dv = ds / dt, where ds is a distance travelled, and dt is a time increment.
  for (std::size_t idx = 1; idx < raw_gps_points.size(); ++idx) {
    double delta_v = (raw_gps_points[idx].distance_from_origin_meters - raw_gps_points[idx-1].distance_from_origin_meters)
        / (raw_gps_points[idx].time_seconds - raw_gps_points[idx-1].time_seconds);
    velocities.push_back(delta_v);
  }
  std::cout << "Calculated " << velocities.size() << " transient velocities.\n";

  // Calculate the average velocity for the entire run:
  double avg_velocity = std::accumulate(velocities.begin(), velocities.end(), 0.0) / velocities.size();
  //std::cout << "The average velocity is " << avg_velocity << "\n";

  // If average velocity >= 3.0, the user has been running:
  bool isExerciseRun = (avg_velocity >= 3.0);
  std::cout << "You have " << (isExerciseRun ? "" : "NOT") << " been running today.\n";

  /*
  if (std::isnan(avg_velocity)) {
    std::cout << "Oh no, avg_velocity is Not-A-Number!\n";
  }
  */
}
