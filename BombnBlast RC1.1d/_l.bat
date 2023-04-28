@echo off
set path=%path%;\SDCC\bin
sdcc -mz80 --code-loc 0x8048 --data-loc 0x7000 --no-std-crt0 ../crtcv.rel ../comp.lib ../cvlib.lib ../getput.lib charset1.rel charset2.rel charset3.rel charset4.rel Level_Contest.rel main.rel music.rel pieceData.rel Title.rel
objcopy --input-target=ihex --output-target=binary crtcv.ihx result.rom
del *.ihx
del crtcv.lnk
pause
