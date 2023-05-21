#include <stdio.h>


void sortujTabliceFor(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
        }
    }
}

void sortujTabliceWhile(int tablica[], int rozmiar) {
    int i = 0;
    while (i < rozmiar - 1) {
        int j = 0;
        while (j < rozmiar - i - 1) {
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}
void sortujTabliceDoWhile(int tablica[], int rozmiar) {
    int i = 0;
    do {
        int j = 0;
        do {
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
            j++;
        } while (j < rozmiar - i - 1);
        i++;
    } while (i < rozmiar - 1);
}

void wyswietlTablice(int tablica[], int rozmiar) {
    printf("Tablica: ");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
}

int main(){
    int tab[] = {10,30,50,666,22,1};
    sortujTabliceFor(tab,6);
    wyswietlTablice(tab,6);
    return 0;
}