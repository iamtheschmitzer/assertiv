@REM Copyright (C) 2013, 2016 Object Computing Incorporated.
@REM All rights reserved.
@REM See the file license.txt for licensing information.
@REM
@REM Compile the assertiv test_example program.
@REM
@REM run in the MSVC: "Developer Command Prompt" window
@REM to ensure that cl and link are on the command path.  
cl test_example.cpp /EHsc
link test_example.obj
