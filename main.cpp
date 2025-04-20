#include "headers/application/application.h"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Application app;
        app.Init();
        app.RunTests(argc, argv);
        app.Run(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Something went wrong: " << std::endl;
        return 2;
    }

    return 0;
}
