


gcc main.c -D I=0 && ./a.out 0 > results/printf.txt
gcc main.c -D I=0 && ./a.out 1 > results/ft_printf.txt

DIFF=$(diff results/printf.txt results/ft_printf.txt)
if [ "$DIFF" != ""  ]
then 
	echo "KO"
else
	echo "OK"
fi
