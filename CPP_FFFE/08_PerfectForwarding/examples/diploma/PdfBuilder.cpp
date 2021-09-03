/**
 * Name: PdfBuilder.cpp
 * Description: Implements a class that builds PDF pages.
 * Created on: 08.07.2021
 * Last modified: 09.07.2021
 * Author: gralin.ski
 * License: CC0
 */

#include "PdfBuilder.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <cairo-pdf.h>

PdfBuilder::PdfBuilder(const std::string& filename)
: filename_(filename)
{
  std::cout << "Generating PDF surface...\n";
  csurface_ = cairo_pdf_surface_create(filename.c_str(), A4_WIDTH_POINTS, A4_HEIGHT_POINTS);
  if (cairo_surface_status(csurface_) != CAIRO_STATUS_SUCCESS) {
    std::cerr << "Could not generate csurface / cr.\n";
  }
  else {
    std::cout << "Successfully generated PDF surface.\n";
  }

  cr_ = cairo_create(csurface_);
}

PdfBuilder::~PdfBuilder()
{
  std::cout << "Cleaning up...\n";
  cairo_show_page(cr_);
  cairo_surface_destroy(csurface_);
  cairo_destroy(cr_);
}


void PdfBuilder::draw_background()
{
  cairo_new_path(cr_);
  cairo_rectangle(cr_, MARGIN, MARGIN, A4_WIDTH_POINTS - 2 * MARGIN, A4_HEIGHT_POINTS - 2 * MARGIN);
  cairo_clip(cr_);

  cairo_set_source_rgba(cr_, 0.2, 0.2, 0.2, 0.2);
  cairo_set_line_width(cr_, 0.4);
  for (int x = MARGIN; x < A4_WIDTH_POINTS - 2 * MARGIN; x += 40) {
    for (int y = MARGIN; y < A4_HEIGHT_POINTS - 2 * MARGIN; y += 40) {
      cairo_set_source_rgba(cr_,
          0.2 + 0.2 * (x / A4_WIDTH_POINTS), 0.2, 0.25 + 0.55 * (y / A4_HEIGHT_POINTS),
          0.7 - std::abs(x - 0.5 * A4_WIDTH_POINTS) / A4_WIDTH_POINTS
              - std::abs(y - 0.5 * A4_HEIGHT_POINTS) / A4_HEIGHT_POINTS
      );
      cairo_arc(cr_, x, y, 100, 0, 2 * M_PI);
      cairo_stroke(cr_);
    }
  }
  cairo_reset_clip(cr_);
}

void PdfBuilder::draw_border()
{
  cairo_set_source_rgb(cr_, 0, 0, 0);
  cairo_set_line_width(cr_, 0.7);
  cairo_rectangle(cr_, MARGIN, MARGIN, A4_WIDTH_POINTS - 2 * MARGIN, A4_HEIGHT_POINTS - 2 * MARGIN);
  cairo_stroke(cr_);
}

void PdfBuilder::draw_title()
{
  cairo_set_source_rgba(cr_, 0, 0, 0.3, 0.8);
  cairo_select_font_face(cr_, "Serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr_, 42.0);

  auto title = "Certificate of Accomplishment";

  cairo_text_extents_t extents;
  cairo_text_extents(cr_, title, &extents);

  cairo_move_to(
      cr_,
      0.5 * A4_WIDTH_POINTS - 0.5 * extents.width,
      0.3 * A4_HEIGHT_POINTS - 0.5 * extents.height
  );
  cairo_show_text(cr_, title);
}

void PdfBuilder::draw_flavor_text(const std::string& awardee)
{
  auto lines = std::vector<const char*> {
    "This certificate is awarded to",
    "................................................",
    "For outstanding performance in",
    "repeated drawing of simple shapes"
  };

  cairo_set_source_rgba(cr_, 0, 0.1, 0.4, 0.8);
  cairo_select_font_face(cr_, "Serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr_, 24.0);
  cairo_text_extents_t extents;
  for (std::size_t i = 0; i < lines.size(); ++i) {
    cairo_text_extents(cr_, lines[i], &extents);
    cairo_move_to(
        cr_,
        0.5 * A4_WIDTH_POINTS - 0.5 * extents.width,
        (0.4 + (0.07 * i)) * A4_HEIGHT_POINTS - 0.5 * extents.height
    );
    cairo_show_text(cr_, lines[i]);
  }

  cairo_set_source_rgba(cr_, 0.4, 0.2, 0.1, 0.9);
  cairo_select_font_face(cr_, "Cursive", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr_, 36.0);
  cairo_text_extents(cr_, awardee.c_str(), &extents);
  cairo_move_to(
      cr_,
      0.5 * A4_WIDTH_POINTS - 0.5 * extents.width,
      0.47 * A4_HEIGHT_POINTS - 0.5 * extents.height
  );
  cairo_show_text(cr_, awardee.c_str());
}
