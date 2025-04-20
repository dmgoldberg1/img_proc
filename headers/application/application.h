#ifndef APPLICATION_H
#define APPLICATION_H

#include "../factory/filtercreators.h"

class Application {
public:
    void Init();
    void RunTests(int argc, char* argv[]);
    void Run(int argc, char* argv[]);

private:
    FilterCreatorFactory factory_;
};

#endif
