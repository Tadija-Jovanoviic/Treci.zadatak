/*
Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
ANxN pronalazi maksimalni element na pozicijama čiji je zbir indeksa paran broj i minimalni element
ispod sporedne dijagonale. Na standardnom izlazu ispisati proizvod ova dva broja. Dimenziju matrice i
vrednosti elemenata matrice učitati iz fajla "matrica.txt". Na početku fajla se nalazi dimenzija kvadratne
matrice nakon čega slede elementi matrice koji su razdvojeni jednim blanko znakom.
*/

#include <stdio.h>
int main()
{
	int A[10][10], n, i, j, min, max, max_init = 0, min_init = 0;
	FILE* f = fopen("matrica.txt", "r");
	if (f) {
		fscanf(f, "%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				fscanf(f, "%d", &A[i][j]);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if ((i + j) % 2 == 0)
				{
					if (!max_init || A[i][j] > max)
					{
						max_init = 1;
						max = A[i][j];
					}
				}
				if (i + j >= n)
				{
					if (!min_init || A[i][j] < min)
					{
						min_init = 1;
						min = A[i][j];
					}
				}
			}
		printf("%d", min * max);
		fclose(f);
	}
	return 0;
}