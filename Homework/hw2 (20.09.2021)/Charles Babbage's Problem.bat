@echo off
set /a val = 1


:inf_loop
set  /a power = %val% * %val%
if "269696" == "%power:~-6%" (
	echo %power%
	exit /b
)
%val% += 1
goto :inf_loop