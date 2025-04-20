#ifndef FILTERPIPELINE_H
#define FILTERPIPELINE_H

#include "../image/dib.h"
#include "../filters/base_filter.h"

#include <vector>

class FilterPipeline {
public:
    using FilterCollection = std::vector<BaseFilter*>;

public:
    ~FilterPipeline() {
        for (BaseFilter* filter : coll_) {
            delete filter;
        }
    }
    bool Apply(Dib* img) const;
    BaseFilter* AddFilter(BaseFilter* filter);
    const size_t GetFilterCount() const {
        return coll_.size();
    }

protected:
    FilterCollection coll_;
};

#endif
