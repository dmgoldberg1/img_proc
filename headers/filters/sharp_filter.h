#ifndef SHARP_FILTER_H
#define SHARP_FILTER_H

#include "base_filter.h"
#include "../image/dib.h"

class SharpFilter : public BaseFilter {
public:
    ~SharpFilter() override;

public:
    bool Apply(Dib* img) const override;

protected:
    const int up_coeff_ = -1;
    const int down_coeff_ = -1;
    const int left_coeff_ = -1;
    const int right_coeff_ = -1;
    const int target_coeff_ = 5;
    const int CHANEL_MAX_VALUE = 255;
};

#endif
