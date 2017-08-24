/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
LowpassFilterAudioProcessorEditor::LowpassFilterAudioProcessorEditor (LowpassFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	cuttoffSliderVisibility();
	resonanceSliderVisibility();

    setSize (400, 300);
}

LowpassFilterAudioProcessorEditor::~LowpassFilterAudioProcessorEditor()
{
}

//==============================================================================
void LowpassFilterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void LowpassFilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	cutoffSlider.setBounds(120, 100, 200, 20);
	cutoffLabel.setBounds(25, 100, 100, 20);
	resonanceSlider.setBounds(120, 200, 200, 20);
	resonanceLabel.setBounds(25, 200, 100, 20);
}

void LowpassFilterAudioProcessorEditor::cuttoffSliderVisibility()
{
	addAndMakeVisible(cutoffSlider);
	cutoffSlider.addListener(this);
	cutoffSlider.setValue(4400.0);
	cutoffSlider.setRange(30.0, 22000.0, 0.10);
	cutoffSlider.setSkewFactorFromMidPoint(1000.0);

	addAndMakeVisible(cutoffLabel);
	cutoffLabel.setText("Cut Off", dontSendNotification);
}

void LowpassFilterAudioProcessorEditor::resonanceSliderVisibility()
{
	addAndMakeVisible(resonanceSlider);
	resonanceSlider.addListener(this);
	resonanceSlider.setValue(1.0);
	resonanceSlider.setRange(0.10, 18.0, 0.01);

	addAndMakeVisible(resonanceLabel);
	resonanceLabel.setText("Resonance", dontSendNotification);
}

void LowpassFilterAudioProcessorEditor::sliderValueChanged(Slider * slider)
{
	if (slider == &cutoffSlider)
	{
		processor.lowL.setCutOff((float)(slider->getValue()));
		processor.lowL.setValues();

		processor.lowR.setCutOff((float)(slider->getValue()));
		processor.lowR.setValues();
	}

	if (slider == &resonanceSlider)
	{
		processor.lowL.setResonance((float)(slider->getValue()));
		processor.lowL.setValues();

		processor.lowR.setResonance((float)(slider->getValue()));
		processor.lowR.setValues();
	}
}
