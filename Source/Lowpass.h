/*
  ==============================================================================

    Lowpass.h
    Created: 22 Aug 2017 7:59:00pm
    Author:  K

  ==============================================================================
*/

#pragma once

class Lowpass {
public:
	Lowpass();
	~Lowpass();

	void setCutOff(float newCutoff);
	void setResonance(float newResonance);
	void setSampleRate(int newSampleRate);
	void setValues();

	float process(float newInput);

private:
	int sampleRate;
	float cutoff, resonance, c, a1, a2, a3, b1, b2;
	float inputHistory[2] = { 0 };
	float outputHistory[3] = { 0 };

};