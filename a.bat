@echo off
md .\Dest 2>nul
for /f "delims=" %%f in ('dir ".\Files\*.kwm" /a/b') do (
.\bin\kwm ".\Files\%%f" ".\Dest\%%~nf.flac"
)
pause