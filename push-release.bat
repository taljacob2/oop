@echo off

REM IMPORTANT: `SETLOCAL EnableDelayedExpansion` enables the use of variables
REM            inside "for loops".
REM NOTE: to use the variables, you should call them with `!var!` and not the
REM       usual `%var%`.
REM See https://stackoverflow.com/a/13805466/14427765
SETLOCAL EnableDelayedExpansion

REM --------------------------------- Imports ----------------------------------

REM IMPORT
SET CONFIG=config.bat
CALL %CONFIG%
CALL shared-config-local-variables.bat

REM ---------------------------------- Code ------------------------------------

SET ERRORLEVEL_MissingParameters=1
SET ERRORLEVEL_GetHelp=2

CALL :GetParametersRaw %*

if %ERRORLEVEL%==%ERRORLEVEL_GetHelp% (

    REM `:GetHelp` was called. Quit script.
    exit /b %ERRORLEVEL_GetHelp%
)

CALL :AssertAndDefaultParameters

if %ERRORLEVEL%==%ERRORLEVEL_MissingParameters% (

    REM `:AssertAndDefaultParameters` threw an error. Quit script.
    exit /b %ERRORLEVEL_MissingParameters%
)

echo Creating a local release...
start /I /WAIT /B cmd /c release.bat
echo Done.

echo Pushing the release to GitHub...
CALL :PushRelease
echo Done.


del /F shared-config-local-variables.bat >NUL 2>&1
GOTO :EOF

REM ------------------------------- Functions ----------------------------------

:GetHelp
    echo Pushes an official release with assets, to the GitHub repository's "master" branch, so it will be displayed in `https://api.github.com/repos/taljacob2/oop/releases`.
    echo.
    echo Usage (The order of the options does not matter):
    echo ```
    echo push-release.bat -token ^<YOUR-TOKEN^> -tagname ^<EXISTING-TAG-NAME^> [-name ^<"RELEASE-NAME"^>] [-prerelease ^<true/false^>] [-body ^<"RELEASE-BODY"^>] [-draft ^<true/false^>]
    echo ```
    echo.
    echo Example 1:
    echo ```
    echo push-release.bat -token ghp_IqIMN0ZH6z0wIEB4T9A2g4EHMy8Ji42q4HA5 -tagname v1.0.0
    echo ```
    echo.
    echo Example 2:
    echo ```
    echo push-release.bat -token ghp_IqIMN0ZH6z0wIEB4T9A2g4EHMy8Ji42q4HA5 -tagname v1.0.0 -name "My First Release" -body "This is the first release for this repository." -prerelease true
    echo ```
    echo.
    echo -token (REQUIRED)         Sets a token to access the GitHub repository.
    echo                           The token must have "push" credentials to the repository.
    echo -tagname (REQUIRED)       Sets the "tag" name to relate to this release.
    echo                           Prerequisites: The "tag" should already exist in the "master" branch before you call this script.
    echo -name                     A string, that will set the name of the release.
    echo                           Defaults to `-tagname`'s value.
    echo -prerelease               A literal text. May be `true` or `false`.
    echo                           Defaults to `false`.
    echo -body                     A string, that will add a body description to the release.
    echo                           Defaults to an empty string (with one space) `" "`.
    echo -draft                    A literal text, that determines if the release will be set as a draft or not.
    echo                           Defaults to `false`.
    
    REM Quit script with an errorlevel.
    exit /b %ERRORLEVEL_GetHelp%
GOTO :EOF

:GetParametersRaw
    :GetOptionParametersLoop
    IF NOT "%1"=="" (
        IF "%1"=="help" (
            CALL :GetHelp

            if %ERRORLEVEL%==%ERRORLEVEL_GetHelp% (

                REM `:GetHelp` was called. Quit script.
                exit /b %ERRORLEVEL_GetHelp%
            )
        )
        IF "%1"=="-token" (

            REM Required.
            REM A literal text. A GitHub token with a "push" credentials to the repository.
            SET token=%2
            SHIFT
        )
        IF "%1"=="-tagname" (

            REM Required.
            REM A literal text, that resembles an existing "tag" name to publish the release from.
            SET tagname=%2
            SHIFT
        )
        IF "%1"=="-name" (

            REM Optional. Defaults to `-tagname`'s value.
            REM A string, that will set the name of the release.
            SET name=%2
            SHIFT
        )
        IF "%1"=="-prerelease" (

            REM Optional. Defaults to `true`.
            REM A literal text. May be `true` or `false`.
            SET prerelease=%2
            SHIFT
        )
        IF "%1"=="-body" (

            REM Optional. Defaults to an empty string `" "`.
            REM A string, that will add a body description to the release.
            SET body=%2
            SHIFT
        )
        IF "%1"=="-draft" (

            REM Optional. Defaults to `false`.
            REM A literal text, that determines if the release will be set as a draft or not.
            SET draft=%2
            SHIFT
        )

        SHIFT
        GOTO :GetOptionParametersLoop
    )
GOTO :EOF

:AssertAndDefaultParameters

    REM Assert `-token` parameter.
    if not defined token (

        REM Quit script with an errorlevel.
        echo ERROR: Missing "token" parameter. Please pass a GitHub token that has "push" credentials and try again. Do it like so: "-token <YOUR-TOKEN>".
        echo.
        echo For further help, run:
        echo ```
        echo push-release.bat help
        echo ```
        exit /b %ERRORLEVEL_MissingParameters%
    )

    REM Assert `-tagname` parameter.
    if not defined tagname (

        REM Quit script with an errorlevel.
        echo ERROR: Missing "tagname" parameter. Please pass an existing "tag" name and try again. Do it like so: "-tagname <EXISTING-TAG-NAME>".
        echo.
        echo For further help, run:
        echo ```
        echo push-release.bat help
        echo ```
        exit /b %ERRORLEVEL_MissingParameters%
    )

    REM Defaults `-name` parameter to `-tagname`'s value converted to string.
    if not defined name (
        SET name="%tagname%"
    )

    REM Defaults `-prerelease` parameter to `false`.
    if not defined prerelease (
        SET prerelease=false
    )

    REM Defaults `-body` parameter to `" "`.
    if not defined body (
        SET body=" "
    )

    REM Defaults `-draft` parameter to `false`.
    if not defined draft (
        SET draft=false
    )
GOTO :EOF

:PushRelease
    start /I /WAIT wsl -e ./push-release-helper.sh %token% %tagname% %name% %body% %draft% %prerelease% %MSVC_RELEASE_PATH% %MSVC_RELEASE_NAME%
GOTO :EOF
