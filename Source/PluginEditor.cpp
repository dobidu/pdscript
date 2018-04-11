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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"

#define PATCH_PATH "/Users/bidu/workspace/pdpulp_run/"

//[MiscUserDefs] You can add your own user definitions and misc code here...

void pdprint(const char *s) {
    fprintf(stderr,"%s", s);
}

void pdnoteon(int ch, int pitch, int vel) {
    fprintf(stderr,"noteon: %d %d %d\n", ch, pitch, vel);
}
////
//// lua patch editor

int new_patch(lua_State* L) {
    char patch_full_path[100]; //!!!
    const char* patch_file_name;
    FILE* fp;

    strcpy(patch_full_path, PATCH_PATH);

    int n = lua_gettop(L);

    if (n == 1) {
        if (lua_type(L,1) == LUA_TSTRING) {
            patch_file_name = lua_tostring(L,1);
        }
    }

    char str1[50]; //!!!
    strcpy(str1,patch_file_name);

    strcat(patch_full_path,str1);

    fprintf(stderr,"Creating %s \n",patch_full_path);

    fp = fopen(patch_full_path, "w+");

    if (!fp) {
        char* str_msg;

        str_msg = (char*)malloc(30*sizeof(char));

        sprintf(str_msg,"ERROR creating %s \n",patch_full_path);
        fprintf(stderr,"ERROR creating %s \n",patch_full_path);

        lua_pushstring(L,str_msg);

        return 1;

    } else {

        fprintf(fp,"#N canvas 10 10 640 480 10;\n");

        fclose(fp);

        char* str_msg;

        str_msg = (char*)malloc(30*sizeof(char));

        sprintf(str_msg,"PATCH %s created\n",patch_full_path);

        lua_pushstring(L,str_msg);

        return 1;

    }

}

int add_patch_array(lua_State* L) {

}

int add_patch_connect(lua_State* L) {
    char patch_full_path[100]; //!!!
    const char* patch_file_name;

    char obj_str[200];

    FILE* fp;
    int source_idx=0, outlet_idx=0;
    int target_idx=0, inlet_idx=0;


    strcpy(patch_full_path, PATCH_PATH);

    int n = lua_gettop(L);

    if (n == 5) {
        if (lua_type(L,1) == LUA_TSTRING) {
            patch_file_name = lua_tostring(L,1);
        }

        if (lua_type(L,2) == LUA_TNUMBER) {
            source_idx = lua_tonumber(L, 2);
        }

        if (lua_type(L,3) == LUA_TNUMBER) {
            outlet_idx = lua_tonumber(L, 3);
        }

        if (lua_type(L,4) == LUA_TNUMBER) {
            target_idx = lua_tonumber(L, 4);
        }

        if (lua_type(L,5) == LUA_TNUMBER) {
            inlet_idx = lua_tonumber(L, 5);
        }

        char str1[50]; //!!!
        strcpy(str1,patch_file_name);

        strcat(patch_full_path,str1);

        sprintf(obj_str,"#X connect %d %d %d %d;\n",source_idx,outlet_idx,target_idx,inlet_idx);
        fprintf(stderr,"Adding connect to %s \n",patch_full_path);

        fp = fopen(patch_full_path, "a");

        if (!fp) {
            char* str_msg;

            str_msg = (char*)malloc(30*sizeof(char));

            sprintf(str_msg,"ERROR adding connect to %s \n",patch_full_path);
            fprintf(stderr,"ERROR adding connect to %s \n",patch_full_path);

            lua_pushstring(L,str_msg);

            return 1;

        } else {

            fprintf(fp,obj_str);

            fclose(fp);

            char* str_msg;

            str_msg = (char*)malloc(30*sizeof(char));

            sprintf(str_msg,"Added connection to %s \n",patch_full_path);

            lua_pushstring(L,str_msg);

            return 1;
        }
    } else {
        return 0;
    }
}

int add_patch_msg(lua_State* L) {

}

