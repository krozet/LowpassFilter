/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class LowpassFilterAudioProcessorEditor  : public AudioProcessorEditor, 
											private Slider::Listener
{
public:
    LowpassFilterAudioProcessorEditor (LowpassFilterAudioProcessor&);
    ~LowpassFilterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void cuttoffSliderVisibility();
	void resonanceSliderVisibility();

	void sliderValueChanged(Slider* slider);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LowpassFilterAudioProcessor& processor;

	Slider cutoffSlider;
	Slider resonanceSlider;
	Label cutoffLabel;
	Label resonanceLabel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LowpassFilterAudioProcessorEditor)
};
