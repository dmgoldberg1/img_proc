#include "../../headers/filter_makers/gs_filter_cmd_args_maker.h"
#include "../../headers/filters/gs_filter.h"

#include <stdexcept>

BaseFilter* CreateGsFilterFromCmdArgs(const FilterDescriptor* fd) {
    if (fd->filter_name != "-gs") {
        throw std::logic_error("Invalid filter descriptor.");
    }

    GsFilter* filter = new GsFilter();
    return filter;
}