int add_patch_obj(lua_State* L) {
    char patch_full_path[100]; //!!!
    const char* patch_file_name;
    const char* obj_name;
    const char* obj_value;

    char obj_str[200];

    FILE* fp;
    int x_pos=0, y_pos=0;


    strcpy(patch_full_path, PATCH_PATH);

    int n = lua_gettop(L);

    if (n >= 4) {
        if (lua_type(L,1) == LUA_TSTRING) {
            patch_file_name = lua_tostring(L,1);
        }

        if (lua_type(L,2) == LUA_TNUMBER) {
            x_pos = lua_tonumber(L, 2);
        }

        if (lua_type(L,3) == LUA_TNUMBER) {
            y_pos = lua_tonumber(L, 3);
        }

        if (lua_type(L,4) == LUA_TSTRING) {
            obj_name = lua_tostring(L, 4);
        }

        if (n == 5) {
            if (lua_type(L,5) == LUA_TSTRING) {
                obj_value = lua_tostring(L, 5);
            }
        }
        char str1[50]; //!!!
        strcpy(str1,patch_file_name);

        strcat(patch_full_path,str1);

        if (n == 5) {
            sprintf(obj_str,"#X obj %d %d %s %s;\n",x_pos,y_pos,obj_name,obj_value);
        } else {
            sprintf(obj_str,"#X obj %d %d %s;\n",x_pos,y_pos,obj_name);
        }

        fprintf(stderr,"Adding obj to %s \n",patch_full_path);

        fp = fopen(patch_full_path, "a");

        if (!fp) {
            char* str_msg;

            str_msg = (char*)malloc(30*sizeof(char));

            sprintf(str_msg,"ERROR adding obj to %s \n",patch_full_path);
            fprintf(stderr,"ERROR adding obj to %s \n",patch_full_path);

            lua_pushstring(L,str_msg);

            return 1;

        } else {

            fprintf(fp,obj_str);

            fclose(fp);

            char* str_msg;

            str_msg = (char*)malloc(30*sizeof(char));

            sprintf(str_msg,"Added obj to %s \n",patch_full_path);

            lua_pushstring(L,str_msg);

            return 1;
        }
    } else {
        return 0;
    }
}

int add_patch_obj_bang() {

}

int add_patch_subpatch() {

}


////
int testdebug(lua_State* L) {

    fprintf(stderr,"hello from testdebug()\n");

    //pd_setinstance(PDINSTANCEOMG);

    char* str_msg;

    fprintf(stderr,"testdebug(lua_State* L)\n");

    //t_pdinstance* pd_instance = pdinstance_new(); //use same from "outside"

    double sampleRate = 44100;
    char* curPatchPath = "/Users/bidu/workspace/pdpulp_run/sawsynth.pd";       //check all!!!!!!!
    int  maxMsgLen = 1000;
    bool queued = false; //false!!!

    bool ranAlready = false;
    bool bLibPdInited = false;

    if (ranAlready) {
        libpd_start_message(1);
        libpd_add_float((float) false);
        libpd_finish_message("pd", "dsp");
        //
        libpd_start_message(maxMsgLen);
        libpd_add_float(1.0f);
        libpd_finish_message(curPatchPath, "menuclose");

    }

    ////CLEAR

    libpd_start_message(1);
    libpd_add_float((float) 1.0f);
    //libpd_finish_message("pd", "dsp"); pdthis bug

    if(queued) {
        libpd_set_queued_printhook(NULL);
        libpd_set_concatenated_printhook(NULL);

        libpd_set_queued_banghook(NULL);
        libpd_set_queued_floathook(NULL);
        libpd_set_queued_symbolhook(NULL);
        libpd_set_queued_listhook(NULL);
        libpd_set_queued_messagehook(NULL);

        libpd_set_queued_noteonhook(NULL);
        libpd_set_queued_controlchangehook(NULL);
        libpd_set_queued_programchangehook(NULL);
        libpd_set_queued_pitchbendhook(NULL);
        libpd_set_queued_aftertouchhook(NULL);
        libpd_set_queued_polyaftertouchhook(NULL);
        libpd_set_queued_midibytehook(NULL);

        libpd_queued_release();
    }
    else {
        libpd_set_printhook(NULL);
        libpd_set_concatenated_printhook(NULL);

        libpd_set_banghook(NULL);
        libpd_set_floathook(NULL);
        libpd_set_symbolhook(NULL);
        libpd_set_listhook(NULL);
        libpd_set_messagehook(NULL);

        libpd_set_noteonhook(NULL);
        libpd_set_controlchangehook(NULL);
        libpd_set_programchangehook(NULL);
        libpd_set_pitchbendhook(NULL);
        libpd_set_aftertouchhook(NULL);
        libpd_set_polyaftertouchhook(NULL);
        libpd_set_midibytehook(NULL);
    }


    //CLEAR

    // attach callbacks
    if(queued) {
        libpd_set_queued_printhook(libpd_print_concatenator);
        if(!bLibPdInited) {
            //libpd_queued_init();
            bLibPdInited = true;
        }
    }
    else {
        libpd_set_printhook(libpd_print_concatenator);
        // init libpd, should only be called once!
        if(!bLibPdInited) {
            //libpd_init();
            bLibPdInited = true;
        }
    }

    //pdinstance_new();

    pd_setinstance(PDINSTANCEOMG);


    void* handle = libpd_openfile("sawsynth.pd", "/Users/bidu/workspace/pdpulp_run/");

    int dollarZero = libpd_getdollarzero(handle);

/////
    //VER ESQUEMA DE LEITURA DO RETORNO NO LUA QUE ESTA INDO PRO OUTPUT DO SHELL

    str_msg = (char*)malloc(30*sizeof(char));
    sprintf(str_msg,"hello from testdebug()!\n");

    lua_pushstring(L,str_msg);

    return 1;

}

