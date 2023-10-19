#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>


float funcseg(float a, float b, float c, int resp){



    float delta = pow(b, 2) - (4*a*c); // delta recebe o valor da formula de acordo com os dados de entrada
    float x1 = (-b + sqrt(delta)) / (2*a); //x1
    float x2 = (-b - sqrt(delta)) / (2*a); // x2

    switch(resp){

    case 1:
        return delta;
    break;

    case 2:
        return x1;
    break;

    case 3:
        return x2;
    break;


    }


}

int main(){

    float A, B, C;
    int resposta;

    printf("\nFORMULA DE SEGUNDO GRAU --> \"ax^2 + bx + c\"");
    printf("\nFORMULA DE BHASKARA --> \"-b + ou - raiz(delta) / 2*a\"");

    printf("\nDigite o valor de A: [caso fracao, coloque o valor em decimal!]\n");
    scanf("\n%f", &A);
    printf("\nDigite o valor de B: [caso fracao, coloque o valor em decimal!]\n");
    scanf("\n%f", &B);
    printf("\nDigite o valor de C: [caso fracao, coloque o valor em decimal!]\n");
    scanf("\n%f", &C);

    printf("\nDigite o que quer consultar: ");
    printf("\n1 - Delta");
    printf("\n2 - X1");
    printf("\n3 - X2");
    printf("\n");
    scanf("\n%d", &resposta);

    printf("\n%2.f", funcseg(A, B, C, resposta));


    return 0;
}
