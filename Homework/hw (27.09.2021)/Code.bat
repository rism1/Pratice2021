@echo off

for /l %%j in (33,1,255) do (
	call :fetch %%j
)
exit /b

:fetch
cmd /c exit %1
echo %1 "%=exitcodeAscii%"
exit /b