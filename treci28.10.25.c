/*
Na programskom jeziku C napisati strukturni program koji formira kvadratnu matricu ANxN na
osnovu tekstualnog fajla “matrica.txt”. Elementi matrice su isključivo vrednosti 0 i 1. Na početku fajla se
nalazi dimenzija matrice, a zatim uputstvo na kojim pozicijama u matrici treba upisati vrednost 1. Preostali
elementi matrice su nule. U svakom redu fajla se nalazi reč iz skupa {gore, dole, levo, desno} i prirodan
broj X odvojen blanko znakom. Popunjavanje matrice počinje od pozicije (0,0) i od te pozicije je potrebno
upisati X jedinica u pravcu pročitane reči (za slučaj “desno 3” potrebno je upisati vrednost 1 na pozicije
(0,0), (0,1) i (0,2)). Matrica se dalje popunjava po istom pravilu, ali od pozicije na kojoj je upisana poslednja
jedinica. Smatrati da je uputstvo validno i da se praćenjem uputstva ne izlazi iz granica matrice. Čitati
uputstvo dok se ne dođe do kraja fajla. Formiranu matricu prikazati na standardnom izlazu.
*/

#include <stdio.h>
#include <string.h>
int main()
{
	int N, i, j, k, x, A[20][20];
	char dir[6];
	FILE* f = fopen("matrica.txt", "r");
	fscanf_s(f, "%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			A[i][j] = 0;
	i = 0;
	j = 0;
	while (!feof(f))
	{
		fscanf_s(f, "%s%d", dir, &x);
		for (k = 0; k < x; k++)
		{
			A[i][j] = 1;
			if (k < x - 1)
			{
				if (strcmp(dir, "desno") == 0)
					j = j + 1;
				else if (strcmp(dir, "levo") == 0)
					j = j - 1;
				else if (strcmp(dir, "dole") == 0)
					i = i + 1;
				else //gore
					i = i - 1;
			}
		}
	}
	fclose(f);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}