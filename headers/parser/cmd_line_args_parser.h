#ifndef CMD_LINE_ARGS_PARSER_H
#define CMD_LINE_ARGS_PARSER_H

#include <string>
#include <vector>

struct FilterDescriptor {

    size_t GetFilterParamsCount() const {
        return filter_params.size();
    }
    std::string filter_name;
    std::vector<std::string> filter_params;
};

class CmdLineArgsParser {
public:
    enum class ErrorCode {
        Ok,
        NotEnoughArgs,
        InvalidFilterParameter,
    };

    enum class LineAttr {
        InFileName = 1,
        OutFileName,
    };

    using FilterDescriptors = std::vector<FilterDescriptor>;

    const int MIN_ARG_COUNT = 3;

public:
    CmdLineArgsParser() : in_file_name_{nullptr}, out_file_name_{nullptr} {
    }

public:
    ErrorCode Parse(int argc, char* argv[]);
    size_t GetFiltersCount() const {
        return filter_descriptors_.size();
    }

public:
    const char* GetInFileName() const {
        return in_file_name_;
    }
    const char* GetOutFileName() const {
        return out_file_name_;
    }
    const FilterDescriptors& GetFilterDescriptors() const {
        return filter_descriptors_;
    }

protected:
    char* in_file_name_;
    char* out_file_name_;
    FilterDescriptors filter_descriptors_;
};

#endif
