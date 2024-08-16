cmake --preset vs2022-x64
cmake --preset vs2022-x86

cmake --build --preset vs2022-x64 --config Release
cmake --build --preset vs2022-x64 --config Debug

cmake --build --preset vs2022-x86 --config Release
cmake --build --preset vs2022-x86 --config Debug
