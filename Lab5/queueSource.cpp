#include <iostream>
#include <cstring>
using namespace std;

#define ROZMIAR 25

struct moja_struktura
{
    int indeks;
    char nazwisko[ROZMIAR];
    char imie[ROZMIAR];
    int wiek;
    struct moja_struktura *nastepny;
};
struct wsk_moja_struktura
{
    struct moja_struktura *poczatek, *koniec;
};
/*
Funkcja przyjmuje cztery argumenty: wskaźnik do struktury wsk_moja_struktura o nazwie kolejka, do której ma zostać dodany element, wartość indeks, która określa, który element listy ma zostać dodany, oraz dwa łańcuchy znaków nazwisko i imie oraz wartość wiek, które są danymi dodawanego elementu.

Funkcja alokuje pamięć dla nowego elementu listy jednokierunkowej przy użyciu funkcji malloc i przypisuje wskaźnik do tego nowego elementu do zmiennej n_wsk.

Sprawdza, czy alokacja pamięci dla nowego elementu się powiodła, porównując wskaźnik n_wsk do wartości NULL przy użyciu operatora !=. Jeśli wartość wskaźnika nie jest równa NULL, to kontynuuje się działanie funkcji.

Ustawia wartości pól nowego elementu listy. Przypisuje wartość indeks do pola indeks, łańcuch nazwisko do pola nazwisko, łańcuch imie do pola imie, a wartość wiek do pola wiek. Pole nastepny ustawia na wartość NULL.

Sprawdza, czy początek listy jest równy NULL (co oznacza, że lista jest pusta).

Jeśli początek listy jest równy NULL, to przypisuje wskaźnik n_wsk zarówno do pola poczatek, jak i koniec w strukturze wsk_moja_struktura.

Jeśli początek listy nie jest równy NULL, to przypisuje wskaźnik n_wsk do pola nastepny ostatniego elementu listy (kolejka->koniec->nastepny = n_wsk) oraz ustawia wskaźnik koniec w strukturze wsk_moja_struktura na nowy element (kolejka->koniec = n_wsk).

Funkcja zwraca true, co oznacza, że nowy element został dodany do listy.

Jeśli alokacja pamięci się nie powiodła, funkcja zwraca false, co oznacza, że element nie został dodany do listy.
*/
bool dodaj(struct wsk_moja_struktura *kolejka, int indeks, const char *nazwisko, const char *imie, int wiek)
{
    struct moja_struktura *n_wsk = (struct moja_struktura *)
        malloc(sizeof(struct moja_struktura));
    if (NULL != n_wsk)
    {
        n_wsk->indeks = indeks;
        strcpy(n_wsk->nazwisko, nazwisko);
        strcpy(n_wsk->imie, imie);
        n_wsk->wiek = wiek;
        n_wsk->nastepny = NULL;
        if (NULL == kolejka->poczatek)
            kolejka->poczatek = kolejka->koniec = n_wsk;
        else
        {
            kolejka->koniec->nastepny = n_wsk;
            kolejka->koniec = n_wsk;
            return true;
        }
        return false;
    }
    return false;
}

moja_struktura pobierzDane()
{
    moja_struktura x;
    printf("Nazwisko: ");
    scanf("%s", x.nazwisko);
    printf("Imie: ");
    scanf("%s", x.imie);
    printf("Wiek: ");
    scanf("%d", &x.wiek);
    return x;
}
void interfejs(struct wsk_moja_struktura *kolejka)
{
    char z;
    moja_struktura x;
    int indeks = 1;
    printf("Czy chcesz dodac nowa osobe (T/N): ");
    do
    {
        z = toupper(getchar());
    } while (z != 'T' && z != 'N');
    printf("%c\n", z);
    if (z == 'N')
        return;
    do
    {
        scanf("%c", &z);
        x = pobierzDane();
        dodaj(kolejka, indeks, x.nazwisko, x.imie, x.wiek);
        indeks++;
        printf("Czy chcesz dodac nowa osobe (T/N): \n");
        do
        {
            z = toupper(getchar());
        } while (z != 'T' && z != 'N');
        printf("%c\n", z);
    } while (z != 'N');
}

/*Ten kod jest funkcją usuwającą element z listy jednokierunkowej w strukturze wsk_moja_struktura. Oto szczegółowy opis, co dzieje się w tej funkcji krok po kroku:

Funkcja przyjmuje dwa argumenty: wskaźnik do struktury wsk_moja_struktura o nazwie kolejka, która zawiera początek i koniec listy, oraz wartość indeks, która określa, który element listy ma zostać usunięty.

Funkcja tworzy wskaźnik current i przypisuje mu wartość początku listy (kolejka->poczatek). Tworzy także wskaźnik previous i ustawia go na NULL.

Tworzy zmienną i i ustawia ją na 1.

Uruchamia się pętla while, która działa dopóki current nie jest równy NULL i i jest mniejsze niż wartość indeks.

W każdej iteracji pętli, przypisuje wartość current do previous i przesuwa current na następny element w liście (current = current->nastepny). Zwiększa wartość i o 1.

Po wyjściu z pętli, funkcja sprawdza, czy current nie jest równy NULL.

Jeśli current nie jest równy NULL, to funkcja ustawia wskaźnik nastepny dla poprzedniego elementu na wartość nastepny dla aktualnego elementu (previous->nastepny = current->nastepny), co usuwa element z listy.

Następnie funkcja zwalnia pamięć, którą zajmował usuwany element (free(current)).

Funkcja sprawdza, czy nastepny dla poprzedniego elementu nie jest równy NULL (co oznacza, że usuwany element był ostatnim elementem na liście), a jeśli tak, to ustawia koniec listy na previous (kolejka->koniec = previous).

Funkcja zwraca true, jeśli element został usunięty, lub false, jeśli element o wartości indeks nie istnieje na liście.*/

bool usun(struct wsk_moja_struktura *kolejka, int indeks)
{
    moja_struktura *current = kolejka->poczatek;
    struct moja_struktura *previous = NULL;
    int i = 1;
    while (current != NULL && i < indeks)
    {
        previous = current;
        current = current->nastepny;
        i++;
    }
    if (current != NULL)
    {
        previous->nastepny = current->nastepny;
        free(current);
        if (previous->nastepny == NULL)
            kolejka->koniec = previous;
        return true;
    }
    return false;
}

void print_kolejka(struct wsk_moja_struktura kolejka)
{
    for (; NULL != kolejka.poczatek; kolejka.poczatek = kolejka.poczatek->nastepny)
        printf("(%d ,%s, %s, %d)", kolejka.poczatek->indeks, kolejka.poczatek->nazwisko, kolejka.poczatek->imie, kolejka.poczatek->wiek);
    printf("\n");
}

int main()
{
    int d;
    struct wsk_moja_struktura kolejka = {NULL, NULL};
    interfejs(&kolejka);
    print_kolejka(kolejka);
    printf("Element z ktorym indeksem chcesz usunac ?\n");
    scanf("%d", &d);
    usun(&kolejka, d);
    print_kolejka(kolejka);

    return 0;
}