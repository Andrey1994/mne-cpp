---
title: MNE-CPP with BrainFlow
parent: Develop
nav_order: 4
---
# MNE-CPP with BrainFlow

This plugin adds BrainFlow data acquisition SDK to MNE-SCAN app.

**Links:**

* [BrainFlow Docs](https://brainflow.readthedocs.io/en/stable/)
* [BrainFlow Repo](https://github.com/Andrey1994/brainflow)

## Compilation of BrainFlow submodule

* Make sure that you have brainflow git submodule
* Build it as a regular Cmake project but for MSVC you need to ensure that you use exactly the same Cmake Generator as for MNE-CPP, also you need to specify MSVC_RUNTIME dynamic(default is static) and use the same build type(Debug/Release). Also specify -DCMAKE_INSTALL_PREFIX=..\installed

To ensure that submodule is downloaded you may need to run:
```
git clone --recursive https://github.com/mne-tools/mne-cpp
# if you cloned the repo without recursive flag you will need to run
git submodule update --init
```
Example of compilation:
```
cd applications\mne_scan\plugins\brainflowboard\brainflow\
mkdir build
cd build
cmake -G "Visual Studio 14 2015 Win64" -DMSVC_RUNTIME=dynamic -DCMAKE_SYSTEM_VERSION=8.1 -DCMAKE_INSTALL_PREFIX=..\\installed ..
cmake --build . --target install --config Release
cd ..
```

## BrainFlowBoard plugin setup

* After steps above make sure that you have brainflowboard uncommented in plugins.pro
* Build MNE-SCAN application
* BrainFlow has several dynamic libraries and JSON file which must be in your search path before you run BrainFlow based app, so you need to copypaste BoardController.dll DataHandler.dll and brainflow_boards.json to your executable folder from brainflow\installed\lib

## BrainFlowBoard plugin UI

* You need to provide all inputs required for selected board and click 'Submit Params and Prepare Session' button. For information about inputs in BraiFlowBoard plugin widget use this [table](https://brainflow.readthedocs.io/en/stable/SupportedBoards.html)
* After that you can start data streaming using play button
* If you need to change board or other parameters click 'Release Session' button and create a new one.
* [Optional] if you need to send config to a board, open setting widget and enter a config.
