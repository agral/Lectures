#include <iostream>
#include "PdfBuilder.hpp"

int main()
{
  std::cout << "Main()\n";
  {
    PdfBuilder builder("diploma.pdf");
    builder.draw_background();
    builder.draw_border();
    builder.draw_title();
    builder.draw_flavor_text("Mr. John Doe");
  }
}
