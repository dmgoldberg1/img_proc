#include "../../headers/filters/negative_filter.h"
#include "../../headers/image/dib.h"

bool NegativeFilter::Apply(Dib* img) const {
    if (img->GetPixels().empty()) {
        return false;
    }
    uint32_t height = img->GetHeight();
    uint32_t width = img->GetWidth();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Dib::Pixel curr_pixel = img->GetPixel(y, x);
            Dib::Pixel new_pixel;
            new_pixel.r = 255 - curr_pixel.r;
            new_pixel.g = 255 - curr_pixel.g;
            new_pixel.b = 255 - curr_pixel.b;
            img->SetPixel(y, x, new_pixel);
        }
    }
    return true;
}

NegativeFilter::~NegativeFilter() {
}