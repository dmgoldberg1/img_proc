#include "../../headers/filters/gs_filter.h"
#include "../../headers/image/dib.h"

bool GsFilter::Apply(Dib* img) const {
    if (img->GetPixels().empty()) {
        return false;
    }
    uint32_t height = img->GetHeight();
    uint32_t width = img->GetWidth();
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            Dib::Pixel curr_pixel = img->GetPixel(y, x);
            Dib::Pixel new_pixel;
            new_pixel.r = curr_pixel.r * r_coeff_ + curr_pixel.b * b_coeff_ + curr_pixel.g * g_coeff_;
            new_pixel.g = curr_pixel.r * r_coeff_ + curr_pixel.b * b_coeff_ + curr_pixel.g * g_coeff_;
            new_pixel.b = curr_pixel.r * r_coeff_ + curr_pixel.b * b_coeff_ + curr_pixel.g * g_coeff_;
            img->SetPixel(y, x, new_pixel);
        }
    }
    return true;
}

GsFilter::~GsFilter() {
}