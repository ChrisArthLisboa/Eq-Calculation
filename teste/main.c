#include "pbPlots.h"
#include "supportLib.h"
#include <stdio.h>
#include <math.h>

#define listSize 30

struct Bhaskara {
    float x1;
    float x2;
    float delta;
};

float get1Y(float a, float b, float x) {
    return a*x + b;
}

float get1X(float a, float b, float y){
    float x=-b/a;
    return x-y;
}

float get2Y(float a, float b, float c, float x) {
    return a*pow(x, 2) + b*x + c;
}


struct Bhaskara get2XD(float a, float b, float c){

    float delta = pow(b, 2) + (-4*a*c);
    float x1 = (-b + sqrt(delta)) / (2*a);
    float x2 = (-b - sqrt(delta)) / (2*a);

    struct Bhaskara resp = {x1, x2, delta};

    return resp;
}

////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// Separation grade /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int main() {

    double x[listSize], y[listSize]; // Crio as listas que vão entrar na funcao
    int grau;


    printf("Voce quer uma equacao de 1 grau ou 2 grau: ");
    scanf("%d", &grau);

    switch (grau) {

        case 1: {
            // Primeiro grau:

            float a, b;
            printf("Digite o valor de a: ");
            scanf("%f", &a);
            printf("Digite o valor de b: ");
            scanf("%f", &b);

            x[0] = get1X(a, b, 0);

            for (int i = 1; i < listSize; i++) {

                x[i] = x[0] + i;
                y[i] = get1Y(a, b, x[i]);

            }

            /////////////////////////////////////////
            /////////////// Results /////////////////
            /////////////////////////////////////////

            printf("\nX: %f\n", x[0]);


            break;
        }

        case 2: {
            // Segundo grau

            float a, b, c;
            printf("Digite o valor de a: ");
            scanf("%f", &a);
            printf("Digite o valor de b: ");
            scanf("%f", &b);
            printf("Digite o valor de c: ");
            scanf("%f", &c);

            double verticeX = -b/(2*a);

            for (int i=listSize/2; i>0; i--) {
                x[listSize/2 - i] = verticeX - i;
                y[listSize/2 - i] = get2Y(a, b, c, x[listSize/2 - i]);
            }

            for (int i=0; i<listSize/2; i++) {
                x[i+listSize/2] = verticeX + i;
                y[i+listSize/2] = get2Y(a, b, c, x[i+listSize/2]);
            }

            /////////////////////////////////////////
            /////////////// Results /////////////////
            /////////////////////////////////////////

            printf("\n%.1f*x^2+%.1f*x+%.1f\n", a, b, c);

            printf("\nDelta: %.2f\n", get2XD(a, b, c).delta);
            printf("X1 | X2: %.2f | %.2f\n", get2XD(a, b, c).x1, get2XD(a, b, c).x2);
            printf("Vertice: (%.2f, %.2f)\n", verticeX, get2Y(a, b, c, verticeX));

            break;

        }

    }



    /*
     * Eu preciso colocar metade dos valores de x como x1 e a outra metade se for x2 se for de 2 grau
     */

////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// graph creation ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    /*
        RGBA = Dinamismo de cor (red | green | blue | alpha) alpha eh a transparencia.
        BitMap = um mapeamento de algo em bits.
        ImageReference cria uma referencia pra imagem.
    */

    StringReference ErrMsg[100];

    DrawScatterPlot(imageRef, 600, 400, x, listSize, y, listSize, ErrMsg);
    /*
        Nessa funcao eh desenhada um grafico de dispersao (algo assim, funciona como um grafico comum)
    */

    ByteArray *PNGData = ConvertToPNG(imageRef->image);
    /*
        Tipo Byte_Array, lista de bytes.
        A referencia do length, que guarda o tamanho da imagem
        e a imagem que esta guardada como um bitmap dentro da instancia de imageref
    */
    WriteToFile(PNGData, "plot.png");

    return 0;

}
