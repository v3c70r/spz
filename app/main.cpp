#include "load-spz.h"

#include <iostream>

int main()
{
    spz::GaussianCloud cloud = spz::loadSpz("../samples/hornedlizard.spz");

    std::cout<<"Loaded "<<cloud.numPoints<<" points"<<std::endl;

    return 0;
};
