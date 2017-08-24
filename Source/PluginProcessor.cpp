/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Lowpass.h"


//==============================================================================
LowpassFilterAudioProcessor::LowpassFilterAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	lowL.setSampleRate(getSampleRate());
	lowR.setSampleRate(getSampleRate());
}

LowpassFilterAudioProcessor::~LowpassFilterAudioProcessor()
{
}

//==============================================================================
const String LowpassFilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool LowpassFilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool LowpassFilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double LowpassFilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int LowpassFilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int LowpassFilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void LowpassFilterAudioProcessor::setCurrentProgram (int index)
{
}

const String LowpassFilterAudioProcessor::getProgramName (int index)
{
    return {};
}

void LowpassFilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void LowpassFilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void LowpassFilterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool LowpassFilterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void LowpassFilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

	lowL.setSampleRate(getSampleRate());
	lowR.setSampleRate(getSampleRate());

	float *inputL = buffer.getWritePointer(0, 0);
	float *inputR = buffer.getWritePointer(1, 0);

	for (int i = 0; i < buffer.getNumSamples(); i++)
	{
		inputL[i] = lowL.process(inputL[i]);
		inputR[i] = lowR.process(inputR[i]);
	}
}

//==============================================================================
bool LowpassFilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* LowpassFilterAudioProcessor::createEditor()
{
    return new LowpassFilterAudioProcessorEditor (*this);
}

//==============================================================================
void LowpassFilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void LowpassFilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new LowpassFilterAudioProcessor();
}
