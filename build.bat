@echo off

set target="out\%1"
cmake -B %target% -S . -DCMAKE_BUILD_TYPE=%1
cmake --build %target% --config %1

