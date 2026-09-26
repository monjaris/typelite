#!/usr/bin/env sh

TEST="main"
DEFAULT_MODE="debug"

cd "tests/"
MODE="${1:-$DEFAULT_MODE}"
OS="$(xmake lua -c 'print(os.host())')"
PLAT="$(xmake lua -c 'print(os.arch())')"

xmake config --mode="$MODE" -y
xmake build -j$(nproc) -v "${TEST}" || exit $?

./"build/${OS}/${PLAT}/${MODE}/${TEST}" "$@"
