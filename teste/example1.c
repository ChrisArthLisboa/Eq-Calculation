#include "pbPlots.h"
#include <stdio.h>

int main() {

    double xl[8] = {1,2,3,4,5,6,7,8}; // Cria uma lista de valores x para seus pontos
    double yl[8] = {8,7,6,5,4,3,2,1}; // Cria uma lista de valores y para seus pontos

    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    /*
        RGBA = Dinamismo de cor (red | green | blue | alpha) alpha eh a transparencia.
        BitMap = um mapeamento de algo em bits.
        ImageReference cria uma referencia pra imagem.
    */

    StringReference ErrMsg[100];

    DrawScatterPlot(imageRef, 600, 400, xl, 8, yl, 8, ErrMsg);
    /*
        Nessa fun��o � desenhada um grafico de dispersao (algo assim, funciona como um gr�fico)
    */

    ByteArray *PNGData = ConvertToPNG(imageRef->image);
    /*
        Tipo Byte_Array, lista de bytes.
        A referencia do length, que guarda o tamanho da imagem
        e a imagem que esta guardada como um bitmap dentro da instancia de imageref
    */
    WriteToFile(PNGData, "plot.png");

    printf("Erro: %s\n", ErrMsg);

    return 0;

}
