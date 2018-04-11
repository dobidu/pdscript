/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "z_libpd.h"
#include "m_imp.h"
#include "z_queued.h"
#include "z_print_util.h"

static t_pdinstance* PDINSTANCEOMG;

#define LUA_OUT_FILE "/tmp/PDSCRIPT_LUA_OUT"
#define LUA_ERR_FILE "/tmp/PDSCRIPT_LUA_ERR"

#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PureDataAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    //==============================================================================
    PureDataAudioProcessorEditor (PureDataAudioProcessor& p);
    ~PureDataAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void buttonClicked (Button* buttonThatWasClicked) override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    // criar classe com PureDataAudioProcessor estatico e varios metodos estaticos que serao invocados
    // pelo lua
    // para depois registralos


    lua_State *lua;

    FILE *lua_out_stream;
    FILE *lua_err_stream;

    int lua_out_size;
    int lua_err_size;

    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<TextEditor> textEditor2;
    ScopedPointer<TextButton> textButton;
    ScopedPointer<TextButton> textButton2;
    ScopedPointer<Label> label;

    PureDataAudioProcessor* processor;
    t_pdinstance* pd_instance;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PureDataAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...


//[/EndFile]
