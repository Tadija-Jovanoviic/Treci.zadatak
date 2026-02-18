/*
Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
Aₙₓₙ pronalazi minimalni element min iznad glavne dijagonale i maksimalni element max ispod sporedne
dijagonale. Prikazati korisniku vrednosti elemenata min i max. Dimenziju matrice i vrednosti elemenata
matrice učitati iz fajla „matrica.txt“. Na početku fajla se nalazi dimenzija kvadratne matrice nakon čega
slede elementi matrice koji su razdvojeni jednim blanko znakom
*/
#include <stdio.h>
int main()
{
	int M[10][10], n, i, j, min, max;
	FILE* f = fopen("matrica.txt", "r");
	if (f) {
		fscanf_s(f, "%d", &n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				fscanf_s(f, "%d", &M[i][j]);
		min = M[0][1];
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++)
				if (M[i][j] < min)
					min = M[i][j];
		max = M[1][0];
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (M[i][j] > max)
					max = M[i][j];
		printf("%d %d", min, max);
		fclose(f);
	}
	return 0;
}