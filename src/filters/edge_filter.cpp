#include "../../headers/filters/edge_filter.h"
#include "../../headers/image/dib.h"
#include "../../headers/filters/gs_filter.h"

bool EdgeFilter::Apply(Dib* img) const {
    if (img->GetPixels().empty()) {
        return false;
    }
    uint32_t height = img->GetHeight();
    uint32_t width = img->GetWidth();
    GsFilter gs_filter;
    gs_filter.Apply(img);
    std::vector<Dib::Pixel> buffer;
    buffer.resize(height * width);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Dib::Pixel new_pixel;
            Dib::Pixel target_pixel = img->GetPixel(y, x);
            Dib::Pixel up_pixel = img->GetPixel(y - 1, x);
            Dib::Pixel down_pixel = img->GetPixel(y + 1, x);
            Dib::Pixel left_pixel = img->GetPixel(y, x - 1);
            Dib::Pixel right_pixel = img->GetPixel(y, x + 1);
            new_pixel.r =
                std::min(CHANEL_MAX_VALUE,
                         std::max(0, up_coeff_ * up_pixel.r + down_coeff_ * down_pixel.r + left_coeff_ * left_pixel.r +
                                         right_coeff_ * right_pixel.r + target_coeff_ * target_pixel.r));
            new_pixel.g =
                std::min(CHANEL_MAX_VALUE,
                         std::max(0, up_coeff_ * up_pixel.g + down_coeff_ * down_pixel.g + left_coeff_ * left_pixel.g +
                                         right_coeff_ * right_pixel.g + target_coeff_ * target_pixel.g));
            new_pixel.b =
                std::min(CHANEL_MAX_VALUE,
                         std::max(0, up_coeff_ * up_pixel.b + down_coeff_ * down_pixel.b + left_coeff_ * left_pixel.b +
                                         right_coeff_ * right_pixel.b + target_coeff_ * target_pixel.b));
            uint8_t edge = std::max(std::max(new_pixel.r, new_pixel.g), new_pixel.b);
            if (edge > threshold_) {
                new_pixel.r = 255;
                new_pixel.g = 255;
                new_pixel.b = 255;
            } else {
                new_pixel.r = 0;
                new_pixel.g = 0;
                new_pixel.b = 0;
            }
            buffer[y * width + x] = new_pixel;
        }
    }
    img->SetPixelsByMoving(std::move(buffer));
    return true;
}

EdgeFilter::~EdgeFilter() {
}