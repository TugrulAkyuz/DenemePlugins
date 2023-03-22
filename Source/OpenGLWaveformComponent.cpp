/*
  ==============================================================================

    OpenGLWaveformComponent.cpp
    Created: 22 Mar 2023 10:11:17am
    Author:  z004m6rv

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OpenGLWaveformComponent.h"


//==============================================================================
OpenGLWaveformComponent::OpenGLWaveformComponent(DenemePluginsAudioProcessor &p) : audioProcessor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setBufferedToImage(false);
    setOpaque(true);
    setPaintingIsUnclipped(true);
    setWantsKeyboardFocus(false);
    setRepaintsOnMouseActivity(false);
    setInterceptsMouseClicks(false, false);

    openGLContext.setRenderer(this);
    openGLContext.setContinuousRepainting(true);
    openGLContext.attachTo(*this);

}

OpenGLWaveformComponent::~OpenGLWaveformComponent()
{
}

void OpenGLWaveformComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("OpenGLWaveformComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void OpenGLWaveformComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void OpenGLWaveformComponent::newOpenGLContextCreated()
{

}

void OpenGLWaveformComponent::renderOpenGL()
{
    // Set up the OpenGL viewport
    juce::gl::glViewport(0, 0, getWidth(), getHeight());

    // Set up the projection matrix
    juce::gl::glMatrixMode(juce::gl::GL_PROJECTION);
    juce::gl::glLoadIdentity();
    juce::gl::glOrtho(0, getWidth(), getHeight(), 0, -1, 1);

    // Set up the modelview matrix
    juce::gl::glMatrixMode(juce::gl::GL_MODELVIEW);
    juce::gl::glLoadIdentity();

    // Clear the screen
    juce::gl::glClear(juce::gl::GL_COLOR_BUFFER_BIT | juce::gl::GL_DEPTH_BUFFER_BIT);

    // Draw the waveform
    juce::gl::glLineWidth(1.0f);
    juce::gl::glColor3f(1.0f, 1.0f, 1.0f);
    juce::gl::glBegin(juce::gl::GL_LINE_STRIP);
    for (int i = 0; i < audioProcessor.bufferForVisual.getNumSamples(); i++) {
        float x = (float)i / audioProcessor.bufferForVisual.getNumSamples() * getWidth();
        float y = getHeight() / 2 + audioProcessor.bufferForVisual.getSample(0, i) * getHeight() / 2;
        juce::gl::glVertex2f(x, y);
    }
    juce::gl::glEnd();
}

void OpenGLWaveformComponent::openGLContextClosing()
{
}


