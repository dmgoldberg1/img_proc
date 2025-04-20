#ifndef TESTS_H
#define TESTS_H

#include "../../headers/tests/tests.h"
#include "../../headers/factory/filtercreators.h"

#include <cassert>
#include <iostream>

void TestCmdLineArgsParser1() {
    CmdLineArgsParser cmd_parser;
    assert(cmd_parser.GetInFileName() == nullptr);
}

void TestCmdLineArgsParser2(int argc, char* argv[]) {
    CmdLineArgsParser cmd_parser;

    CmdLineArgsParser::ErrorCode res = cmd_parser.Parse(argc, argv);
    if (res == CmdLineArgsParser::ErrorCode::NotEnoughArgs) {
        std::cerr << "You must provide at least 2 arguments: input and output file names\n";
        return;
    }
    if (res == CmdLineArgsParser::ErrorCode::InvalidFilterParameter) {
        std::cerr << "Filter parameters must be real numbers or integers\n";
        return;
    }
}

void TestOpenInputFile(int argc, char* argv[]) {
    CmdLineArgsParser cmd_parser;
    cmd_parser.Parse(argc, argv);
    Dib img = Dib::ReadFromFile(cmd_parser.GetInFileName());
    if (img.GetPixels().empty()) {
        std::cerr << "Can't read input file\n";
        return;
    }
}

void TestFilterMappingStuff() {
    FilterCreatorFactory factory;
    factory.RegisterFilterCreator("-crop", CreateCropFilterFromCmdArgs);
    factory.RegisterFilterCreator("-gs", CreateGsFilterFromCmdArgs);
    factory.RegisterFilterCreator("-neg", CreateNegativeFilterFromCmdArgs);
    factory.RegisterFilterCreator("-edge", CreateEdgeFilterFromCmdArgs);
    factory.RegisterFilterCreator("-sharp", CreateSharpFilterFromCmdArgs);
    FilterDescriptor fd_gs{"-gs", {}};
    FilterDescriptor fd_crop{"-crop", {"1", "1"}};
    FilterDescriptor fd_neg{"-neg", {}};
    FilterDescriptor fd_edge{"-edge", {"51"}};
    FilterDescriptor fd_sharp{"-sharp", {}};
    BaseFilter* gs_filter = factory.CreateFilter(&fd_gs);
    BaseFilter* crop_filter = factory.CreateFilter(&fd_crop);
    BaseFilter* neg_filter = factory.CreateFilter(&fd_neg);
    BaseFilter* edge_filter = factory.CreateFilter(&fd_edge);
    BaseFilter* sharp_filter = factory.CreateFilter(&fd_sharp);
    assert(gs_filter != nullptr);
    assert(crop_filter != nullptr);
    assert(neg_filter != nullptr);
    assert(edge_filter != nullptr);
    assert(sharp_filter != nullptr);
    delete gs_filter;
    delete crop_filter;
    delete neg_filter;
    delete edge_filter;
    delete sharp_filter;
}

#endif