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
        return 5
    }
    return ocena;
}

int ocena(int broj_indeksa, int rok, int info[][4], int n) {
    int i;
    for(i=0;i<n;i++0) {
        if (info[i][0] == broj_indeksa && info[i][3]==rok) {
            return (izracunajOcenu(info[i][1]) + izracunajOcenu(info[i][2])) /2;
        }
    }
    return 5;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
