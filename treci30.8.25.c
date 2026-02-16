/*
 Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
𝐴𝑁×𝑁 određuje sumu apsolutnih vrednosti elemenata na i ispod glavne dijagonale, kao i sumu apsolutnih
vrednosti elemenata na i iznad sporedne dijagonale. Na izlazu prikazati vrednost veće od dve sume.
Dimenziju matrice i elemente učitati iz fajla "matrica.txt".
*/
#include <stdio.h>
void main()
{
	int i, j, N;
	int A[10][10];
	int glavna = 0;
	int sporedna = 0;
	FILE* f = fopen("matrica.txt", "r");
	fscanf(f, "%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			fscanf(f, "%d", &A[i][j]);
		}
	}
	fclose(f);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j) {
				sporedna += abs(A[i][j]);
			}
			if (i + j <= N - 1) {
				glavna += abs(A[i][j]);
			}
		}
	}
	if (glavna > sporedna)
		printf("%d", glavna);
	else
		printf("%d", sporedna);
}