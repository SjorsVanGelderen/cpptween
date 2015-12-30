/*
  cpptween example
  Version 1
  Copyright 2015, Sjors van Gelderen
  MIT license
*/

#include <iostream>
#include "cpptween.h"

int main()
{
    std::cout << "Starting interpolation.." << std::endl;
    
    float valueToBeInterpolated = 0;
    
    CPPTween tween;
    tween.Initialize(&valueToBeInterpolated, 0, 1, 2, "inout", "linear");

    while(!tween.IsFinished())
    {
	tween.Step(0.01f); //Fictional time delta
	std::cout << valueToBeInterpolated << std::endl;
    }

    std::cout << "Interpolation complete! Exiting.." << std::endl;
    return 0;
}
