#!/bin/bash
set -e
if [[ -z $1 ]] || [[ -z $2 ]]; then
  echo "Not enough arguments!"
  echo
  echo "Usage: $(basename $0) OLD_PROJECT_DIR NEW_PROJECT_DIR"
fi

rsync -av --exclude build --exclude CMakeLists.txt.user $1/ $2
cd $2
sed "s/$1/$2/g" CMakeLists.txt -i
