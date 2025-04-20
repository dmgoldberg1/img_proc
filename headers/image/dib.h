#ifndef DIB_H
#define DIB_H

#include "bmp_wrap.h"

#include <cstdint>
#include <string>
#include <vector>

class Dib {
public:
    struct Pixel {
        uint8_t b;
        uint8_t g;
        uint8_t r;
    };
    const Pixel GetPixel(int i, int j) const;
    const uint32_t GetWidth() const {
        return width_;
    }
    const uint32_t GetHeight() const {
        return height_;
    }
    const std::vector<Pixel> GetPixels() const {
        return pixels_;
    }
    void SetPixels(const std::vector<Pixel>& pixels) {
        pixels_ = pixels;
    }
    void SetPixelsByMoving(std::vector<Pixel>&& pixels) {
        pixels_ = std::move(pixels);
    }
    void SetWidthAndHeight(uint32_t width, uint32_t height);
    void SetPixel(size_t i, size_t j, Pixel pixel) {
        pixels_[i * width_ + j] = pixel;
    }

public:
    static Dib ReadFromFile(const std::string& file_name);
    static bool SaveToFile(const std::string& file_name, Dib* image);

public:
    const int PIXEL_BYTE_SIZE = 3;
    const int PADDING_BYTE_SIZE = 4;

protected:
    bool ReadPixels(std::istream& istr);
    bool WritePixels(std::ofstream& ostr);
    uint32_t width_;
    uint32_t height_;
    std::vector<Pixel> pixels_;
    BMPWrapper bmp_wrapper_;
};

#endif  // DIB_H
