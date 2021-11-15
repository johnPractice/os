#! /bin/bash
# read for get input from user
clear
read -p "Enter you name: " NAME

if [ "${NAME}" = "reza" ]; then
    # expresion
    echo "you are admin"
else
    echo "Hello ${NAME}"
# end if :)
fi
