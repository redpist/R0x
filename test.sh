#!/bin/sh
#test script

if [ -n "`echo $@`"  ] ; then
    params=$@
else
    params=`ls test/`
fi
for i in $params ; do
    echo "--------------------------------------------------------------------------------"
    echo "STARTING test ($i):"
    rm -f "test/$i/_output"
    g++-4.6 -std=c++0x -Wextra -Wall -I include test/$i/main.cc && ./a.out > "test/$i/_output"
    if [ -f "test/$i/expected_output" ] ; then
        if [ -f "test/$i/_output" ] ; then
            output=`diff "test/$i/expected_output" "test/$i/_output"`
            if [ -z "$output" ] ; then
                result="OK"
            else
                result="ERROR"
                echo "output differ from file \"test/$i/expected_output\""
                echo -- "$output"
            fi
        else
            result="ERROR"
        fi
    else
        echo "no expected file : \"test/$i/expected_output\""
        echo "Output : "
        cat "test/$i/_output"
        result="WARNING"
    fi
    echo "test ($i) DONE : $result"
done
