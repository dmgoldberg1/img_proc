#ifndef FILTER_H
#define FILTER_H

#include "base_filter.h"
#include "../image/dib.h"

class CropFilter : public BaseFilter {
public:
    CropFilter(uint32_t width, uint32_t height) : width_{width}, height_{height} {
    }
    ~CropFilter() override;

public:
    bool Apply(Dib* img) const override;

protected:
    uint32_t width_;
    uint32_t height_;
};

#endif  // FILTER_H
