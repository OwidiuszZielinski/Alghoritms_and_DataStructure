#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float a;
    int b;
} klasa_lub_obiekt;
typedef struct wezel_z_wskazaniem_na_kolejny
{
    klasa_lub_obiekt dane;
    struct wezel_z_wskazaniem_na_kolejny *next;
} wezel_z_wskazaniem_na_kolejny;

typedef wezel_z_wskazaniem_na_kolejny *Kolejka;

Kolejka poczatek = NULL, koniec = NULL;

void dodajElement(Kolejka *pocz, Kolejka *kon, klasa_lub_obiekt x)
{
    Kolejka q;
    q = (wezel_z_wskazaniem_na_kolejny *)malloc(sizeof(wezel_z_wskazaniem_na_kolejny));
    q->dane = x;
    q->next = NULL;
    if ((*pocz) == NULL)
        (*pocz) = q;
    else
        (*kon)->next = q;
    (*kon) = q;
}
klasa_lub_obiekt nowyRekord()
{
    klasa_lub_obiekt x;
    printf("Wprowadz wartosc pola a: ");
    scanf("%f", &x.a);
    printf("Wprowadz wartosc pola b: ");
    scanf("%d", &x.b);
    return x;
}

void wyswietlKolejke(Kolejka pocz)
{
    while (pocz != NULL)
    {
        wyswietlRekord(pocz->dane);
        pocz = pocz->next;
    }
}
void wyswietlRekord(klasa_lub_obiekt x)
{
    printf("%6.1f %3d\n", x.a, x.b);
}

int main()
{
    klasa_lub_obiekt d = nowyRekord();
    dodajElement(&poczatek, &koniec, d);
    wyswietlKolejke(&poczatek);
    return 0;
}