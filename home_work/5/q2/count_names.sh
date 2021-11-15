#!/bin/bash

# NOTE:
# * Your script MUST read the input from the given files as follows:
#   $ ./count_names.sh input.txt
# * Your script MUST print the result to the stdout.
# * Your script MUST conform to the output format provided in the question.
#
# ATTENTION: DON'T change this file name!
clear
COUNTER_OUTPUT=1
init_task() {
    if [ ! -e $1 ] || [ $1='' ]; then
        echo >&2 "EROOR need file path "
        exit 1
    fi
    if [ ! -e './counter.txt' ]; then
        echo 1 >'./counter.txt'
    else
        while read LINE; do
            COUNTER_OUTPUT=$LINE
            # echo $LINE
        done <'./counter.txt'
    fi
}
add_counter() {
    echo $COUNTER_OUTPUT >'counter.txt'
}
init_task
OUTPUT_FILE="names_output${COUNTER_OUTPUT}.txt"
# NEW=$(sed 's/[|!\]/,/p' $1)
NEW=$(sed 's/!/,/g' $1)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/ /,/g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/\\/,/g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/$/,/g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/\t/,/g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/|/,/g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
NEW=$(sed 's/,/ /g' $OUTPUT_FILE)
echo $NEW >$OUTPUT_FILE
COUNTER_WORD=$(wc -w $OUTPUT_FILE | cut -d " " -f1)
((COUNTER_OUTPUT++))
add_counter
echo "COUNTER:${COUNTER_WORD}" >$OUTPUT_FILE
