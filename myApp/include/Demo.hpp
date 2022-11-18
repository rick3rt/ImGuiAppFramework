#ifndef __DEMO_HPP__
#define __DEMO_HPP__

#include "App.hpp"
#include <cmath>
#include <vector>

// =============================================================================
// Demo class
// =============================================================================
class Demo : public App
{

  public:
    using App::App;

    ~Demo() {}

    // will run during initialization
    void Start() override;

    // display loop
    void Update() override;

    // render the plot window
    void RenderViewport();
};

#endif //!__DEMO_HPP__