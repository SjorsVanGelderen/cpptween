#include "cpptween.h"

CPPTween::CPPTween()
{
    //Default variable initialization
    finished = false;
    targetVariable = nullptr;
    elapsedSec = 0;
    durationSec = 1.0f;
    start = 0;
    target = 1.0f;
    equation = "linear";
    easingMode = "inout";
}

CPPTween::~CPPTween()
{
    targetVariable = nullptr;
}

void CPPTween::Initialize(float* _targetVariable, float _start, float _target, float _durationSec, std::string _easingMode, std::string _equation)
{
    SetTargetVariable(_targetVariable);
    SetStart(_start);
    SetTarget(_target);
    SetDuration(_durationSec);
    SetEasingMode(_easingMode);
    SetEquation(_equation);
}

void CPPTween::SetTargetVariable(float* _targetVariable)
{
    targetVariable = _targetVariable;
}

void CPPTween::SetStart(float _start)
{
    start = _start;
}

void CPPTween::SetTarget(float _target)
{
    target = _target;
}

void CPPTween::SetDuration(float _durationSec)
{
    durationSec = _durationSec;
}

void CPPTween::SetEasingMode(std::string _easingMode)
{
    easingMode = _easingMode;
}

void CPPTween::SetEquation(std::string _equation)
{
    equation = _equation;
}

void CPPTween::Reset()
{
    elapsedSec = 0;
    finished = false;
}

void CPPTween::Step(float _timeDelta)
{
    if(!finished)
    {
	elapsedSec += _timeDelta;
	if(elapsedSec >= durationSec)
	{
	    //Don't overstep
	    elapsedSec = durationSec;

	    //Interpolation is complete after this step
	    finished = true;
        }
    
	if(easingMode == "in")
	{
	    *targetVariable = EaseIn(elapsedSec, start, target - start, durationSec);
	}
	else if(easingMode == "out")
	{
	    *targetVariable = EaseOut(elapsedSec, start, target - start, durationSec);
	}
	else if(easingMode == "inout")
	{
	    *targetVariable = EaseInOut(elapsedSec, start, target - start, durationSec);
	}
	else
	{
	    std::cout << "Specified easing mode for this tween doesn't exist!" << std::endl;
	    finished = true;
	}
    }
}

bool CPPTween::IsFinished()
{
    return finished;
}

float CPPTween::EaseIn(float _t, float _b, float _c, float _d)
{
    if(equation == "linear")
    {
	return _c * _t / _d + _b;
    }
    else if(equation == "quadratic")
    {
	_t /= _d;
	return _c * _t * _t + _b;
    }
    else if(equation == "cubic")
    {
	_t /= _d;
	return _c * _t * _t * _t + _b;
    }
    else if(equation == "quartic")
    {
	_t /= _d;
	return _c * _t * _t * _t * _t + _b;
    }
    else if(equation == "quintic")
    {
	_t /= _d;
	return _c * _t * _t * _t * _t + _b;
    }
    else if(equation == "sinusoidal")
    {
	return -_c * cos(_t / _d * (M_PI / 2.0f)) + _c + _b;
    }
    else if(equation == "exponential")
    {
	return _c * pow(2.0f, 10.0f * (_t / _d - 1.0f)) + _b;
    }
    else if(equation == "circular")
    {
	_t /= _d;
	_t--;
	return _c * sqrtf(1.0f -_t * _t) + _b;
    }
    else if(equation == "bounce")
    {
	//TODO
    }
    else if(equation == "elastic")
    {
	//TODO
    }
    else if(equation == "back")
    {
	//TODO
    }

    std::cout << "Specified equation for this tween doesn't exist!" << std::endl;
    return 0;
}

