#include "../../headers/filter_makers/edge_filter_cmd_args_maker.h"
#include "../../headers/filters/edge_filter.h"

#include <stdexcept>
#include <string>

BaseFilter* CreateEdgeFilterFromCmdArgs(const FilterDescriptor* fd) {
    if (fd->filter_name != "-edge" || fd->filter_params.empty()) {
        throw std::logic_error("Invalid filter descriptor.");
    }
    double threshold = std::stod(fd->filter_params[THRESHOLD]);
    EdgeFilter* filter = new EdgeFilter(threshold);
    return filter;
}