/*
Na programskom jeziku C napisati strukturni program koji prikazuje elemente kolone
celobrojne kvadratne matrice ANxN čija je suma najveća (pretpostaviti da postoji samo jedna takva kolona).
Dimenziju matrice N i vrednosti elemenata matrice učitati iz fajla "matrica.txt". Na početku fajla se nalazi
dimenzija kvadratne matrice nakon čega slede elementi matrice koji su razdvojeni jednim blanko znakom.
Na izlazu prikazati elemente kolone u jednom redu razdvojene sa po jednim blanko znakom.
*/

#include <stdio.h>
int main()
{
	int i, j, N, kolonaIndex = -1;
	int matrica[100][100];
	int suma, maxSum = 0;
	FILE* f = fopen("matrica.txt", "r");
	fscanf(f, "%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			fscanf(f, "%d", &matrica[i][j]);
		}
	}
	fclose(f);
	for (j = 0; j < N; j++)
	{
		suma = 0;
		for (i = 0; i < N; i++)
		{
			suma += matrica[i][j];
		}
		if (suma > maxSum)
		{
			maxSum = suma;
			kolonaIndex = j;
		}
	}
	for (i = 0; i < N; i++)
		printf("%d ", matrica[i][kolonaIndex]);
	return 0;
}