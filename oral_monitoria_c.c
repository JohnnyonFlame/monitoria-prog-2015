#include <stdio.h>

int matriz[3][3] =
{
    [0 ... 2] = {-1, -1, -1}
};
int *vetor = &matriz[0][0];

void ler_dados(char *prompt, char *fmt, void *ptr);
void matriz_ler();
void matriz_print();
void vetor_ler();
void vetor_print();

int main(int argc, char *argv[])
{
    char cmd;

    do
    {
        system("cls");
        matriz_print();
        printf("\n");
        vetor_print();
        printf("\n");

        ler_dados("m) Muda valor via matriz\n"
                  "v) Muda valor via vetor\n"
                  "e) Sai do programa\n"
                  "Digite o comando: ", "%c", &cmd);

        printf("\n");

        switch(cmd)
        {
        case 'm':
            matriz_ler();
            break;
        case 'v':
            vetor_ler();
            break;
        case 'e':
            break;
        default:
            printf("Comando Invalido.\n");
            sleep(1);
            continue;
        }
    } while (cmd!='e');

    return 0;
}

void ler_dados(char *prompt, char *fmt, void *ptr)
{
    do
    {
        fflush(stdin);
        printf("%s", prompt);
    } while (!fscanf(stdin, fmt, ptr));
}

void matriz_ler()
{
    int i, j, v;

    ler_dados("Linha  [0..2]: ", "%i", &i);
    ler_dados("Coluna [0..2]: ", "%i", &j);

    if ((i<0) || (i>2) || (j<0) || (j>2))
    {
        printf("Linha ou Coluna invalido.\n");
        sleep(1);
        return;
    }

    ler_dados("Valor da posicao [0...99]: ", "%i", &v);
    if ((v<0) || (v>99))
    {
        printf("Valor invalido.\n");
        sleep(1);
        return;
    }

    matriz[i][j] = v;
}

void matriz_print()
{
    int i, j;

    printf("Representacao por matriz:\n");
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (matriz[i][j] > 0)
                printf("%02i ", matriz[i][j]);
            else
                printf( "xx ");
        }

        printf("\n");
    }
}

void vetor_ler()
{
    int i, v;
    ler_dados("Indice [0..2]: ", "%i", &i);

    if (i>8)
    {
        printf("Indice invalido.\n");
        sleep(1);
        return;
    }

    ler_dados("Valor da posicao [0...99]: ", "%i", &v);
    if ((v<0) || (v>99))
    {
        printf("Valor invalido.\n");
        sleep(1);
        return;
    }

    vetor[i] = v;
}

void vetor_print()
{
    int i;

    printf("Representacao por vetor:\n");
    for (i=0; i<9; i++)
    {
        if (vetor[i] > 0)
            printf("%02i ", vetor[i]);
        else
            printf( "xx ");
    }

    printf("\n");
}
