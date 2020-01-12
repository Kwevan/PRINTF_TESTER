GREEN='\033[1;32m'
RED='\033[0;31m'
OFF='\033[0m'

lib='libftprintf.a'
CC='gcc'
FLAGS='-Wall -Werror -Wextra'
main='main_tmp.c'
r_printf='results/printf.txt'
r_ft_printf='results/ft_printf.txt'
GET_HEADER=$(find ../ -name "*.h")

#here comptabilite couleur OS
e='-e'


cp main.c main_tmp.c
make libftprintf.a -C ../
cp ../libftprintf.a ./



${CC} ${FLAGS} ${main} ${lib}  && ./a.out > ${r_printf}


sed -i -e "s/"printf"/"ft_printf"/g" ${main}


${CC} ${FLAGS} -include ${GET_HEADER} ${main} ${lib}  && ./a.out > ${r_ft_printf}



DIFF=$(diff ${r_printf} ${r_ft_printf})

if [ "$DIFF" != "" ]
then
	
	echo  -e " \n \n \n \n PRINTF" >> ${r_printf}
	echo  -e "\n\n\n\n FT_PRINTF" >> ${r_ft_printf}
	
	sdiff -s ${r_printf} ${r_ft_printf}
	echo  "\n\nleft : printf" >> ${r_printf}
	echo "------------------------------------------------------------------------------------------------------------------------------"
	echo ${e} "\n${RED}[KO]"
	echo ${e} "${OFF}"
	echo -e "run vim diff ? (Y or N)\n"
	read answer
	if [ ${answer} == "y" ] || [ ${answer} == "Y" ] ||  [ ${answer} == "yes" ] || [ ${answer} == "YES" ]
	then
		vim -d ${r_printf} ${r_ft_printf}
	else
		echo "ok";
	fi
else
	echo  -e "${GREEN}[OK]"
fi






rm  ${main} ${lib} a.out 

rm ${r_printf} ${r_ft_printf}

#rm backup file

rm main_tmp.c-e



#	************************	others	*****************************


#kind of replacing a word by another
#sed -i -e "s/"ft_printf"/"printf"/g" ${main}

#delete first line of a file
#sed -i -e '1d' ${main}


#add text at the beginning of a file
#sed -i -e '1s/^/#include "..\/include\/ft_printf.h"\
#/' ${main}

#not working with -Werror	 don't get that: (2> /dev/null)
#${CC} ${main} i libftprintf.a 2> /dev/null && ./a.out > results/ft_printf.txt
