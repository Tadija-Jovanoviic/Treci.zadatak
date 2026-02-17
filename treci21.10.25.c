/*
Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
ANxN pronalazi vrstu sa najvećom sumom elemenata i zamenjuje je sa prvom vrstom u matrici.
Pretpostaviti da postoji samo jedna vrsta sa maksimalnom sumom, da matrica sadrži samo pozitivne cele
brojeve, kao i da dimenzija matrice neće biti nula. Dimenziju matrice i vrednosti elemenata matrice je
potrebno učitati iz fajla "ulaz.txt". Smatrati da se na početku fajla najpre nalazi dimenzija matrice, nakon
čega slede elementi matrice razdvojeni jednim blanko znakom. Prikazati matricu nakon transformacije na
standardnom izlazu, gde je svaki element razdvojen blanko znakom i svaka vrsta je u novom redu.

*/

#include <stdio.h>
int main() {
	FILE* f;
	int matrica[100][100], i, j, n, maxSuma = 0, maxIndeks = 0;
	fopen_s(&f, "ulaz.txt", "r");
	fscanf_s(f, "%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf_s(f, "%d", &matrica[i][j]);
		}
	}
	fclose(f);
	for (i = 0; i < n; i++) {
		int trenutnaSuma = 0;
		for (j = 0; j < n; j++) {
			trenutnaSuma += matrica[i][j];
		}
		if (trenutnaSuma > maxSuma) {
			maxSuma = trenutnaSuma;
			maxIndeks = i;
		}
	}
	if (maxIndeks != 0) {
		for (j = 0; j < n; j++) {
			int temp = matrica[0][j];
			matrica[0][j] = matrica[maxIndeks][j];
			matrica[maxIndeks][j] = temp;
		}
	}
	printf("Matrica nakon transformacije:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
	return 0;
}