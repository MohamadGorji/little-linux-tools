#!/bin/bash
echo "Enter the directory:"
read user_dir
[ -z "$user_dir" ] && user_dir=$(pwd)
time=$(date +%M)
[ -d "$user_dir" ] && tar -czf backup_$time.tar.gz $user_dir
cur_dir=$(pwd)
cd /home 
mkdir -p backup
cd $cur_dir
mv backup_$time.tar.gz /home/backup
