# Treci.zadatak

Kolekcija zadataka iz programskog jezika C - rad sa kvadratnim matricama. Svaki zadatak ucitava podatke iz tekstualnog fajla, vrsi odredjenu obradu nad matricom i prikazuje rezultat na standardnom izlazu.

## Fajlovi

### treci9.10.25.c - Maksimum na parnim pozicijama i minimum ispod sporedne dijagonale
Program ucitava dimenziju i elemente celobrojne kvadratne matrice iz fajla `matrica.txt`. Na pocetku fajla se nalazi dimenzija matrice, a zatim slede elementi razdvojeni blanko znakom. Program prolazi kroz matricu i pronalazi maksimalni element na pozicijama ciji je zbir indeksa paran broj (npr. pozicije (0,0), (0,2), (1,1), (2,0)...), kao i minimalni element koji se nalazi ispod sporedne dijagonale (pozicije gde je zbir reda i kolone veci ili jednak od N). Na standardnom izlazu ispisuje proizvod ta dva broja.

### treci21.10.25.c - Zamena vrste sa najvecom sumom
Program ucitava dimenziju i elemente celobrojne kvadratne matrice iz fajla `ulaz.txt`. Na pocetku fajla se nalazi dimenzija matrice, a zatim slede elementi razdvojeni blanko znakom. Program prolazi kroz svaku vrstu matrice, racuna sumu njenih elemenata i pronalazi vrstu koja ima najvecu sumu. Nakon toga, ta vrsta se zamenjuje sa prvom vrstom u matrici. Na kraju se prikazuje matrica nakon izvrsene transformacije, gde je svaki element razdvojen blanko znakom i svaka vrsta je u novom redu.

### treci28.10.25.c - Kretanje po matrici sa uputstvima
Program formira kvadratnu matricu NxN na osnovu uputstava iz fajla `matrica.txt`. Na pocetku fajla se nalazi dimenzija matrice, a zatim slede uputstva u obliku smera i broja koraka. Popunjavanje matrice pocinje od pozicije (0,0). Iz fajla se cita smer kretanja (`gore`, `dole`, `levo`, `desno`) i broj pozicija na koje treba upisati vrednost 1. Na primer, za uputstvo "desno 3" upisuje se jedinica na tri uzastopne pozicije udesno. Svako sledece uputstvo nastavlja od pozicije na kojoj je upisana poslednja jedinica. Svi preostali elementi matrice ostaju nule. Na kraju se formirana matrica prikazuje na standardnom izlazu.

### treci12.11.25.c - Dijagonale i prebrojavanje elemenata
Program ucitava dimenziju i elemente kvadratne matrice iz fajla `matrica.txt`. Implementirane su tri funkcije: `sumaG` racuna sumu elemenata na glavnoj dijagonali (elementi gde je red jednak koloni), `sumaS` racuna sumu elemenata na sporednoj dijagonali (elementi od gornjeg desnog do donjeg levog ugla), a `brojElemenata` broji koliko elemenata ispod glavne dijagonale ima vrednost vecu ili jednaku od aritmeticke sredine te dve sume. Program na kraju prikazuje ukupan broj pronadjenih elemenata.

### treci16.1.26.c - Formiranje matrice sa dijagonalama
Program ucitava dimenziju matrice iz fajla `dimenzija.txt` i formira kvadratnu matricu po posebnim pravilima. Svi elementi koji se nalaze na glavnoj dijagonali (gde je red jednak koloni) ili na sporednoj dijagonali (gde je zbir reda i kolone jednak N-1) dobijaju vrednost 1. Preostali elementi se popunjavaju uzastopnim brojevima pocevsi od 2, i to po kolonama, preskakajuci vec popunjene pozicije na dijagonalama. Nakon formiranja matrice, program racuna aritmeticku sredinu svih elemenata koji se istovremeno nalaze iznad glavne i iznad sporedne dijagonale, i prikazuje je zaokruzenu na dve decimale.
