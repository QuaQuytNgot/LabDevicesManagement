#!/usr/bin/env bash

set -e 

if [ -d build ]; then
  rm -rf build
fi

cmake -S . -B build > /dev/null 2>&1

cmake --build build --config Release > /dev/null 2>&1

if [ -f devices.csv ]; then
  cp devices.csv build/
fi


