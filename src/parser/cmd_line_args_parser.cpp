#include "../../headers/parser/cmd_line_args_parser.h"
#include <string>
#include <stdexcept>

CmdLineArgsParser::ErrorCode CmdLineArgsParser::Parse(int argc, char* argv[]) {
    if (argc < MIN_ARG_COUNT)
        return ErrorCode::NotEnoughArgs;
    in_file_name_ = argv[int(LineAttr::InFileName)];
    out_file_name_ = argv[int(LineAttr::OutFileName)];
    for (int i = 3; i < argc;) {
        if (argv[i][0] == '-') {
            FilterDescriptor filter_descriptor{};
            filter_descriptor.filter_name = argv[i];
            ++i;
            while (i < argc && argv[i][0] != '-') {
                try {
                    std::stod(argv[i]);
                } catch (const std::exception&) {
                    return ErrorCode::InvalidFilterParameter;
                }
                filter_descriptor.filter_params.push_back(argv[i]);
                ++i;
            }
            filter_descriptors_.push_back(filter_descriptor);
        }
    }
    return ErrorCode::Ok;
}
