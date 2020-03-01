FOR %%i IN (1,1,30) DO (
echo f
cl %%i
if exist %%~ni.exe (echo C++ >> C:\Users\Alexandra\Documents\Informaticsss\mosh2017-2018\2\cmd.txt) ELSE (
fpc %%i
if exist %%~ni.exe (echo Pascal >> C:\Users\Alexandra\Documents\Informaticsss\mosh2017-2018\2\cmd.txt) ELSE (echo Python >> C:\Users\Alexandra\Documents\Informaticsss\mosh2017-2018\2\cmd.txt)))