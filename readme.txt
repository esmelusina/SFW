Copy the sfwdraw.h and SFW.lib into your project directory.

Right now, everything is setup using Visual Studio 2015. The .libs shouldn't work in other versions.
A vs2015 glfw3 binary can be found in the source folder if you'd like to use it for some other project.


In the solution explorer (visual studio),
	Right-Click Project
		-> Add
		-> Existing Item
		Select sfwdraw.h

	Right-click project
		-> Configuration Properties
		-> Linker
		-> Input
		-> Additional Dependencies
		-> Edit
		type in SFW.lib;

	
Look at the example project for usage.


This is a very simple framework to provide the simplest possible drawing context in C++.
It uses a fixed, pixel-perfect orthogonal view based on the size of the window created.
Immediate mode procedures are in place to draw white lines and circles- nothing else.


