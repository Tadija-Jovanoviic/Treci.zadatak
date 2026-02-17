/*
Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
BNxN određuje razliku proizvoda elemenata na glavnoj i proizvoda elemenata na sporednoj dijagonali
matrice. Nakon toga, potrebno je odrediti broj parnih elemenata matrice koji se nalaze ispod glavne
dijagonale i koji su veći od prethodno određene razlike. Datu vrednost prikazati korisniku na standardnom
izlazu. Dimenziju matrice i vrednosti elemenata matrice je potrebno učitati iz fajla “ulaz.txt”. Smatrati da
se na početku fajla najpre nalazi dimenzija matrice, nakon čega se u novom redu nalaze elementi matrice
razdvojeni jednim blanko znakom.
*/


#include<stdio.h>
int main()
{
	int B[10][10], i, j, n, br = 0, razlika, glavna_d = 1, sporedna_d = 1;
	FILE* f = fopen("ulaz.txt", "r");
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf(f, "%d", &B[i][j]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				glavna_d *= B[i][j];
			if (i + j == n - 1)
				sporedna_d *= B[i][j];
		}
	}
	razlika = glavna_d - sporedna_d;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i > j && B[i][j] % 2 == 0 && B[i][j] > razlika)
				br++;
		}
	}
	printf("%d ", br);
	return 0;
}