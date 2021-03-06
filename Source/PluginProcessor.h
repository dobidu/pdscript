/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "PdBase.hpp"
#include "Receiver.h"
#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class FloatParameter;
class PureDataAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PureDataAudioProcessor();
    ~PureDataAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //=======
    void setParameterName(int index, String name);
    void reloadPatch(double sampleRate);
    void setPatchFile(juce::File file);
    void setParameterDefaults();
    File getPatchFile();
    t_pdinstance* getPDInstance();
    
    bool patchLoadError = false;

private:
    
    Receiver receiver;
    Array<FloatParameter*> parameterList;
    double cachedSampleRate;

    AudioPlayHead::CurrentPositionInfo positionInfo;
    File patchfile;
    ScopedPointer<pd::PdBase> pd;
    int pos;
    pd::Patch patch;
    HeapBlock<float> pdInBuffer, pdOutBuffer;
    t_pdinstance* pd_instance;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PureDataAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
