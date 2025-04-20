#ifndef CREATE_EDGE_H
#define CREATE_EDGE_H

#include "../parser/cmd_line_args_parser.h"
#include "../filters/base_filter.h"

BaseFilter* CreateEdgeFilterFromCmdArgs(const FilterDescriptor* fd);

const int THRESHOLD = 0;

#endif