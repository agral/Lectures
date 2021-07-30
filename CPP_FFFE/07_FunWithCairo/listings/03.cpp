#include <cairo.h>
#include <cairo-pdf.h>
#include <cmath>
#include <iostream>

constexpr inline double mm_to_tp(double mm) { return mm / 25.4 * 72; }
const double A4_WIDTH = mm_to_tp(297);
const double A4_HEIGHT = mm_to_tp(210);

int main()
{
  cairo_surface_t* csurface =
      cairo_pdf_surface_create("file.pdf", A4_WIDTH, A4_HEIGHT); // 1
  if (cairo_surface_status(csurface) != CAIRO_STATUS_SUCCESS) {
    std::cerr << "Could not generate cairo surface\n";
    std::exit(1);
  } else {
    std::cout << "Successfully created cairo surface\n";
  }
  cairo_t* cr = cairo_create(csurface); // 2

  // 3
  cairo_set_line_width(cr, mm_to_tp(3));

  cairo_set_source_rgb(cr, 0.75, 1.0, 0.0);
  cairo_arc(cr, 0.25 * A4_WIDTH, 0.5 * A4_HEIGHT,
      mm_to_tp(30), 1.5 * M_PI, 3.0 * M_PI);
  cairo_stroke(cr);

  cairo_set_source_rgb(cr, 1.0, 0.75, 0.0);
  cairo_arc(cr, 0.5 * A4_WIDTH, 0.5 * A4_HEIGHT,
      mm_to_tp(30), 0.0, 2.0 * M_PI);
  cairo_stroke(cr);

  cairo_set_source_rgb(cr, 0.0, 0.75, 1.0);
  cairo_arc(cr, 0.75 * A4_WIDTH, 0.5 * A4_HEIGHT,
      mm_to_tp(30), 0.0 * M_PI, 1.5 * M_PI);
  cairo_stroke(cr);


  cairo_show_page(cr); // 4
  cairo_surface_destroy(csurface); // 5
  cairo_destroy(cr);               // 5
}
