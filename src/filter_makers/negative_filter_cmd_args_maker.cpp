#include "../../headers/filter_makers/negative_filter_cmd_args_maker.h"
#include "../../headers/filters/negative_filter.h"

#include <stdexcept>

BaseFilter* CreateNegativeFilterFromCmdArgs(const FilterDescriptor* fd) {
    if (fd->filter_name != "-neg") {
        throw std::logic_error("Invalid filter descriptor.");
    }

    NegativeFilter* filter = new NegativeFilter();
    return filter;
}