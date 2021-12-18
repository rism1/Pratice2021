@echo off
cd semest1\Basics of Programming

set string1=%DATE:~-10%
set string2=%string1:/=-%

set /P data="Enter log data: "
echo %data% > %string2%.log





