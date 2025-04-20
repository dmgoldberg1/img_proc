#ifndef EDGE_FILTER_H
#define EDGE_FILTER_H

#include "base_filter.h"
#include "../image/dib.h"

class EdgeFilter : public BaseFilter {
public:
    ~EdgeFilter() override;
    EdgeFilter(double threshold) : threshold_(threshold) {
    }

public:
    bool Apply(Dib* img) const override;

protected:
    double threshold_;
    const int up_coeff_ = -1;
    const int down_coeff_ = -1;
    const int left_coeff_ = -1;
    const int right_coeff_ = -1;
    const int target_coeff_ = 4;
    const int CHANEL_MAX_VALUE = 255;
};

#endif
