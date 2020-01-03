#include "ft_printf.h"
int main ()
{

printf ("%d",  ft_printf("[050.1s]def\n",  "abc"));


//ft_printf("[%1s]def", "abc");

//seulement si . est present


//marche po, prends pas en compte la taille du nombre, affiche just x spaces
//printf ("[%d]\n", printf("%2dabc", 12));
//printf ("[%d]\n", ft_printf("%2dabc", 12));







	//ft_printf ( "[,  return: %d]", ft_printf("yo"));
//	ft_printf ( "[,  return: %d]", ft_printf("%d", -6));
//	ft_printf ( "[,  return: %d]", ft_printf("[%d], [%d], [%d]", 0, 1, -12 ));
//	ft_printf ( "[,  return: %d]", ft_printf("[%u], [%u], [%u]", 0, 1, -12 ));


/*i	char *s = "yo";
	printf ("ft_printf: ");
	printf ( "[,  return: %d]", ft_printf("[%p]", s  ));
	printf ("\nprintf: ");
	printf ( "[,  return: %d]", printf("[%p]", s  ));
*/


//	ft_printf("%yo\n", 5); //boucle infinie
//	printf("%yo", 5); //warning compile pas sur mac de lecole, mais sinn affiche simplement %yo

//	printf("%d"); //random nombres
//	ft_printf("%d"); //random nombres

//printf("%p", NULL); //return 5, print (nil)
/*
printf ("[%d]\n", ft_printf("%2iabc", 5));

printf ("[%d]\n", printf("%2iabc", 5));


printf ("[%d]\n", printf("%0iabc", 5));
printf ("[%d]\n", ft_printf("%0iabc", 5));
*/


}
