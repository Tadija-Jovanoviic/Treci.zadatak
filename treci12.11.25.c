/*
Na programskom jeziku C napisati strukturni program koji za datu kvadratnu matricu
pronalazi sumu elemenata na glavnoj dijagonali SG, sumu elemenata na sporednoj dijagonali SS,
aritmetičku sredinu ove dve sume (SG+SS)/2, a nakon toga nalazi ukupan broj elemenata koji se nalaze
ispod glavne dijagonale i čija vrednost je veća od izračunate aritmetičke sredine. Računanja suma na
dijagonalama i nalaženje broja elemenata implementirati funkcijama sumaG, sumaS i brojElemenata,
respektivno. Dimenziju matrice i njene elemente učitati iz tekstualne datoteke "matrica.txt". Prvi elemenat
fajla je dimenzija, ostali su elementi matrice, razdvojeni jednim blanko znakom. Na standardnom izlazu
prikazati broj pronađenih elemenata.
*/
#include <stdio.h>
int sumaG(int matrica[100][100], int n) {
	int i, suma = 0;
	for (i = 0; i < n; i++) {
		suma += matrica[i][i];
	}
	return suma;
}
int sumaS(int matrica[100][100], int n) {
	int i, suma = 0;
	for (i = 0; i < n; i++) {
		suma += matrica[i][n - 1 - i];
	}
	return suma;
}
int brojElemenata(int matrica[100][100], int n, double prosecni) {
	int i, j, brojac = 0;
	// samo elementi ispod glavne (i > j)
	for (i = 1; i < n; i++) { // od druge vrste
		for (j = 0; j < i; j++) { // do i-1 kol
			if (matrica[i][j] >= prosecni) {
				brojac++;
			}
		}
	}
	return brojac;
}
int main() {
	int mat[100][100], n, i, j, s1, s2;
	double aritSred;
	FILE* file;
	file = fopen_s(&file, "matrica.txt", "r");
	fscanf_s(file, "%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf_s(file, "%d", &mat[i][j]);
		}
	}
	fclose(file);
	s1 = sumaG(mat, n);
	s2 = sumaS(mat, n);
	aritSred = (double)(s1 + s2) / 2.0; // arit sredina
	int rezultat = brojElemenata(mat, n, aritSred); // poziv funkcije za prebrojavanje
	printf("%d", rezultat);
	return 0;
}