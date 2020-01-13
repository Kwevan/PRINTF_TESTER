#REAL_MAIN='main_string.c'
#REAL_MAIN='main_number.c'
#REAL_MAIN='main_c.c'
#REAL_MAIN='main_p_c.c'
REAL_MAIN='main_p.c'



GREEN='\033[1;32m'
RED='\033[0;31m'
OFF='\033[0m'

main='main_tmp.c'
lib='libftprintf.a'
CC='gcc'
FLAGS='-Wall -Werror -Wextra'
r_printf='results/printf.txt'
r_ft_printf='results/ft_printf.txt'
GET_HEADER=$(find ../ -name "*.h")

#here comptabilite couleur OS
e='-e'



cp ${REAL_MAIN}  ${main}
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
##	echo -e "run vim diff ? (Y or N)\n"
#	read answer
#	if [ ${answer} == "y" ] || [ ${answer} == "Y" ] ||  [ ${answer} == "yes" ] || [ ${answer} == "YES" ]
#	then
#		vim -d ${r_printf} ${r_ft_printf}
#	else
#		echo "ok";
#	fi
else
	echo  -e "${GREEN}[OK] - All GOOD"
	echo ${e} "${OFF}"
fi



while true
do

	echo -e "type: 1, 2, 3, or 4\n\n\n[ show diff ] (1)  |  [ show printf results ] (2)  |  [ show ft_printf results ] (3)  |  [ exit ] (4)\n"

	read answer
	if [ ${answer} == "1" ]
	then
		vim -d ${r_printf} ${r_ft_printf}
	elif [ ${answer} == "2" ]
	then
 		vim ${r_printf}
	elif [ ${answer} == "3" ]
	then
 		vim ${r_printf}
	elif [ ${answer} == "4" ]
	then
		break
	fi
done



rm  ${main} ${lib} a.out 

#rm ${r_printf} ${r_ft_printf}

#rm backup file
rm main_tmp.c-e #only for mac

make fclean -C ../ 




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