float CPPTween::EaseOut(float _t, float _b, float _c, float _d)
{
    if(equation == "linear")
    {
	return EaseIn(_t, _b, _c, _d);
    }
    else if(equation == "quadratic")
    {
	_t /= _d;
	return -_c * _t * (_t - 2.0f) + _b;
    }
    else if(equation == "cubic")
    {
	_t /= _d;
	_t--;
	return _c * (_t * _t * _t + 1.0f) + _b;
    }
    else if(equation == "quartic")
    {
	_t /= _d;
	_t--;
	return -_c * (_t * _t * _t * _t - 1.0f) + _b;
    }
    else if(equation == "quintic")
    {
	_t /= _d;
	_t--;
	return _c * (_t * _t * _t * _t * _t + 1.0f) + _b;
    }
    else if(equation == "sinusoidal")
    {
	return _c * sin(_t / _d * (M_PI / 2.0f)) + _b;
    }
    else if(equation == "exponential")
    {
	return _c * (-pow(2.0f, -10.0f * _t / _d) + 1.0f) + _b;
    }
    else if(equation == "circular")
    {
	_t /= _d;
	_t--;
	return _c * sqrtf(1.0f - _t * _t) + _b;
    }
    else if(equation == "bounce")
    {
	//TODO
    }
    else if(equation == "elastic")
    {
	//TODO
    }
    else if(equation == "back")
    {
	//TODO
    }

    std::cout << "Specified equation for this tween doesn't exist!" << std::endl;
    return 0;
}

float CPPTween::EaseInOut(float _t, float _b, float _c, float _d)
{
    if(equation == "linear")
    {
	return EaseIn(_t, _b, _c, _d);
    }
    else if(equation == "quadratic")
    {
	_t /= _d / 2.0f;
	if(_t < 1.0f)
	{
	    return _c / 2.0f * _t * _t + _b;
	}

	_t--;
	return -_c / 2.0f * (_t * (_t - 2.0f) - 1.0f) + _b;
    }
    else if(equation == "cubic")
    {
	_t /= _d / 2.0f;
	if(_t < 1.0f)
	{
	    return _c / 2.0f * _t * _t * _t + _b;
	}

	_t -= 2.0f;
	return _c / 2.0f * (_t * _t * _t + 2.0f) + _b;
    }
    else if(equation == "quartic")
    {
	_t /= _d / 2.0f;

	if(_t < 1.0f)
	{
	    return _c / 2.0f * _t * _t * _t * _t + _b;
	}

	_t -= 2.0f;
	return -_c / 2.0f * (_t * _t * _t * _t - 2.0f) + _b;
    }
    else if(equation == "quintic")
    {
	_t /= _d / 2.0f;
	if(_t < 1.0f)
	{
	    return _c / 2.0f * _t * _t * _t * _t * _t + _b;
	}

	_t -= 2.0f;
	return _c / 2.0f * (_t * _t * _t * _t * _t + 2.0f) + _b;
    }
    else if(equation == "sinusoidal")
    {
	return -_c / 2.0f * (cos(M_PI * _t / _d) - 1.0f) + _b;
    }
    else if(equation == "exponential")
    {
	_t /= _d / 2.0f;
	if(_t < 1.0f)
	{
	    return _c / 2.0f * pow(2.0f, 10.0f * (_t - 1.0f)) + _b;
	}

	_t--;
	return _c / 2.0f * (-pow(2.0f, -10.0f * _t) + 2.0f) + _b;
    }
    else if(equation == "circular")
    {
	_t /= _d / 2.0f;
	if(_t < 1.0f)
	{
	    return _c / 2.0f * pow(2.0f, 10.0f * (_t - 1.0f)) + _b;
	}
	
	_t--;
	return _c / 2.0f * (-pow(2.0f, -10.0f * _t) + 2.0f) + _b;
    }
    else if(equation == "bounce")
    {
	//TODO
    }
    else if(equation == "elastic")
    {
	//TODO
    }
    else if(equation == "back")
    {
	//TODO
    }

    std::cout << "Specified equation for this tween doesn't exist!" << std::endl;
    return 0;
}
