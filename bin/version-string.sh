#!/usr/bin/env bash
# Print a version string for the currently-checked-out code.
# Copyright (C) 2023 Selene ToyKeeper
# SPDX-License-Identifier: GPL-3.0-or-later

# Usage: version-string.sh [c|git|both]
# Prints in C or Git format.  Defaults to both.

function main {
    echo "2025-02-12"
}

function git-describe {
    git describe --tags
}

function c-version-string {
    # version = git tag + revs since + dirty flag
    REV=$(git-describe)
    # convert "r2020-01-01-158-g0abcdef-dirty" to "2020-01-01+158#1"
    REV=$(echo "$REV" |
        sed -E 's/^r//;
                s/-dirty/#1/;
                s/-g[0-9a-f]+//;
                s/^([0-9]{4}-[0-9]{2}-[0-9]{2})-/\1+/;
                '
        )
    # handle an empty name (can happen during github action runs)
    if [[ -z "$REV" ]]; then
        HASH=$(git describe --always)
        REV="0.$HASH"
    fi
    # print the version string
    echo "$REV"
}

main "$@"

