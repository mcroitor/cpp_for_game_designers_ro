@echo off
rem path to Visual Studio
set VS_VERSION=14.37.32822
set SDK_VERSION=10.0.22000.0
set VSPATH=c:\Program Files\Microsoft Visual Studio\2022\Community
set MSVC=%VSPATH%\VC\Tools\MSVC\%VS_VERSION%
set SDKPATH=c:\Program Files (x86)\Windows Kits\10
set PATH=%MSVC%\bin\Hostx64\x64


rem Microsoft C++ compiler
set COMPILER=cl.exe
rem Microsoft C++ compiler options
set INCLUDES=
set INCLUDES=%INCLUDES% /I "%MSVC%\include"
set INCLUDES=%INCLUDES% /I "%SDKPATH%\Include\%SDK_VERSION%\ucrt"
set COMPILER_OPTIONS=%INCLUDES% /c /W3 /EHsc /nologo

rem Microsoft linker
set LINKER=link.exe
rem Microsoft linker options
set LIBDIRS=
set LIBDIRS=%LIBDIRS% /libpath:"%MSVC%\lib\x64"
set LIBDIRS=%LIBDIRS% /libpath:"%SDKPATH%\Lib\%SDK_VERSION%\um\x64"
set LIBDIRS=%LIBDIRS% /libpath:"%SDKPATH%\Lib\%SDK_VERSION%\ucrt\x64"

rem set LIBS="kernel32.lib" "user32.lib" "gdi32.lib"
set LINKER_OPTIONS=
set LINKER_OPTIONS=%LINKER_OPTIONS% %LIBDIRS% /DYNAMICBASE %LIBS%
set LINKER_OPTIONS=%LINKER_OPTIONS% /MACHINE:X64 /SUBSYSTEM:CONSOLE /NOLOGO

set APPNAME=xoxo.exe

set BUILD_DIR=%cd%\build
set BIN_DIR=%BUILD_DIR%\bin
set OBJ_DIR=%BUILD_DIR%\obj

rem %COMPILER% /? > help.txt

rem prepare environment
echo create environment structure
md %BIN_DIR%
md %OBJ_DIR%

rem compile
echo compile source files
%COMPILER% %COMPILER_OPTIONS% /Fo%OBJ_DIR%\engine.obj engine.cpp
%COMPILER% %COMPILER_OPTIONS% /Fo%OBJ_DIR%\main.obj main.cpp
%COMPILER% %COMPILER_OPTIONS% /Fo%OBJ_DIR%\board.obj board.cpp
%COMPILER% %COMPILER_OPTIONS% /Fo%OBJ_DIR%\player.obj player.cpp

rem build
echo link app %APPNAME%
set OBJECTS=%OBJ_DIR%\engine.obj %OBJ_DIR%\board.obj %OBJ_DIR%\player.obj %OBJ_DIR%\main.obj
%LINKER% %LINKER_OPTIONS% /OUT:"%BIN_DIR%\%APPNAME%" %OBJECTS%