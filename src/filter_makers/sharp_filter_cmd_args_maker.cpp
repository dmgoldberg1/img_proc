#include "../../headers/filter_makers/sharp_filter_cmd_args_maker.h"
#include "../../headers/filters/sharp_filter.h"

#include <stdexcept>

BaseFilter* CreateSharpFilterFromCmdArgs(const FilterDescriptor* fd) {
    if (fd->filter_name != "-sharp") {
        throw std::logic_error("Invalid filter descriptor.");
    }

    SharpFilter* filter = new SharpFilter();
    return filter;
}