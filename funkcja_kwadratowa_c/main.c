#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,delta,x1,x2;
    puts("Podaj a,b,c do rozwiazania funkcji kwadratowej");
    scanf("%f %f %f",&a,&b,&c);
    if(a!=0){
        printf("Obliczamy delte \n");
        delta = (b*b) - 4 *a*c;
        printf("Delta wynosi %f\n",delta);
        if(delta == 0){
            printf("Rownanie ma tylko jedno miejsce zerowe \n");
            x1 = -(b/(2 *a));
            printf("x1 = %f\n",x1);
        }
        else if(delta>0){
                printf("Rownanie ma dwa miejsca zerowe\n");
                x1 = (-b-sqrt(delta))/2*a;
                x2 = (-b +sqrt(delta))/2*a;
                printf("x1 = %f a x2 = %f\n",x1,x2);
        }else{
                printf("Rownanie sprzeczne");
        }
    }
    return 0;
}
