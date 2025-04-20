#include "../../headers/image/dib.h"

#include <fstream>
#include <algorithm>

Dib Dib::ReadFromFile(const std::string& file_name) {
    Dib image;
    std::ifstream file(file_name, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open()) {
        return image;
    }
    bool is_read_headers = image.bmp_wrapper_.ReadHeaders(file);
    if (!is_read_headers) {
        return image;
    }
    auto dib_header = image.bmp_wrapper_.GetDIBHeader();
    image.width_ = dib_header.width;
    image.height_ = dib_header.height;
    image.ReadPixels(file);
    return image;
}

bool Dib::ReadPixels(std::istream& istr) {
    if (!istr.good()) {
        return false;
    }
    int padding_size = (PADDING_BYTE_SIZE - (width_ * PIXEL_BYTE_SIZE) % PADDING_BYTE_SIZE) % PADDING_BYTE_SIZE;
    pixels_.resize(width_ * height_);
    for (int y = height_ - 1; y >= 0; --y) {
        for (int x = 0; x < width_; ++x) {
            Pixel pixel;
            istr.read(reinterpret_cast<char*>(&pixel), 3);
            if (!istr.good()) {
                return false;
            }
            pixels_[width_ * y + x] = pixel;
        }
        istr.seekg(padding_size, std::ios::cur);
    }
    return true;
}

bool Dib::SaveToFile(const std::string& file_name, Dib* image) {
    if (image->GetPixels().empty()) {
        return false;
    }
    std::ofstream file(file_name, std::ios_base::out | std::ios_base::binary);
    if (!file.is_open()) {
        return false;
    }
    auto dib_header = image->bmp_wrapper_.GetDIBHeader();
    auto bmp_header = image->bmp_wrapper_.GetBMPHeader();
    file.write(reinterpret_cast<const char*>(&bmp_header), image->bmp_wrapper_.BMP_HEADER_SIZE);
    file.write(reinterpret_cast<const char*>(&dib_header), image->bmp_wrapper_.DIB_HEADER_SIZE);
    image->WritePixels(file);
    return true;
}

bool Dib::WritePixels(std::ofstream& ostr) {
    if (pixels_.empty()) {
        return false;
    }
    int padding_size = (PADDING_BYTE_SIZE - (width_ * PIXEL_BYTE_SIZE) % PADDING_BYTE_SIZE) % PADDING_BYTE_SIZE;
    char padding[3]{0, 0, 0};
    for (int y = height_ - 1; y >= 0; --y) {
        for (int x = 0; x < width_; ++x) {
            ;
            if (!ostr.good()) {
                return false;
            }
            Pixel pixel = pixels_[width_ * y + x];
            ostr.put(pixel.b);
            ostr.put(pixel.g);
            ostr.put(pixel.r);
        }
        ostr.write(padding, padding_size);
    }

    return true;
}
void Dib::SetWidthAndHeight(uint32_t width, uint32_t height) {
    int padding_size = (4 - (width * 3) % 4) % 4;
    uint32_t image_size = (width * 3 + padding_size) * height;
    uint32_t actual_size = bmp_wrapper_.HEADERS_SIZE + image_size;
    width_ = width;
    height_ = height;
    bmp_wrapper_.SetBMPHeaderSize(actual_size);
    bmp_wrapper_.SetDIBHeaderHeight(height_);
    bmp_wrapper_.SetDIBHeaderWidth(width_);
    bmp_wrapper_.SetDIBHeaderImageSize(image_size);
}
const Dib::Pixel Dib::GetPixel(int i, int j) const {
    int lower = 0;
    int higher_i = static_cast<int>(height_);
    int higher_j = static_cast<int>(width_);
    i = std::clamp(i, lower, higher_i - 1);
    j = std::clamp(j, lower, higher_j - 1);
    return pixels_[i * width_ + j];
}