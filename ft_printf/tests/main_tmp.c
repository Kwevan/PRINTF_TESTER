#include "limits.h"
#include "stdio.h"
#include <unistd.h>

int main ()
{


	char	c = 'a';
	int		ii = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -9999999;
	char	*n = "abcdefghijklmnop";

//	ft_printf("%s\n\n", n);

	ft_printf(" --- Return : %d\n\n", ft_printf("Simple input test"));
	ft_printf(" --- Return : %d\n\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", ii, j, k, l, m, n, c, c, j, j, j));
	ft_printf(" --- Return : %d\n\n", ft_printf("%d, %s, %c, %d, %u, %x, %X", m, n, c, c, j, j, j));

//	ft_printf ("%d\n\n",  ft_printf("[%5x]", 5));

	ft_printf ("%d\n\n",  ft_printf("[%x]", j));
	ft_printf ("%d\n\n",  ft_printf("[%X]", j));



	/********************     %d     *******************/


	int size = 10;
	int i = 0;
	//int nb[] = {12, -12};
	int nb[] = {INT_MIN, 1000000, -451, -5, 0, -0, 6, 451, 2000000, INT_MAX};

	while (i < size)
	{

		ft_printf ("%d\n\n",  ft_printf("1 [%d]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%5d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%05d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%.d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%10.d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%.10d]",  nb[i]));

		ft_printf ("%d\n\n",   ft_printf("5 [%10.6d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%0d]",  nb[i]));

		//here ft_printf print nothing for thr %d
		ft_printf ("%d\n\n",  ft_printf("[%.0d]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("10 [%5d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%5.0d]",  nb[i]));

		//error
		ft_printf ("%d\n\n",  ft_printf("[%5.0d]", nb[i]));

		//error
		ft_printf ("%d\n\n",  ft_printf("[%0.5d]",  nb[i]));

		ft_printf ("%d    |    the 0 flag is ignore because of the precision \n", ft_printf("[%010.5d]", nb[i]));

		ft_printf ("%d\n\n",    ft_printf("[%010.*d]", -5, nb[i]));

		ft_printf ("%d\n\n",  ft_printf("15 [%0.5d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%10.5d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%11.10d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%5.d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%05d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%.5d]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%.5d]",  nb[i]));

		ft_printf ("%d\n\n",  ft_printf("[%05d]",  nb[i]));


		ft_printf ("%d\n\n",  ft_printf("[%-.5d]",  nb[i]));


		//	*

		ft_printf ("\n**********  [*]  *********\n\n");

		//		int t[] = {}; idealement 2 int array pour chaque * mais flemme

		int nb_2[] = {-444, -5, 0, -0, 7, 222, 555};
		int size_2 = 7;
		int i_2 = 0;

		while (i_2 < size_2)	
		{	
			ft_printf ("%d\n\n",  ft_printf("446 (%d) [%*d]", nb_2[i_2], nb_2[i_2], nb[i]));

			ft_printf ("%d\n\n",  ft_printf("447[%5.*d]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("448[%5.*d]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("449[%5.*d]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("450[%*.d]", nb_2[i_2],  nb[i]));

			ft_printf ("%d\n\n",  ft_printf("441[%5.*d]", nb_2[i_2],  nb[i]));
			//ft_printf error		
			//		ft_printf ("%d\n\n",  ft_printf("452[%*.*d]",  nb_2[i], nb_2[i], nb[i]));

			//		ft_printf ("%d\n\n",  ft_printf("453[%0*.*d]",   nb_2[i], nb_2[i], nb[i]));

			i_2++;
		}
		i++;
	}

	ft_printf ("%d\n\n",  ft_printf("452bb[%0*d]",    -10, 7));
	ft_printf ("%d\n\n",  ft_printf("453b[%0*.*d]",   5, 10, 7));
	ft_printf ("%d\n\n",  ft_printf("453c[%0*.*d]",   -5, -10, -7));
	ft_printf ("%d\n\n",  ft_printf("453d[%0*.*d]",   -5, 10, -7));
	ft_printf ("%d\n\n",  ft_printf("453e[%0*.*d]",   5, -10, -7));
	ft_printf ("%d\n\n",  ft_printf("452b[%*.*d]",  -5, -10, -7));
	ft_printf ("%d\n\n",  ft_printf("452c[%*.*d]",  5, 10, 7));
	ft_printf ("%d\n\n",  ft_printf("454[%-*.*d]",  5, 10, 7));

	// ça a prit 4 minutes.......................
	//ft_printf ("%d\n\n",  ft_printf("452 [%*d]", 100000000,  9 ));


	ft_printf("%d\n\n",  ft_printf("455 [%*d]", -1000,  9));


//	sleep(5);

}
