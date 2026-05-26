#!/usr/bin/env bash

set -e

find ../src -type f \( -name "*.cpp" -o -name "*.h" \) -exec clang-format -i {} +
