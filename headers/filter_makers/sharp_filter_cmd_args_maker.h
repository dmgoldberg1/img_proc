#ifndef CREATE_SHARP_H
#define CREATE_SHARP_H

#include "../parser/cmd_line_args_parser.h"
#include "../filters/base_filter.h"

BaseFilter* CreateSharpFilterFromCmdArgs(const FilterDescriptor* fd);

#endif
