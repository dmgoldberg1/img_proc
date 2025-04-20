#include "../../headers/image/bmp_wrap.h"

#include <fstream>

bool BMPWrapper::ReadHeaders(std::istream& istr) {
    if (!istr.good()) {
        return false;
    }
    istr.read(reinterpret_cast<char*>(&bmp_header_), BMP_HEADER_SIZE);
    if (!istr.good()) {
        return false;
    }
    if (bmp_header_.sign != SIGNATURE) {
        return false;
    }
    istr.read(reinterpret_cast<char*>(&dib_header_), DIB_HEADER_SIZE);
    if (!istr.good()) {
        return false;
    }

    return true;
}
