#include "../../headers/factory/filterpipeline.h"

#include <stdexcept>

bool FilterPipeline::Apply(Dib* img) const {
    for (const BaseFilter* filter : coll_) {
        if (!filter) {
            throw std::invalid_argument("Filter is null.");
        }
        bool res = filter->Apply(img);
        if (!res) {
            throw std::logic_error("Try to apply filter to an empty image.");
        }
    }
    return true;
}

BaseFilter* FilterPipeline::AddFilter(BaseFilter* filter) {
    coll_.push_back(filter);
    return filter;
}