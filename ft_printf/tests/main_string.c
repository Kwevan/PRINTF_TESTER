#include "limits.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <unistd.h>

int main ()
{

//	printf ("%d\n\n",  printf("[%5x]", 5));



	/********************     %d     *******************/


	int size = 3;
	int i = 0;

	char **nb  = malloc(5 * sizeof(char*));

	//NULL est undef	

	nb[0] = "aloa";
	nb[1] = strdup("okkkkkkkkkkkkkkkkk");
	nb[2] = strdup("");;
	nb[3] = NULL;
	nb[4] = 0;

	while (i < size)
	{

		printf("-------------------- start while with %s --------------------", nb[i]);

		printf ("%d\n\n",  printf("1 [%s]",  nb[i]));

		printf ("%d\n\n",  printf("[ 2 [%s] okkk ]",  nb[i]));


		printf ("%d\n\n",  printf("[%5s]",  nb[i]));

		printf ("%d\n\n",  printf("[%.s]",  nb[i]));

		printf ("%d\n\n",  printf("[%10.s]",  nb[i]));

		printf ("%d\n\n",  printf("[%.10s]",  nb[i]));

		printf ("%d\n\n",   printf("5 [%10.6s]",  nb[i]));

		printf ("%d\n\n",  printf("10 [%sd]",  nb[i]));


		printf ("%d\n\n",  printf("[%5.0s]",  nb[i]));

		printf ("%d\n\n",  printf("[%5.0s]", nb[i]));

		//printf ("%d\n\n",  printf("15 [%0.5s]",  nb[i]));

		printf ("%d\n\n",  printf("[%10.5s]",  nb[i]));

		printf ("%d\n\n",  printf("[%11.10s]",  nb[i]));

		printf ("%d\n\n",  printf("[%5.s]",  nb[i]));


		printf ("%d\n\n",  printf("[%.5s]",  nb[i]));


		printf ("%d\n\n",  printf("[%.5s]",  nb[i]));


		printf ("%d\n\n",  printf("[%-.5s]",  nb[i]));



		printf ("\n**********  [*]  *********\n\n");


		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			printf ("%d\n\n",  printf("446 (%d) [%*s]", nb_2[i_2], nb_2[i_2], nb[i]));

			printf ("%d\n\n",  printf("447[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("448[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("449[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("450[%*.s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("441[%5.*s]", nb_2[i_2],  nb[i]));

			printf ("%d\n\n",  printf("452[%*.*s]",  nb_2[i], nb_2[i], nb[i]));

			i_2++;
		}


		i++;
	}

	printf ("%d\n\n",  printf("452b[%*.*s]",  -5, -10, "sd"));
	printf ("%d\n\n",  printf("452c[%*.*s]",  5, 10, "sd"));
	printf ("%d\n\n",  printf("454[%-*.*s]",  5, 10, "sd"));

	// ça a prit 4 minutes.......................
	//		printf ("%d\n\n",  printf("452 [%*s]", 100000000,  "abc"));	

	printf("%d\n\n",  printf("455 [%*s]", -1000,  "cba"));









	printf ("%d\n",  printf("%5.sdef",  "hij"));


	printf ("%d\n",  printf("%.5s",   "klm"));

	printf ("%d\n",  printf("%*.s", 5 , "pqr"));

	printf ("%d\n",  printf("%*.*s", 5 , 2, "stu"));
	printf ("%d\n",  printf("%*.*s", 5 , 2 , "stu"));



	printf ("%d\n\n",  printf("%.*s", -5  , "vwx"));

	printf ("%d\n\n",  printf("%.s" , "yza"));


	//care flags after type field

	printf ("%d\n\n",  printf("[%5.0s]",  "abc"));


	printf ("%d\n\n",  printf("[%5s.]",  "abc"));

	printf ("%d\n\n",  printf("[%5s.*0]",  "abc"));

	printf ("%d\n\n",  printf("[%5s-]",  "abc"));




	//end %s









	return (0);
}
