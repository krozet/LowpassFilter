/*
  ==============================================================================

    Lowpass.cpp
    Created: 22 Aug 2017 7:59:00pm
    Author:  K

  ==============================================================================
*/

#include "Lowpass.h"
#include <cmath>
#define _USE_MATH_DEFINES
#define M_PI1 3.141592653589793238462643383279502884F

Lowpass::Lowpass() : cutoff(4400), resonance(1), sampleRate(0)
{
}

Lowpass::~Lowpass()
{
}

void Lowpass::setCutOff(float newCutoff)
{
	cutoff = newCutoff;
}

void Lowpass::setResonance(float newResonance)
{
	resonance = newResonance;
}

void Lowpass::setSampleRate(int newSampleRate)
{
	sampleRate = newSampleRate;
}

void Lowpass::setValues()
{
	c = 1.0 / tan(M_PI1 * cutoff / sampleRate);
	a1 = 1.f / (1.f + resonance * c + c * c);
	a2 = 2.f * a1;
	a3 = a1;
	b1 = 2.f * (1.f - c * c) * a1;
	b2 = (1.f - resonance * c + c * c);
}

float Lowpass::process(float newInput)
{
	float newOutput = a1 * newInput + a2 * inputHistory[0] + a3 * inputHistory[1] - b1 *  outputHistory[0] - b2 * outputHistory[1];

	//move the newInput and newOutput into the history arrays
	inputHistory[1] = inputHistory[0];
	inputHistory[0] = newInput;

	outputHistory[2] = outputHistory[1];
	outputHistory[1] = outputHistory[0];
	outputHistory[0] = newOutput;

	return outputHistory[0];
}
