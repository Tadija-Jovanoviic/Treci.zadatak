/*
 Na programskom jeziku C napisati strukturni program koji u celobrojnoj kvadratnoj matrici
𝐴𝑁×𝑁 određuje sumu elemenata na glavnoj dijagonali, a potom modifikuje elemente na sporednoj dijagonali
tako što im naizmenično dodaje i oduzima vrednost dobijene sume (prvom elementu na sporednoj
dijagonali dodaje sumu, drugom oduzima, trećem dodaje…). Prvim elementom sporedne dijagonale smatra
se element koji se nalazi u prvoj vrsti. Na izlazu prikazati matricu nakon transformacije. Dimenziju i
elemente matrice učitati sa standardnog ulaza.
*/
#include <stdio.h>
int main()
{
	int i, j, N, operacija = 1;
	int A[10][10];
	int suma = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
	for (i = 0; i < N; i++)
		suma += A[i][i];
	for (i = 0; i < N; i++)
	{
		A[i][N - 1 - i] += operacija * suma;
		operacija = -1 * operacija;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}