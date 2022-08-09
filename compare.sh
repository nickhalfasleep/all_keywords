#!/bin/bash
total_lines=0
found_lines=0
percent=100
filename='keyword_list.txt'
while read line; do
# reading each line
if grep -q $line allkeywords.cpp; then
 ((found_lines++))
fi
((total_lines++))
done < $filename

echo percent found $((($percent*$found_lines)/$total_lines))
