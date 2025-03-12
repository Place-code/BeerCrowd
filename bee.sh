FILE=$1
PATH_FILE=$(find . -type f -name  $FILE)
TYPE_FILE=$(echo $FILE | rev | cut -d . -f1 | rev)

OUT_FILE="question.exe"
COMPILE=""
FLAGS=""
if [[ $TYPE_FILE = "c" ]];then
	COMPILE="gcc"
	FLAGS=" -Wall -Wextra -std=c99 -O2 -lm -o "${OUT_FILE}
elif [[ $TYPE_FILE = "cpp" ]];then
	COMPILE="g++"
	FLAGS=" -Wall -Wextra -std=c++20 -O2 -lm -o "${OUT_FILE}
elif [[ $TYPE_FILE = "rs" ]];then
	COMPILE="rustc"
	FLAGS="-o "${OUT_FILE}
elif [[ $TYPE_FILE = "hs" ]];then
	COMPILE="ghc"
	FLAGS="-o "${OUT_FILE}
elif [[ $TYPE_FILE = "cs" ]];then
	COMPILE="csc"
	FLAGS="-out:"${OUT_FILE}
elif [[ $TYPE_FILE = "php" ]];then
	COMPILE="php"
elif [[ $TYPE_FILE = "py" ]];then
	COMPILE="python3"
elif [[ $TYPE_FILE = "java" ]];then
	COMPILE="java"
fi

echo $COMPILE $FLAGS $PATH_FILE
$COMPILE $FLAGS $PATH_FILE
