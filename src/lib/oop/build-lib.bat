@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=../../../config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET LIBRARY_NAME=%OUTPUT_LIB_FILE_NAME%

@REM CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib dir /s/b *.lib"

REM See https://stackoverflow.com/a/2423969/14427765
REM See https://www.geeksforgeeks.org/batch-script-iterating-over-an-array/

REM Initialize with nothing.
SET subLibList=

for /f %%f in ('dir /s/b/a:d') do (
	cd "%%f"

    REM Execute the submodule's  `build-lib.bat`.
    start /I /WAIT /B cmd /c build-lib.bat

    REM See https://stackoverflow.com/a/57802962/14427765
    for /f %%i in ('dir /b ^| findstr /e .lib') do (
        SET SUB_LIB_NAME=%%i
    )
    
	cd ..

    REM Add ` %%f\!SUB_LIB_NAME!` to `subLibList`, only if `!SUB_LIB_NAME!`
    REM is not empty. Notice the preceeding `' '`.
    REM See https://stackoverflow.com/a/41586321/14427765
    if defined SUB_LIB_NAME ( SET subLibList=!subLibList! %%f\!SUB_LIB_NAME! )
)

if defined subLibList ( 
    CALL %CONFIG% :RunLib "/out:%LIBRARY_NAME%.lib !subLibList!"
)

del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF
