#include "../../headers/filters/crop_filter.h"
#include "../../headers/image/dib.h"

CropFilter::~CropFilter() {
}

bool CropFilter::Apply(Dib* img) const {
    if (img->GetPixels().empty()) {
        return false;
    }
    uint32_t new_width = std::min(img->GetWidth(), width_);
    uint32_t new_height = std::min(img->GetHeight(), height_);
    std::vector<Dib::Pixel> cropped_pixels;
    cropped_pixels.reserve(new_height * new_width);
    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            cropped_pixels.push_back(img->GetPixel(y, x));
        }
    }
    img->SetPixelsByMoving(std::move(cropped_pixels));
    img->SetWidthAndHeight(new_width, new_height);
    return true;
}
