#include <stdio.h>
#include <math.h>

int main() {
    
    float x, y, z;  
    float A, B, C, D;  
    float distance;  
    printf("Obliczanie odległości punktu od zadanej płaszczyzny wykonujemy przy użyciu wzoru kanonicznego : Ax + By + Cz + D = 0\n");

    printf("Podaj wspolrzedne punktu (x,y,z): \n");
    printf("Podaj x : \n");
    scanf("%f",&x);
    printf("Podaj y : \n");
    scanf("%f",&y);
    printf("Podaj z : \n");
    scanf("%f",&z);

    printf("Podaj wspolczynniki plaszczyzny (A,B,C,D): \n");
    printf("Podaj A : \n");
    scanf("%f",&A);
    printf("Podaj B : \n");
    scanf("%f",&B);
    printf("Podaj C : \n");
    scanf("%f",&C);
    printf("Podaj D : \n");
    scanf("%f",&D);
    distance = fabs(A*x + B*y + C*z + D) / sqrtf(A*A + B*B + C*C);
    printf("Odleglosc punktu wynosi : %f\n", distance);
    return 0;
}





