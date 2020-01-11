GREEN='\033[1;32m'
RED='\033[0;31m'
OFF='\033[0m'

lib='libftprintf.a'
CC='gcc -Wall -Werror -Wextra'
main='main_tmp.c'
r_printf='results/printf.txt'
r_ft_printf='results/ft_printf.txt'

#here comptabilite couleur OS
e='-e'


cp main.c main_tmp.c
make libftprintf.a -C ../
cp ../libftprintf.a ./


sed -i -e "s/"ft_printf"/"printf"/g" ${main}
sed -i -e '1d' ${main}
sed -i -e '1s/^/#include "..\/include\/ft_printf.h"\
/' ${main}

gcc -Wall -Werror -Wextra ${main} libftprintf.a && ./a.out > results/printf.txt



sed -i -e "s/"printf"/"ft_printf"/g" ${main}
sed -i -e '1d' ${main}
sed -i -e '1s/^/#include "..\/include\/ft_printf.h"\
/' ${main}

${CC} ${main} libftprintf.a && ./a.out > results/ft_printf.txt





DIFF=$(diff ${r_printf} ${r_ft_printf})

if [ "$DIFF" != "" ]
then
	echo ${e} "${RED}[KO]"
	echo ${e} "${OFF}"
#	vim -d ${r_printf} ${r_ft_printf}
	#or
	sdiff -s ${r_printf} ${r_ft_printf}
	echo -e "\n\nleft : printf"
	echo -e "right : ft_printf\n"
else
	echo  -e "${GREEN}[OK]"
fi






rm  ${main} ${lib} a.out 

#rm ${r_printf} ${r_ft_printf}

#rm backup file

rm main_tmp.c-e

