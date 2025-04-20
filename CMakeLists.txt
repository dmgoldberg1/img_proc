cmake_minimum_required(VERSION 3.0)

project(PrjMisc CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 20)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0") #" -Wall")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(image_processor
        main.cpp
        headers/filters/crop_filter.h src/filters/crop_filter.cpp
        headers/filter_makers/crop_filter_cmd_args_maker.h src/filter_makers/crop_filter_cmd_args_maker.cpp
        headers/filters/gs_filter.h src/filters/gs_filter.cpp
        headers/filter_makers/gs_filter_cmd_args_maker.h src/filter_makers/gs_filter_cmd_args_maker.cpp
        headers/filters/negative_filter.h src/filters/negative_filter.cpp
        headers/filter_makers/negative_filter_cmd_args_maker.h src/filter_makers/negative_filter_cmd_args_maker.cpp
        headers/filters/sharp_filter.h src/filters/sharp_filter.cpp
        headers/filter_makers/sharp_filter_cmd_args_maker.h src/filter_makers/sharp_filter_cmd_args_maker.cpp
        headers/filters/edge_filter.h src/filters/edge_filter.cpp
        headers/filter_makers/edge_filter_cmd_args_maker.h src/filter_makers/edge_filter_cmd_args_maker.cpp
        headers/filters/base_filter.h src/filters/base_filter.cpp
        headers/parser/cmd_line_args_parser.h src/parser/cmd_line_args_parser.cpp
        headers/image/dib.h src/image/dib.cpp
        headers/image/bmp_wrap.h src/image/bmp_wrap.cpp
        headers/factory/filterpipeline.h src/factory/filterpipeline.cpp
        headers/factory/filtercreators.h src/factory/filtercreators.cpp
        headers/tests/tests.h src/tests/tests.cpp
        headers/application/application.h src/application/application.cpp
)
