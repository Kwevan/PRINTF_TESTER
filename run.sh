
#oui bon c'est un peu la merde 


array=(  main_string.c main_number.c main_c.c main_p_c.c main_u.c main_x.c main_p.c)


for item in ${array[*]}
do
    	printf "%0.s-" {1..30}
	printf "\n"
	printf "|        %-20s|\n" $item
	printf "|%28c|\n" ' '
    	printf "%0.s-" {1..30}	
	printf "\n\n"
	bash dont_run_me.sh ${item}
done
