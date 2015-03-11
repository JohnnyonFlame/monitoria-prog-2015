#include <stdio.h>

int vetor_numeros[10];

void ler_dados(char *prompt, char *fmt, void *ptr);
void inicia_numeros();
int acha_maior();

int main(int argc, char *argv[])
{
    inicia_numeros();
    printf("\nO maior numero digitado foi: %i\n", acha_maior());

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

void inicia_numeros()
{
    int i;
    for (i=0; i<10; i++)
        ler_dados("Digite um numero: ", "%i", &vetor_numeros[i]);
}

int acha_maior()
{
    int ret = vetor_numeros[0];
    int i;

    for (i=1; i<10; i++)
    {
        if (vetor_numeros[i] > ret)
            ret = vetor_numeros[i];
    }

    return ret;
}
