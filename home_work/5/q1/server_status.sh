#!/bin/bash

# NOTE:
# * Your script MUST read the input from the given files as follows:
#   $ ./count_names.sh input.txt
# * Your script MUST print the result to the stdout.
# * Your script MUST conform to the output format provided in the question.
#
# ATTENTION: DON'T change this file name!
clear
FILE_INPUT=$1
LINE_SERVER=''
COUNTER_OUTPUT=1
init_task() {
    if [ ! -e './counter.txt' ]; then
        echo 1 >'./counter.txt'
    else
        while read LINE; do
            COUNTER_OUTPUT=$LINE
            echo $LINE
        done <'./counter.txt'
    fi
}
add_counter() {
    echo $COUNTER_OUTPUT >'counter.txt'

}
read_file() {
    init_task
    echo "read_file"
    while read LINE; do
        echo $LINE
        LINE_SERVER=$LINE
        check_server
    done <$FILE_INPUT
    ((COUNTER_OUTPUT++))
    add_counter
}

check_server() {
    # echo "check server"
    # echo $LINE_SERVER
    local FIRST_ARG="$(echo $LINE_SERVER | cut -d " " -f1)"
    local SECOND_ARG="$(echo $LINE_SERVER | cut -d " " -f2)"
    local THIRD_ARG="$(echo $LINE_SERVER | cut -d " " -f3)"
    local FOURTH_ARG="$(echo $LINE_SERVER | cut -d " " -f4)"
    # echo $THIRD_ARG
    local RESULT="FAIL"
    if [ ${SECOND_ARG} -gt 50 ] && [ $THIRD_ARG -gt 50 ] && [ $FOURTH_ARG -gt 50 ]; then
        RESULT="PASS"
    fi
    echo "${FIRST_ARG}: ${RESULT}" >>"server_output${COUNTER_OUTPUT}.txt"

}

if [ ! -e $1 ] || [ $1='' ]; then
    echo >&2 "EROOR need file path "
    exit 1
fi
if [ ${FILE_INPUT}="" ] || [ ${FILE_INPUT}='' ] || [ ! -e ${FILE_INPUT} ]; then
    echo >&2 "[Error] no such file"
    exit 1
else
    read_file $1
fi
