
# Programa de resolução de equações polinomiais de 1° e 2° grau.


## Para compilar use:  
`gcc main.c pbPlots.c supportLib.c -lm -o example1 -o main`

## Para executar use:  
`./main`

## Sumário:

### Funções:

- [1° grau](#1-grau):
  - [get1Y()](#get1y);
  - [get1X()](#get1x);

- [2° grau](#2-grau):
  - [get2Y()](#get2y);
  - [get2XD()](#get2xd);

### Structs:

- [Criadas](#criadas);
- [Usadas](#usadas).

### Bibliotecas externas:

- ["pbPlots.h"](#-pbplotsh-);
- ["supportLib.h"](#-supportlibh-);


## Funções:

### 1° grau:

#### get1Y():

- Como usar
    ```c
        float get1Y(float a, float b, float c, float x);
    ```
  
- Utilidade:  
    Retorna o valor de y para um x em uma equação de 1° grau.

#### get1X():

- Como usar
    ```c
        float get1X(float a, float b, float c, float y);
    ```
- Utilidade:  
    Retorna o valor de x para um y em uma equação de 1° grau.

### 2° grau:

#### get2Y():

- Como usar
    ```c
        float get2Y(float a, float b, float c, float x);
    ```
- Utilidade:  
  Retorna o valor de y para um x em uma equação de 2° grau.

#### get2XD():

- Como usar
    ```c
        struct Bhaskara get2XD(float a, float b, float c);
    ```
- Utilidade:  
  Retorna a estrutura [Bhaskara](#bhaskara) com os valores de `x1`, `x2` e `delta` de uma equação de 2° grau.

## Structs:

### Criadas:

#### Bhaskara:

```c
struct Bhaskara {
    float x1;
    float x2;
    float delta;
};
```
Essa estrutura foi criada para passar dados pela função de [get2XD()]().

### Usadas:

Foi utilizada a estrutura da biblioteca ["pbPlots.h"](), `RGBABitmapImageReference` para alocar dados em bits da imagem e salvá-las em um arquivo .png.

## Bibliotecas externas:

### ["pbPlots.h"]():

Essa biblioteca foi utilizada para gerar os gráficos das equações.  
_Fonte_: [InductiveComputerScience/pbPlots](https://github.com/InductiveComputerScience/pbPlots/tree/master/C).

__Funções utilizadas__:

- `CreateRGBABitmapImageReference()`;
- `DrawScatterPlot()`;
- `ConvertToPNG()`.

__Estruturas utilizadas__:

- `RGBABitmapImageReference`;
- `StringReference`;
- `ByteArray`.

### ["supportLib.h"]():

Biblioteca de suporte ao ["pbPlots.h"]().
_Fonte_: [InductiveComputerScience/pbPlots](https://github.com/InductiveComputerScience/pbPlots/tree/master/C).  

__Funções utilizadas__:

- `WriteToFile()`;
