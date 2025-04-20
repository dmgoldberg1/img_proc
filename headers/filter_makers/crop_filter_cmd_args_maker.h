#ifndef CREATE_CROP_H
#define CREATE_CROP_H

#include "../parser/cmd_line_args_parser.h"
#include "../filters/base_filter.h"

BaseFilter* CreateCropFilterFromCmdArgs(const FilterDescriptor* fd);

const int WIDTH = 0;
const int HEIGHT = 1;

#endif