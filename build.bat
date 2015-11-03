@echo off

if %errorlevel% neq 0 goto fail


REM ---- Delete old generated files.
del src\*.generated.h

pushd src
cl /Zi template_expand.c
template_expand.exe
popd

pushd build

set sdl_link_deps=Winmm.lib Version.lib Shell32.lib Ole32.lib OleAut32.lib Imm32.lib

REM NOTES:
REM     Define MILTON_FANCY_GL for OpenGL debugging messages.

set mlt_defines=-D_CRT_SECURE_NO_WARNINGS

set mlt_opt=/O2 /MT
set mlt_nopt=/Od /MTd

set mlt_compiler_flags=/Oi /Zi /GR- /Gm- /Wall /WX /fp:fast /nologo /FC
REM 4100 Unreferenced func param (cleanup)
REM 4820 struct padding
REM 4255 () != (void)
REM 4668 Macro not defined. Subst w/0
REM 4710 Func not inlined
REM 4711 Auto inline
REM 4189 Init. Not ref
REM 4201 Nameless struct (GNU extension, but available in MSVC. Also, valid C11)
REM 4204 Non-constant aggregate initializer.
set comment_for_cleanup=/wd4100 /wd4189
set mlt_disabled_warnings=%comment_for_cleanup% /wd4820 /wd4255 /wd4668 /wd4710 /wd4711 /wd4201 /wd4204

set mlt_includes=-I ..\third_party\ -I ..\third_party\gui -I ..\third_party\SDL2-2.0.3\include -I ..\..\EasyTab

set mlt_links=..\third_party\glew32s.lib OpenGL32.lib ..\third_party\SDL2-2.0.3\VisualC\SDL\x64\Debug\SDL2.lib ..\third_party\SDL2-2.0.3\VisualC\SDLmain\x64\Debug\SDL2main.lib user32.lib gdi32.lib %sdl_link_deps%

cl %mlt_opt% %mlt_compiler_flags% %mlt_disabled_warnings% %mlt_defines% %mlt_includes%  ..\src\milton_unity_build.c /FeMilton.exe %mlt_links%
if %errorlevel% equ 0 goto ok
goto fail

goto ok
:fail
popd
exit /b 1

:ok
popd
exit /b 0
