#include "../../headers/factory/filtercreators.h"
#include "../../headers/filters/base_filter.h"

#include <stdexcept>

BaseFilter* FilterCreatorFactory::CreateFilter(const FilterDescriptor* fd) {
    auto filter_creator_it = filter_creator_mapping_.find(fd->filter_name);
    if (filter_creator_it == filter_creator_mapping_.end()) {
        return nullptr;
    }
    PFunFilterCreator filter_creator = filter_creator_it->second;
    if (!filter_creator) {
        throw std::logic_error("Creator cannot be null function.");
    }
    BaseFilter* filter = filter_creator(fd);
    return filter;
}

FilterPipeline FilterCreatorFactory::CreatePipeline(const CmdLineArgsParser::FilterDescriptors& descriptors) {
    FilterPipeline pipeline;
    for (const FilterDescriptor& descr : descriptors) {
        BaseFilter* filter = CreateFilter(&descr);
        if (filter) {
            pipeline.AddFilter(filter);
        }
    }
    return pipeline;
}

void FilterCreatorFactory::RegisterFilterCreator(const std::string& filter_name, PFunFilterCreator filter_creator) {
    if (!filter_creator_mapping_.contains(filter_name)) {
        filter_creator_mapping_.insert({filter_name, filter_creator});
    }
}
