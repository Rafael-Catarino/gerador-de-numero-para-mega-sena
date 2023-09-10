#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrNum[6];

void cabecalho()
{
    printf("--------------------------------\n");
    printf("-Sorteando Numeros da Mega Sena-\n");
    printf("--------------------------------\n");
}

void sorteandoNumeros()
{
	int i, f, sorteio;
    srand(time(NULL));
    for (i = 0; i < 6; i++)
    {
        sorteio = rand() % 100;
        while (sorteio >= 60 || sorteio == 0)
        {
            sorteio = rand() % 100;
        }
        if(i == 0)
        {
            arrNum[i] = sorteio;
        }
        for (f = 0; f < i; f++)        
		{
            if(arrNum[f] != sorteio)
            {
                arrNum[i] = sorteio;
            }
            else 
            {
                i--;
                break;
            }
        }
    }
}

void ordenaNumero()
{
	int i, j;
    int aux;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (arrNum[i] < arrNum[j])
            {
                aux = arrNum[i];
                arrNum[i] = arrNum[j];
                arrNum[j] = aux;
            }
        }
    }
}

void mostraNumeros()
{
	int j;
    for (j = 0; j < 6; j++)
    {
    	if (j== 5)
		{
    		 printf("%d", arrNum[j]);
		}
		else {
			printf("%d - ", arrNum[j]);
		}
    }
}

int main(void)
{
    system("cls");
    cabecalho();
    sorteandoNumeros();
    ordenaNumero();
    mostraNumeros();
    return 0;
}
