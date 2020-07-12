@echo off

set PROGRAM="Debug\extract.exe"
set OUT="%TEMP%\out.txt"
set INPUT_DATA_FOLDER="input data"
set CORRECT_OUT_FOLDER="correct tests out"

echo Run program without parameters
%PROGRAM% > %OUT% && goto error
fc %OUT% %CORRECT_OUT_FOLDER%\1.txt > nul || goto error
echo Passed
echo.

echo Run program with wrong input file
%PROGRAM% %INPUT_DATA_FOLDER%\wrong.txt %OUT% > %OUT% && goto error
fc %OUT% %CORRECT_OUT_FOLDER%\2.txt > nul || goto error
echo Passed
echo.

echo Run program with empty input file
%PROGRAM% %INPUT_DATA_FOLDER%\empty.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\3.txt > nul || goto error
echo Passed
echo.

echo Run program with image size more than 100x100
%PROGRAM% %INPUT_DATA_FOLDER%\moreThan100x100.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\4.txt > nul || goto error
echo Passed
echo.

echo Run program with image without start positions to fill
%PROGRAM% %INPUT_DATA_FOLDER%\withoutStartPositions.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\5.txt > nul || goto error
echo Passed
echo.

echo Run program with image that would we filled full
%PROGRAM% %INPUT_DATA_FOLDER%\fullFill.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\6.txt > nul || goto error
echo Passed
echo.

echo Run program with image that would we filled out of bounds
%PROGRAM% %INPUT_DATA_FOLDER%\fillOutOfBounds.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\7.txt > nul || goto error
echo Passed
echo.

echo Run program with normal image
%PROGRAM% %INPUT_DATA_FOLDER%\fill.txt %OUT% || goto error
fc %OUT% %CORRECT_OUT_FOLDER%\8.txt > nul || goto error
echo Passed
echo.

echo All tests passed
exit /B 0

:error
echo Program test failed
exit /B 1