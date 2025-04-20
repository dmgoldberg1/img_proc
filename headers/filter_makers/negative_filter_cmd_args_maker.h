#ifndef CREATE_NEGATIVE_H
#define CREATE_NEGATIVE_H

#include "../parser/cmd_line_args_parser.h"
#include "../filters/base_filter.h"

BaseFilter* CreateNegativeFilterFromCmdArgs(const FilterDescriptor* fd);

#endif
