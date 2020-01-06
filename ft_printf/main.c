#include "ft_printf.h"
int main ()
{

//start %d

// 5.* = 5
// 5. = 5

// . = 0
// .* = 0


// si point
	//si seul osef
	// si nb avant, then min = nb avant
	//si aucun nombre avant mais nb apres 
		//then min = nb apres et on print des 0 
//printf ("%d\n",  ft_printf("[%d]",  12));
//printf ("%d\n\n",  printf("[%d]",  12));

printf ("%d\n",  ft_printf("[%5d]",  3));
printf ("%d\n\n",  printf("[%5d]",  3));


printf ("%d\n",  ft_printf("[%05d]",  18));
printf ("%d\n\n",  printf("[%05d]",  18));


printf ("%d\n",  ft_printf("[%.d]",  17));
printf ("%d\n\n",  printf("[%.d]",  17));

 
printf ("%d\n",  ft_printf("[%10.6d]",  12));
printf ("%d\n\n",   printf("[%10.6d]",  12));

printf ("%d\n",  ft_printf("[%0d]",  15));
printf ("%d\n\n",  printf("[%0d]",  15));


//here printf print nothing for thr %d
printf ("%d\n",  ft_printf("[%.0d]",  0));
printf ("%d\n\n",  printf("[%.0d]",  0));


printf ("%d\n",  ft_printf("[%5d]",  0));
printf ("%d\n\n",  printf("[%5d]",  0));

printf ("%d\n",  ft_printf("[%d]",  0));
printf ("%d\n\n",  printf("[%d]",  0));


printf ("%d\n",  ft_printf("[%5.0d]",  2));
printf ("%d\n\n",  printf("[%5.0d]",  2));


//error
printf ("%d\n",  ft_printf("[%5.0d]", 0));
printf ("%d\n\n",  printf("[%5.0d]", 0));

//error
printf ("%d\n",  ft_printf("[%0.5d]",  0));
printf ("%d\n\n",  printf("[%0.5d]",  0));

printf ("%d\n",  ft_printf("[%0.5d]",  2));
printf ("%d\n\n",  printf("[%0.5d]",  2));

printf ("%d\n",  ft_printf("[%10.5d]",  12));
printf ("%d\n\n",  printf("[%10.5d]",  12));



printf ("%d\n",  ft_printf("[%11.10d]",  13));
printf ("%d\n\n",  printf("[%11.10d]",  13));

printf ("%d\n",  ft_printf("[%5.d]",  -14));
printf ("%d\n\n",  printf("[%5.d]",  -14));

printf ("%d\n",  ft_printf("[%05d]",  -14));
printf ("%d\n\n",  printf("[%05d]",  -14));

printf ("%d\n",  ft_printf("[%.5d]",  15));
printf ("%d\n\n",  printf("[%.5d]",  15));


printf ("%d\n",  ft_printf("[%.5d]",  -3));
printf ("%d\n\n",  printf("[%.5d]",  -3));

printf ("%d\n",  ft_printf("[%05d]",  -3));
printf ("%d\n\n",  printf("[%05d]",  -3));


printf ("%d\n",  ft_printf("[%-.5d]",  16));
printf ("%d\n\n",  printf("[%-.5d]",  16));



printf ("%d\n",  ft_printf("[%5.*d]", 2,  18));
printf ("%d\n\n",  printf("[%5.*d]", 2,  18));

printf ("%d\n",  ft_printf("[%5.*d]", -2,  17));
printf ("%d\n\n",  printf("[%5.*d]", -2,  17));

printf ("%d\n",  ft_printf("[%*.d]", -2,  11));
printf ("%d\n\n",  printf("[%*.d]", -2,  11));


printf ("%d\n",  ft_printf("[%0.5d]",  12));
printf ("%d\n\n",  printf("[%0.5d]",  12));


//end %d



//start %s

/*
printf (" ret: %d\n",  ft_printf("%5s",  "abc"));
printf (" ret: %d\n",  printf("%5s",  "abc"));

printf ("%d\n",  ft_printf("salut"));
printf ("%d\n",  printf("salut"));


//printf ("%d\n",  ft_printf("%05s",  "abc")); //undef
//printf ("%d\n",  printf("%05s",  "abc"));

printf ("%d\n", ft_printf("%5.sdef",  "abc"));
printf ("%d\n",  printf("%5.sdef",  "abc"));


printf ("%d\n", ft_printf("%.5s",   "abc"));
printf ("%d\n",  printf("%.5s",   "abc"));

printf ("%d\n", ft_printf("%*sdef", 5,  "abc"));
printf ("%d\n", ft_printf("%*sdef",  5,  "abc"));

printf ("%d\n",  ft_printf("%*.s",  5, "abc"));
printf ("%d\n",  printf("%*.s", 5 , "abc"));

printf ("%d\n",  printf("%*.*s", 5 , 2, "abc"));
printf ("%d\n",  printf("%*.*s", 5 , 2 , "abc"));



printf ("%d\n",  ft_printf("%.*s" , -5,  "abc"));
printf ("%d\n\n",  printf("%.*s", -5  , "abc"));

printf ("%d\n",  ft_printf("%.s" , "abc"));
printf ("%d\n\n",  printf("%.s" , "abc"));



printf ("%d\n",  ft_printf("[%5.0s]",  "abc"));
printf ("%d\n\n",  printf("[%5.0s]",  "abc"));

//printf ("%d\n",  ft_printf("[%0.5s]",  "abc")); //undef
//printf ("%d\n\n",  printf("[%0.5s]",  "abc"));

*/
//end %s






//start bordel

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
