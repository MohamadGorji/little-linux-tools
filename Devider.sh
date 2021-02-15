#!/bin/bash

#devide directories from files
seprate_array()
{
    Directories=();
    Files=();
    cd $1;
    for f in *; 
    do
        if [ -d "$f" ]; 
        then
            Directories+=($f);
        fi

        if [ -f "$f" ]; 
        then
            Files+=($f);
        fi
    done
}

#print output
output_print()
{
    len1=${#Directories[*]}
    len2=${#Files[*]}
    header="\n%-40s  | %-40s\n"
    format="%-40s  | %-40s\n"
    printf "$header" "Directories" "Files"
    printf '%42s|%40s\n' | tr ' ' =
    for ((i = 0 , j=0 ; i < ${len1} || j < ${len2} ; i++ , j++)); 
    do
        printf "$format" ${Directories[i]} ${Files[j]}
    done
}

#option handler
if [ -d "$1" ]; 
then
    seprate_array $1
    output_print $Directories $Files
elif [ "$1" = "-o" ]; 
then
    seprate_array $3
    output_print $Directories $Files >> $2
else
    echo "Err"
fi

