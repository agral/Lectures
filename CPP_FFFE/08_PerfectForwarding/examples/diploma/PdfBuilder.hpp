/**
 * Name: PdfBuilder.hpp
 * Description: Provides an interface to a class that builds PDF pages.
 * Created on: 08.07.2021
 * Last modified: 09.07.2021
 * Author: gralin.ski
 * License: CC0
 */

#pragma once

#include <cairo.h>
#include <string>

const double A4_WIDTH_POINTS = 11.7 * 72;
const double A4_HEIGHT_POINTS = 8.3 * 72;
const double MARGIN = 20;

class PdfBuilder
{
 public:
  PdfBuilder(const std::string& filename);
  ~PdfBuilder();

  void draw_background();
  void draw_border();
  void draw_title();
  void draw_flavor_text(const std::string& awardee = "John Doe");

 private:
  std::string filename_;
  cairo_surface_t* csurface_;
  cairo_t* cr_;
};
