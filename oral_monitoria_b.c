#include <stdio.h>
#include <math.h> //sqrtf

float matriz_lugares[10][2];

void ler_dados(char *prompt, char *fmt, void *ptr);
void lugares_inicia();
float lugares_calculaDistancia(int lugar_a, int lugar_b);

int main(int argc, char *argv[])
{
    lugares_inicia();

    int lugar_a, lugar_b;
    while(1)
    {
        system("cls");
        ler_dados("Digite o primeiro lugar: ", "%i", &lugar_a);
        ler_dados("Digite o segundo lugar:  ", "%i", &lugar_b);

        if ((lugar_a < 0) || (lugar_b < 0))
        {
            printf("Local negativo, abortando.\n");
            getc(stdin);
            break;
        }
        else if ((lugar_a >= 10) || (lugar_b >= 10))
        {
            printf("Local invalido preenchido.\n");
            continue;
        }

        system("cls");
        printf("\nDistancia entre %i e %i: %.2f\n", lugar_a, lugar_b, lugares_calculaDistancia(lugar_a, lugar_b));
    }
}

void ler_dados(char *prompt, char *fmt, void *ptr)
{
    do
    {
        fflush(stdin);
        printf("%s", prompt);
    } while (!fscanf(stdin, fmt, ptr));
}

void lugares_inicia()
{
    int i;
    for (i=0; i<10; i++)
    {
        system("cls");
        printf("Lugar %i\n", i);
        ler_dados("Digite posicao no eixo x: ", "%f", &(matriz_lugares[i][0]));
        ler_dados("Digite posicao no eixo y: ", "%f", &(matriz_lugares[i][1]));
    }
}

float lugares_calculaDistancia(int lugar_a, int lugar_b)
{
    float dx = matriz_lugares[lugar_a][0] - matriz_lugares[lugar_b][0],
          dy = matriz_lugares[lugar_a][1] - matriz_lugares[lugar_b][1];

    return sqrtf((dx*dx) + (dy*dy)); //sqrtf => Square Root (float) => Raiz Quadrada (float)
}
