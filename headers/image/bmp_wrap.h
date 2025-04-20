#ifndef BMP_WRAP_H
#define BMP_WRAP_H

#include <cstdint>
#include <string>

class BMPWrapper {
public:
    struct BMPHeader {
        uint16_t sign;
        uint32_t size;
        uint16_t reserved_a;
        uint16_t reserved_b;
        uint32_t pixel_offset;
    } __attribute__((packed));

    struct DIBHeader {
        uint32_t header_size;
        uint32_t width;
        uint32_t height;
        uint16_t color_planes;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t image_size;
        uint32_t horizontal_resolution;
        uint32_t vertical_resolution;
        uint32_t palette_size;
        uint32_t important_colors;
    } __attribute__((packed));

    const size_t BMP_HEADER_SIZE = sizeof(BMPHeader);
    const size_t DIB_HEADER_SIZE = sizeof(DIBHeader);
    const uint32_t HEADERS_SIZE = 54;
    const uint16_t SIGNATURE = 0x4D42;

public:
    bool ReadHeaders(std::istream& istr);
    const DIBHeader GetDIBHeader() const {
        return dib_header_;
    }
    const BMPHeader GetBMPHeader() const {
        return bmp_header_;
    }
    void SetDIBHeaderWidth(uint32_t width) {
        dib_header_.width = width;
    }
    void SetDIBHeaderHeight(uint32_t height) {
        dib_header_.height = height;
    }
    void SetBMPHeaderSize(uint32_t size) {
        bmp_header_.size = size;
    }
    void SetDIBHeaderImageSize(uint32_t image_size) {
        dib_header_.image_size = image_size;
    }

protected:
    BMPHeader bmp_header_;
    DIBHeader dib_header_;
};

#endif