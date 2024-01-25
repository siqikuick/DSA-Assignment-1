#! /bin/bash

# array of programs to check
declare -a programs=("cmake" "make")

program_not_installed=0

for program in "${programs[@]}"
do
    if ! [ -x "$(command -v $program)" ]; then
        echo "Error: $program is not installed." >&2
        program_not_installed=1
    fi
done

if [ $program_not_installed -eq 1 ]; then
    exit 1
fi

echo "Building the project..."
mkdir -p build
cd build
# check if there's a --debug flag passed
if [ "$1" == "--debug" ]; then
    echo "Building in debug mode..."
    cmake -DCMAKE_BUILD_TYPE=Debug ..
else
    echo "Building in release mode..."
    cmake ..
fi
make
echo "Done!"