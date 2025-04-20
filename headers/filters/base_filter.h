#ifndef BASE_FILTER_H
#define BASE_FILTER_H

#include "../image/dib.h"

class BaseFilter {
public:
    virtual ~BaseFilter();

public:
    virtual bool Apply(Dib* img) const = 0;
};

#endif