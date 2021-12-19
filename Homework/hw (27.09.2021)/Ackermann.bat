@echo off
set depth_value=0

:func
if %1==0 goto state1
if %2==0 goto state2
 
:else
set /a value1=%2-1
set /a depth_value+=1
call :func %1 %value1%
set value2=%errorlevel%
set /a value3=%1-1
call :func %value3% %value2%
set value2=%errorlevel%
set /a depth_value-=1
if %depth_value%==0 ( 
echo %value2%
goto stop
) else ( exit /b %value2% )
 
:state1
set/a value1=%2+1
if %depth_value%==0 ( 
echo %value1%
goto stop
) else ( exit /b %value1% )
 
:state2
set /a value3=%1-1
set /a depth_value+=1
call :func %value3% 1
set value2=%errorlevel%
set /a depth_value-=1
if %depth_value%==0 ( 
echo %value2%
goto stop
) else ( exit /b %value2% )

:stop
exit /b