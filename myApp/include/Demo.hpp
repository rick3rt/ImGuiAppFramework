#ifndef DEMO_HPP_
#define DEMO_HPP_

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

#endif //! DEMO_HPP_