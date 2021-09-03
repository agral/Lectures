#include <cairo.h>
#include <cairo-pdf.h>
#include <cstdlib>
#include <iostream>

int main()
{
  cairo_surface_t* csurface =
      cairo_pdf_surface_create("file.pdf", 800, 600); // 1
  if (cairo_surface_status(csurface) != CAIRO_STATUS_SUCCESS) {
    std::cerr << "Could not generate cairo surface\n";
    std::exit(1);
  } else {
    std::cout << "Successfully created cairo surface\n";
  }
  cairo_t* cr = cairo_create(csurface); // 2

  // 3

  cairo_show_page(cr); // 4
  cairo_surface_destroy(csurface); // 5
  cairo_destroy(cr);               // 5
}
