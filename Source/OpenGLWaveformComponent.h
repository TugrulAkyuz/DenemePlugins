/*
  ==============================================================================

    OpenGLWaveformComponent.h
    Created: 22 Mar 2023 10:11:17am
    Author:  z004m6rv

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class OpenGLWaveformComponent  : public juce::Component , public juce::OpenGLRenderer
{
public:
    OpenGLWaveformComponent(DenemePluginsAudioProcessor&);
    ~OpenGLWaveformComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    // Inherited via OpenGLRenderer
    virtual void newOpenGLContextCreated() override;

    virtual void renderOpenGL() override;

    virtual void openGLContextClosing() override;

    juce::OpenGLContext openGLContext;
    DenemePluginsAudioProcessor& audioProcessor;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OpenGLWaveformComponent)





};
