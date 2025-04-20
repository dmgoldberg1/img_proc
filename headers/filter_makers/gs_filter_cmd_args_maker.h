#ifndef CREATE_GS_H
#define CREATE_GS_H

#include "../parser/cmd_line_args_parser.h"
#include "../filters/base_filter.h"

BaseFilter* CreateGsFilterFromCmdArgs(const FilterDescriptor* fd);

#endif
