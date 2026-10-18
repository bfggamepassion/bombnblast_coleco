@echo off
rem Lance result.rom dans blueMSX en mode ColecoVision
set EMU=D:\Emulation\BlueMSX\blueMSX.exe
if not exist "%~dp0result.rom" (
  echo result.rom introuvable : compile le jeu d'abord avec _c.bat puis _l.bat
  pause
  exit /b 1
)
start "" "%EMU%" /machine "COL - ColecoVision" /rom1 "%~dp0result.rom"
