/*
Na programskom jeziku C napisati strukturni program koji na osnovu dimenzije N učitane iz
datoteke "dimenzija.txt" formira kvadratnu matricu 𝐴𝑁×𝑁. Matrica se formira tako što svi elementi na
glavnoj i sporednoj dijagonali dobijaju vrednost 1, dok se preostali elementi redom popunjavaju
uzastopnim brojevima (2, 3, 4, 5...) po kolonama, počev od elementa na poziciji (0,0), pri čemu se
preskaču već popunjene pozicije na dijagonalama. Nakon formiranja matrice, izračunati aritmetičku
sredinu svih elemenata koji se istovremeno nalaze iznad glavne i iznad sporedne dijagonale. Na
standardnom izlazu prikazati formiranu matricu, a zatim u novom redu i izračunatu aritmetičku sredinu,
zaokruženu na dve decimale.

*/
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j;
	int mat[100][100];
	int brojac = 2;
	int suma = 0;
	int brojEl = 0;
	FILE* fp;
	fp = fopen("dimenzija.txt", "r");
	if (fp) {
		fscanf(fp, "%d", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i == j || i + j == n - 1) {
					mat[i][j] = 1;
				}
				else {
					mat[j][i] = brojac++;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i < j && i + j < n - 1) {
					suma += mat[i][j];
					brojEl++;
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		if (brojEl > 0) {
			printf("%.2f", (float)suma / brojEl);
		}
		else {
			printf("%.2f", (float)suma);
		}
		fclose(fp);
	}
	return 0;
}