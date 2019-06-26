@ECHO Preparing build directory ...
IF EXIST build (RD /Q /S build)
MD build
CD build
cmake -G "Visual Studio 15 2017 Win64" ..
CD ..

