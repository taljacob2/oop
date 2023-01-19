@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=../../../../config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=Object

CALL :CompileAllCFilesInCurrentDirectory
CALL :LibAllObjFilesInCurrentDirectory

REM Cleanup *.obj files.
del /F *.obj

del /F shared-config-local-variables.bat
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:CompileAllCFilesInCurrentDirectory
    CALL "%vcvars64%"
    for %%f in (*.c) do (
        CALL %CONFIG% :RunCl "/c %%f"
    )
GOTO :EOF

:LibAllObjFilesInCurrentDirectory
    CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib *.obj"
GOTO :EOF
