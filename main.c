#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor CVOR;
typedef CVOR* PCVOR;
typedef struct prijava{
    int broj_indeksa;
    int poeni_prakticni;
    int poeni_usmeni;
    int rok;
} PRIJAVA;
struct cvor{
    PRIJAVA prijava;
    PCVOR sledeci;
};

int izracunajOcenu(int poeni) {
    int ocena = poeni/10;
    if (ocena<5){
        return 5;
    }
    return ocena;
}

int ocena(int broj_indeksa, int rok, int info[][4], int n) {
    int i;
    for(i=0;i<n;i++) {
        if (info[i][0] == broj_indeksa && info[i][3]==rok) {
            return (izracunajOcenu(info[i][1]) + izracunajOcenu(info[i][2])) /2;
        }
    }
    return 5;
}

double prosek(char deo_ispita, int rok, int info[][4], int n) {
    int kolona = deo_ispita =='p' ? 1 :2;
    double res = 0;
    int i,ukupno=0;
    for(i=0;i<n;i++) {
        if (info[i][3] != rok) {
            continue;
        }
        ukupno++;
        res = res + info[i][kolona];
    }
    return res / ukupno;
}

int proveri_indeks(int indeks) {
    if (indeks <0) {
        return 0;
    }
   int godina = indeks / 10000;
   int broj = indeks % 10000;
   if (godina < 2000 || godina > 2022) {
    return 0;
   }
   if (broj <1 || broj > 999) {
    return 0;
   }
   return 1;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
