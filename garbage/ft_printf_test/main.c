#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ft_printf.h" //se renseigner sur les noms possible de ce header


void test2()
{
	if(I)
		printf("ret: %i\n", printf("Test 2, "));
	else
		printf("ret: %i\n", ft_printf("Test 2, "));

}

void test1()
{
	if (I)	
		printf("ret: %i\n", printf("ft Test 1, "));
	else
		printf("ret: %i\n", printf("Test 1, "));
}
int main(int ac, char **av)
{
	(void)ac;
	int count = atoi(av[1]);

	switch (count)
	{
		case 0:
			test1();
			break;
		case 1:
			test2();
			break;
		case 2:
			test2();
			break;
		case 3:
			test2();
			break;
		default:
			printf("Error switch case");
	}

    return (0);
}
