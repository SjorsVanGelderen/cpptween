/*
  cpptween - A simple C++ tweening class
  Version 1
  Copyright 2015, Sjors van Gelderen
  MIT license
*/

/*
  TODO:
  Bounce equation
  Elastic equation
  Back equation
*/

#ifndef CPPTWEEN_H
#define CPPTWEEN_H

#include <iostream>
#include <math.h>

class CPPTween
{
public:
    CPPTween();
    ~CPPTween();
    void Initialize(float* _targetVariable, float _start, float _target, float _durationSec, std::string _easingMode, std::string _equation); //Concise initializer
    void SetTargetVariable(float* _targetVariable); //Set the target variable
    void SetStart(float _start); //Set the start value
    void SetTarget(float _target); //Set the target value
    void SetDuration(float _durationSec); //Set the interpolation duration
    void SetEasingMode(std::string _easingMode);
    void SetEquation(std::string _equation);
    void Reset(); //Reset the tween
    void Step(float _timeDelta); //Interpolate depending on time
    bool IsFinished(); //Returns whether the interpolation has completed or not
    
private:
    float EaseIn(float _t, float _b, float _c, float _d); //Ease in
    float EaseOut(float _t, float _b, float _c, float _d); //Ease out
    float EaseInOut(float _t, float _b, float _c, float _d); //Ease in and out
    
    bool finished; //Whether the interpolation has completed or not
    float* targetVariable; //The target variable
    float elapsedSec; //The amount of elapsed seconds
    float durationSec; //The duration of the interpolation
    float start; //The initial value
    float target; //The resulting value
    std::string equation; //The equation to be used
    std::string easingMode; //The easing mode to be used
};

#endif
