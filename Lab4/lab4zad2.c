#include <stdio.h>
#include <math.h>

int main()
{
    int n, bin, toOut;
    int wynik = 0;
    int *pBin = &bin;

    printf("Podaj liczbe binarna: ");
    scanf("%d", pBin);
    toOut = *pBin;
    n = log10(*pBin) / log10(2) + 1;
    printf("%d\n", n);

    for (int i = 0; i < n; i++)
    {
        int bit = *pBin % 10;
        wynik += bit * pow(2, i);
        *pBin /= 10;
    }
    printf("Liczba binarna %d w systemie dziesiętnym wynosi %d\n", toOut, wynik);

    return 0;
}