call ..\..\lib\Core\build.bat
 
REM Compile the demo using VC++
cl /std:c++20 /EHsc /Fe:bin/pilot_episode.exe /Fo:bin/pilot_episode.obj .\pilot_episode.cpp /I..\..\lib /I..\..\3rdparty\include /L..\..\3rdparty\lib

if %errorlevel% neq 0 (
    echo Build failed with error code %errorlevel%.
    exit /b %errorlevel%
)
 
REM Create necessary directories and copy resources
if not exist bin\fonts mkdir bin\fonts
xcopy /Y /E ..\..\lib\Termin8or\fonts bin\fonts

xcopy /Y /E chiptune2.ct bin