int charCounter(char* fileName) {
    FILE *f = fopen(fileName, "r");
    unsigned int number_of_chars = 0;
    int ch;
    while (EOF != (ch=fgetc(f)))
            ++number_of_chars;
    return number_of_chars;
}



//[/MiscUserDefs]

//==============================================================================
PureDataAudioProcessorEditor::PureDataAudioProcessorEditor (PureDataAudioProcessor& p)
    : AudioProcessorEditor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    addAndMakeVisible (textEditor2 = new TextEditor ("new text editor"));
    textEditor2->setMultiLine (false);
    textEditor2->setReturnKeyStartsNewLine (false);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (false);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setText (String());

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("Send"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colours::white);
    textButton->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->setButtonText (TRANS("Clear"));
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colours::white);
    textButton2->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("PdScript Terminal\n")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

//////


    lua_out_stream = fopen(LUA_OUT_FILE, "w+");
    lua_err_stream = fopen(LUA_ERR_FILE, "w+");

    lua_out_size = 0;
    lua_err_size = 0;

    stdout = lua_out_stream;
    stderr = lua_err_stream;

    lua = (lua_State *)luaL_newstate();

    luaL_openlibs(lua);

    //LuaPDWrapper::setPDInstance(pd_this); //WILL HAVE TO CHANGE ON MULTI INSTANCE :)

    //LuaPDWrapper::pd_instance = pd_this;

    pd_instance = processor->getPDInstance();

    PDINSTANCEOMG = pd_instance;
    //

    //lua_register(lua, "scratch", LuaPDWrapper::scratch);
    lua_register(lua, "xxxx", testdebug);
    lua_register(lua, "pd_patch",new_patch);
    lua_register(lua, "put_obj",add_patch_obj);
    lua_register(lua, "put_connect",add_patch_connect);

    /*

    // register our function
    //  lua_register(L, "average", average);
     COLOCAR AQUI FUNCOES DE MANIPULACAO DO PD QUE SERAO INVOCADAS PELO LUA
     :)
     pd create instance
     patch create **** varias outras funcoes

     pd load patch
     pd send stuff

     */

    /* run the script */
    //luaL_dofile(L, "avg.lua");

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PureDataAudioProcessorEditor::~PureDataAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    textEditor = nullptr;
    textEditor2 = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;
    label = nullptr;
    processor = nullptr;
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PureDataAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PureDataAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    textEditor->setBounds (8, 24, 296, 256);
    textEditor2->setBounds (16, 288, 280, 40);
    textButton->setBounds (184, 336, 104, 24);
    textButton2->setBounds (24, 335, 104, 24);
    label->setBounds (96, 0, 120, 24);
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void PureDataAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        juce::String lineCmd = textEditor2->getTextValue().toString();
        juce::String terminalBox = "\n > " + lineCmd;

        textEditor->insertTextAtCaret(juce::String("\n"));
        textEditor->insertTextAtCaret(juce::String(terminalBox));

        terminalBox = "";
        textEditor2->clear();

        if (lineCmd.startsWith("pd_patch_run")) {
            /* aqui !!! */
            //terminalBox = terminalBox + "\n" + "[DEBUG COMMAND] BEF\n";
            //debugTest();
            hard_wire(std::string(lineCmd.getCharPointer()));
            textEditor->insertTextAtCaret(juce::String("\n"));
            textEditor->insertTextAtCaret(juce::String("[pd_patch_run]\n"));
            //////
            int new_out_size = charCounter(LUA_OUT_FILE);
            //printf("(new_out_size = %d)",new_out_size);
            if (new_out_size > lua_out_size) {
                fseek(lua_out_stream,lua_out_size,SEEK_SET);
                char ch;
                juce::String lua_out_str;
                while (EOF != (ch=fgetc(lua_out_stream))) {
                    lua_out_str += ch;
                }
                lua_out_size = new_out_size;
                textEditor->insertTextAtCaret(juce::String("\n"));
                textEditor->insertTextAtCaret(juce::String(lua_out_str));
            }
            int new_err_size = charCounter(LUA_ERR_FILE);
            //printf("(new_err_size = %d)",new_err_size);
            if (new_err_size > lua_err_size) {
                fseek(lua_err_stream,lua_err_size,SEEK_SET);
                char ch;
                juce::String lua_err_str;
                while (EOF != (ch=fgetc(lua_err_stream))) {
                    lua_err_str += ch;
                }

                lua_err_size = new_err_size;
                textEditor->insertTextAtCaret(juce::String("\n"));
                textEditor->insertTextAtCaret(juce::String(lua_err_str));
            }


        } else {
            int lua_res = luaL_dostring(lua, lineCmd.toRawUTF8());
            if (!lua_res) {
                if (lineCmd.startsWith("return")) {
                    //printf("return detected ;)");
                    const char * strReturnLineCmd = lua_tostring(lua, -1);
                    //terminalBox = terminalBox + "\n" + strReturnLineCmd;
                    //textEditor->setText(terminalBox);
                    textEditor->insertTextAtCaret(juce::String("\n"));
                    textEditor->insertTextAtCaret(juce::String(strReturnLineCmd));

                } else {
                    int new_out_size = charCounter(LUA_OUT_FILE);
                    //printf("(new_out_size = %d)",new_out_size);
                    if (new_out_size > lua_out_size) {
                        fseek(lua_out_stream,lua_out_size,SEEK_SET);
                        char ch;
                        juce::String lua_out_str;
                        while (EOF != (ch=fgetc(lua_out_stream))) {
                                lua_out_str += ch;
                            }
                        //terminalBox = terminalBox + "\n" + lua_out_str;
                        //textEditor->setText(terminalBox);
                        textEditor->insertTextAtCaret(juce::String("\n"));
                        textEditor->insertTextAtCaret(juce::String(lua_out_str));
                        lua_out_size = new_out_size;
                        }
                    int new_err_size = charCounter(LUA_ERR_FILE);
                    //printf("(new_err_size = %d)",new_err_size);
                    if (new_err_size > lua_err_size) {
                        fseek(lua_err_stream,lua_err_size,SEEK_SET);
                        char ch;
                        juce::String lua_err_str;
                        while (EOF != (ch=fgetc(lua_err_stream))) {
                            lua_err_str += ch;
                        }
                        textEditor->insertTextAtCaret(juce::String("\n"));
                        textEditor->insertTextAtCaret(juce::String(lua_err_str));
                        //terminalBox = terminalBox + "\n" + lua_err_str;
                        //textEditor->setText(terminalBox);
                        lua_err_size = new_err_size;
                    }
                    /*
                    if (terminalBox.length() > 0) {
                        textEditor->setText(terminalBox);
                    }
                     */
                }

            }
            else {

                textEditor->insertTextAtCaret(juce::String(textEditor->getTextValue().toString()));
                textEditor->insertTextAtCaret(juce::String("\n >"));
                textEditor->insertTextAtCaret(juce::String(lineCmd));
                //juce::String terminalBox = textEditor->getTextValue().toString() + "\n > " + lineCmd;
                //terminalBox += "\nnil";
                //textEditor->setText(terminalBox);
                textEditor2->clear();

            }

        }


        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        textEditor->clear();
        //[/UserButtonCode_textButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PureDataAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="PureDataAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
