# xinu-timed-events
## CIS 657 Principles of Operating System - lab 6
------------------------------------------------------------------
This repository contains the original xinu source code for the 
beagle bone black. A prototype functionality of timed function is also implemented 
to part of this code base. The time function feature is similar to FreeBSD's callout 
queue, where a function call can be delayed until some time in the future. 

Note: This only executes certain hard coded functions for demonstration purpose, but can be extended to handle other functions.

Steps to build xinu image (root folder)

1. $ cd compile 
2. $ touch mipsVars 
3. $ cd uboot-tool 
4. $ make clean; make 
5. $ cd ..
6. $ make clean; make (compile directory)

A precompiled xinu binary is located in xinu/compile/xinu 