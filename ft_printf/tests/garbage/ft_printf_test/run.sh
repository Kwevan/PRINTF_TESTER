source src/utils.sh

GREEN='\033[1;32m'
RED='\033[0;31m'
OFF='\033[0m'

yah

function work {

gcc main.c libftprintf.a -D I=0 && ./a.out  $i > results/printf.txt
gcc main.c libftprintf.a -D I=1 && ./a.out $i > results/ft_printf.txt

DIFF=$(diff results/printf.txt results/ft_printf.txt)
DIFF2=$(diff results/printf.txt results/error.txt)

if [ "$DIFF2" == "" ]
then
	exit 1
fi

if [ "$DIFF" != "" ]
then 
	echo  "${RED}[KO]"
	echo  "      		   ${OFF}printf:		[$(cat results/printf.txt)]"
	echo  "		ft_printf:		[$(cat results/ft_printf.txt)]"
else
	echo  "${GREEN}[OK]"
fi
}


TEST_COUNT=1000000000000 #en vrai yen a 5
i=0


make libftprintf.a -C ../
cp ../libftprintf.a ./

while [ $i -le $TEST_COUNT ]
do
	work
	i=$(( i+1 ))
done
