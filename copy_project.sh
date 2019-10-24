#!/bin/bash
if [[ -z $1 ]] || [[ -z $2 ]]; then
  echo "Not enough arguments!"
  echo
  echo "Usage: $(basename $0) OLD_PROJECT_DIR NEW_PROJECT_DIR"
fi

rsync -av --exclude build $1/ $2
cd $2
sed "s/$1/$2/g" CMakeLists.txt -i
sed "s/$1/$2/g" CMakeLists.txt.user -i
