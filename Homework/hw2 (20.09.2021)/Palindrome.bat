@echo off
setlocal enabledelayedexpansion

set line=%1
set num=0
echo %line%

:LOOP
call set tmpa=%%line:~%num%,1%%%
set /a num+=1
if not "%tmpa%" equ "" (
set rline=%tmpa%%rline%
goto LOOP
)


echo %rline%

if %line% == %rline% (
	echo YES
	exit /b
)
echo NO