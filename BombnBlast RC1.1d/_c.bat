@echo off
set path=%path%;\SDCC\bin
sdcc -mz80 -c --std-c99 --opt-code-speed charset1.c
del charset1.lst
del charset1.sym
del charset1.asm
sdcc -mz80 -c --std-c99 --opt-code-speed charset2.c
del charset2.lst
del charset2.sym
del charset2.asm
sdcc -mz80 -c --std-c99 --opt-code-speed charset3.c
del charset3.lst
del charset3.sym
del charset3.asm
sdcc -mz80 -c --std-c99 --opt-code-speed charset4.c
del charset4.lst
del charset4.sym
del charset4.asm
sdcc -mz80 -c --std-c99 --opt-code-speed Level_Contest.c
del Level_Contest.lst
del Level_Contest.sym
del Level_Contest.asm
sdcc -mz80 -c --std-c99 --opt-code-speed main.c
del main.lst
del main.sym
del main.asm
sdasz80 -o music.rel music.s
sdcc -mz80 -c --std-c99 --opt-code-speed pieceData.c
del pieceData.lst
del pieceData.sym
del pieceData.asm
sdcc -mz80 -c --std-c99 --opt-code-speed Title.c
del Title.lst
del Title.sym
del Title.asm
pause
