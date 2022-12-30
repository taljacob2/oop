#!/bin/bash

ROOT_PATH=`pwd`

SRC_PATH="$ROOT_PATH"/src
MAIN_PATH="$SRC_PATH"/main
TEST_PATH="$SRC_PATH"/test
LIB_PATH="$SRC_PATH"/lib
OUTPUT_LIB_PATH="$LIB_PATH"/oop

OUTPUT_LIB_FILE_NAME=oop

# --------- Edit to you liking: ---------

RUN_WITH_VALGRIND=true
VALGRIND_OPTIONS=--"leak-check=full --show-leak-kinds=all"
