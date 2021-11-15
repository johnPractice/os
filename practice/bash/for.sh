!# /bin/bash
clear
FILE=$(cat ls.txt)
# echo ${FILE}

for f in ${FILE}; do
    echo ${f}
done
