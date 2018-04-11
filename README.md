PDScript
==============

PDScript is a lua-based scripting environment aiming at providing real time interaction with PureData. PDScript contains a Lua API that wraps LibPD's functionalities with the adition of patch creation and editing mechanisms. 

The current incarnation of pdscript is on a form of a real time command prompt in form of a VST, which can be integrated with compatible DAWs, allowing its users to user imperative instruction - commands - to create and controll PD patches. The first prototype can be used to produce complex patches, for live coding and so on. The first prototype version was developed over the barebone juce project distributed along with [Pd Pulp](http://pd-pulp.net/) that utilizes libpd to be able to use pure data as the sound engine for juce audio plugins.

Future PDScript versions will allow for the usage of the Lua API outside of the VST scope, and will also include an improved GUI for the PDScript command prompt. 

The information below came from the original Pd Pulp project, with some updates.

Although this howto focuses on OSX specific development, you should be able to create Windows and Linux plugins as well. 

###JUCE Installation:
Make sure your setup is ready to produce VST and/or AudioUnit plugins. If it's not, follow the instructions at the [JUCE plugin setup tutorial](https://docs.juce.com/master/tutorial_create_projucer_basic_plugin.html).

###LibPD Installation
[LibPD](https://github.com/libpd/libpd) is already included. However, if want to produce 64bit plugins, you need to compile it for the correct architecture and replace the libpd-osx.a file in the projects "libpd" folder.

###Setting up the Project

#####VST creation
Note, that you need to set the path of the vst sdk by clicking on the target Xcode (MacOSX) and enter the path. If the vst path field is missing, it means, that one or more audio plugin specific modules have not been added. Click on modules and add all audio modules.

#####Patchfile
After you successfully compiled it, you should get a Juce Assertion failure, because the patch file cant be loaded - here you need to enter the correct path to the patch file. Since this is a runtime variable, it has to be an absolute path.

#####Debugging
In Xcode edit you "Run Debug" scheme and enter your DAW you are testing with as Executable. You can also use Juce PluginHost app from the juce examples folder.   Remember that the DAW software might not find your plugin if it's compiled for an unsuitable architecture.
