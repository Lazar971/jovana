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

void dodaj(PCVOR*glava, PRIJAVA prijava) {
    PCVOR pcvor =(PCVOR) malloc(sizeof (CVOR));
    pcvor->prijava = prijava;
    pcvor->sledeci=NULL;
    if (*glava == NULL) {
        *glava = pcvor;
        return;
    }
    PCVOR pom = *glava;
    while(pom->sledeci != NULL) {
        pom = pom->sledeci;
    }
   pom->sledeci = pcvor;
}

void kreiraj_listu(int info[][4], int n, PCVOR *glava) {
    int i;
    PRIJAVA* p;
    for (i=0;i<n;i++) {
        if (izracunajOcenu(info[i][1])> 5 && izracunajOcenu(info[i][2]) > 5) {
         p = (PRIJAVA*) malloc(sizeof (PRIJAVA));
         p->broj_indeksa = info[i][0];
         p->poeni_prakticni=info[i][1];
         p->poeni_usmeni=info[i][2];
         p->rok = info[i][3];
         dodaj(glava,*p);
        }
    }
}

void pronadji(int rok, PCVOR glava, PRIJAVA* prijava) {
    int poeni = 0;
    PCVOR pom = glava;
    while(pom != NULL) {
        if (pom->prijava.rok == rok && pom->prijava.poeni_prakticni>poeni) {
             *prijava =pom->prijava;
             poeni = pom->prijava.poeni_prakticni;
        }
    }
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
