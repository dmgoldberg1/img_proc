#include "../../headers/application/application.h"

#include "../../headers/parser/cmd_line_args_parser.h"
#include "../../headers/tests/tests.h"

void Application::Init() {
    factory_.RegisterFilterCreator("-crop", CreateCropFilterFromCmdArgs);
    factory_.RegisterFilterCreator("-gs", CreateGsFilterFromCmdArgs);
    factory_.RegisterFilterCreator("-neg", CreateNegativeFilterFromCmdArgs);
    factory_.RegisterFilterCreator("-sharp", CreateSharpFilterFromCmdArgs);
    factory_.RegisterFilterCreator("-edge", CreateEdgeFilterFromCmdArgs);
}

void Application::Run(int argc, char* argv[]) {
    CmdLineArgsParser parser;
    parser.Parse(argc, argv);
    Dib img = Dib::ReadFromFile(parser.GetInFileName());
    FilterPipeline pipeline{factory_.CreatePipeline(parser.GetFilterDescriptors())};
    pipeline.Apply(&img);
    Dib::SaveToFile(parser.GetOutFileName(), &img);
}

void Application::RunTests(int argc, char* argv[]) {
    TestCmdLineArgsParser1();
    TestCmdLineArgsParser2(argc, argv);
    TestFilterMappingStuff();
    TestOpenInputFile(argc, argv);
}