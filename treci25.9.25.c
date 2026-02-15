/*
 Na programskom jeziku C napisati strukturni program koji od realne matrice BMxN konstruiše
novu matricu AMxN koja se konstruiše tako što se svaki element matrice B zamenjuje aritmetičkom sredinom
tog elementa i desnog suseda tog elementa u istoj vrsti. Desni sused elementa matrice sa indeksom vrste i i
indeksom kolone j je element sa indeksom vrste i i indeksom kolone j+1. Kod poslednjeg elementa u vrsti
i, smatrati da je njegov desni sused element sa indeksom kolone 0 u istoj vrsti i. Matricu A prikazati
korisniku na standardnom izlazu gde je svaki element zaokružen na dve decimale i razdvojen blanko
znakom i svaka vrsta je u novom redu. Dimenzije matrice i vrednosti elemenata matrice je potrebno učitati
iz fajla “ulaz.txt”. Smatrati da se na početku fajla najpre nalazi broj vrsta matrice M, zatim broj kolona
matrice N razdvojene blanko znakom, nakon čega se u novom redu nalaze elementi matrice razdvojeni
jednim blanko znakom
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n, m, i, j;
	float B[10][10], A[10][10];
	FILE* f = fopen("ulaz.txt", "r");
	if (f)
	{
		fscanf(f, "%d %d", &m, &n);
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				fscanf(f, "%f", &B[i][j]);
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				A[i][j] = (B[i][j] + B[i][(j + 1) % n]) / 2;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				printf("%.2f ", A[i][j]);
			printf("\n");
		}
		fclose(f);
	}
	return 0;
}
