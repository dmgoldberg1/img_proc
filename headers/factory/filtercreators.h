#ifndef FILTERCREATORS_H
#define FILTERCREATORS_H

#include "../parser/cmd_line_args_parser.h"
#include "filterpipeline.h"
#include "../../headers/filters/base_filter.h"
#include "../filter_makers/crop_filter_cmd_args_maker.h"
#include "../filter_makers/gs_filter_cmd_args_maker.h"
#include "../filter_makers/negative_filter_cmd_args_maker.h"
#include "../filter_makers/sharp_filter_cmd_args_maker.h"
#include "../filter_makers/edge_filter_cmd_args_maker.h"

#include <map>

class FilterCreatorFactory {
public:
    using PFunFilterCreator = BaseFilter* (*)(const FilterDescriptor* fd);
    using FilterName2CreatorMap = std::map<std::string, PFunFilterCreator>;

    BaseFilter* CreateFilter(const FilterDescriptor* fd);
    FilterPipeline CreatePipeline(const CmdLineArgsParser::FilterDescriptors& descriptors);
    void RegisterFilterCreator(const std::string& filter_name, PFunFilterCreator filter_creator);

protected:
    FilterName2CreatorMap filter_creator_mapping_;
};

#endif
