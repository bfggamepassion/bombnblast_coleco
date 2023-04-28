ColecoVision Startkit (for SDCC)
Made by Daniel Bienvenu, 2009-2010.

DATE : 3-JULY-2010

STATE : BETA


REMARK FROM THE AUTHOR
======================
Even if it's a beta version, this distribution works for me,
so it should works for you. If you find any bug or problem
while using this kit, look first at the web site for any
updated version and/or contact me by email.

For specific needs, like a map maker or a fancy effect
for you game project, I can't help you...
... I've my own projects to deal with.

Have fun!

- Daniel Bienvenu (aka Newcoleco)


How to install
==============

1. Unzip this archive

2. Install SDCC (Windows snapshot) - Complete (or Medium)
URL : http://sdcc.sourceforge.net/

3. Copy "objcopy.exe" file from "z80/tools/System" to SDCC "bin" folder

4. Copy all header files "*.h" from "z80" to SDCC "include" folder


How to compile
==============

1. Copy "CCI2.EXE" file from "z80/tools/System" in your project folder which should be a sub-folder of "z80".

2. Execute "CCI2.EXE"

3. Click "Compile All", Press space bar when asked for any key. 

4. Checkmark needed files or click on "Default"

5. Click "Link", Press space bar when asked for any key.

6. Clink "Run"


TROUBLE SHOOTING
================

ERROR #1 :

    It doesn't compile... CCI can't find "EXE" files.

  SOLUTION #1 :

    Try reinstalling SDCC : Complete (or Medium), all folders, and PATH to "binary path".


ERROR #2 : Missing file(s)

    While compiling, you get a message like this :
    "...  fatal error: coleco.h: No such file or directory"
  
  SOLUTION #2 : Copy file(s)

    You didn't copy the header files properly (or not at all).
    Copy "coleco.h","getput.h" and "comp.h" into SDCC "include" folder.
  
    C:\Program Files\SDCC\include
    - or -
    C:\Program Files (x86)\SDCC\include


ERROR #3 : Missing libraries

    While linking, you get this message :
    "?ASlink-Warning-Couldn't find library 'z80'"

  SOLUTION #3 : Reinstall SDCC.


ERROR #4 : Missing 'objcopy'

    While linking, objcopy is used to make the binary file.

  SOLUTION #4

    Copy 'objcopy.exe' from "z80/tools/System" to SDCC "bin" foler.

    C:\Program Files\SDCC\bin
    - or -
    C:\Program Files (x86)\SDCC\bin


ERROR #5 : Undefined Global functions/routines

    While linking, you get a message like this :
    "?ASlink-Warning-Undefined Global '_disable_nmi' referenced by module 'main'"

  SOLUTION #5

    Click default button in CCI interface.

ERROR #6 : Missing MSVBVM50.DLL ?

    While trying to run ICVGM, WAV2CV and WAV2CVDS

  SOLUTION : 

    You need a DLL to run VisualBASIC 5 programs.
    URL : http://support.microsoft.com/search/default.aspx?query=Msvbvm50.exe