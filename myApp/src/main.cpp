#include "Demo.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Demo app("Demo", 1280, 760, argc, argv);
    app.Run();

    // MatlabInterface mi;
    // MatlabImage image("test", "test", ImPlotColormap_Cool, &mi);
    // image.printInfo();

    // std::cout << "hi" << std::endl;

    return 0;
}
