#ifndef NEG_FILTER_H
#define NEG_FILTER_H

#include "base_filter.h"
#include "../image/dib.h"

class NegativeFilter : public BaseFilter {
public:
    ~NegativeFilter() override;

public:
    bool Apply(Dib* img) const override;
};

#endif
