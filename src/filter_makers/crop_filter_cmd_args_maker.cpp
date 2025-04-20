#include "../../headers/filter_makers/crop_filter_cmd_args_maker.h"
#include "../../headers/filters/crop_filter.h"

#include <stdexcept>
#include <string>

BaseFilter* CreateCropFilterFromCmdArgs(const FilterDescriptor* fd) {
    if (fd->filter_name != "-crop") {
        throw std::logic_error("Invalid filter descriptor.");
    }

    if (fd->GetFilterParamsCount() < 2) {
        throw std::logic_error("Invalid crop filter parameters count.");
    }
    int width = std::stoi(fd->filter_params[WIDTH]);
    int height = std::stoi(fd->filter_params[HEIGHT]);
    CropFilter* filter = new CropFilter(width, height);
    return filter;
}