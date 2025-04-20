#ifndef GS_FILTER_H
#define GS_FILTER_H

#include "base_filter.h"
#include "../image/dib.h"

class GsFilter : public BaseFilter {
public:
    ~GsFilter() override;

public:
    bool Apply(Dib* img) const override;

protected:
    const double r_coeff_ = 0.299;
    const double g_coeff_ = 0.587;
    const double b_coeff_ = 0.114;
};

#endif
