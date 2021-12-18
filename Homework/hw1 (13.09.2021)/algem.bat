cd semest1\Algebra and Geometry

set /P data="Enter log data: "

set string1=%DATE:~-10%
set string2=%string1:/=-%

echo %data% > %string2%.log
