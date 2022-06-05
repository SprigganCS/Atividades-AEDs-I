
/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Operacoes Bit a Bit
* Disciplina: AEDs I
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Andre Neves medeiros
* Data......: 01/09/2020
-------------------------------------------------------------*/
#include <stdio.h>
int main()
{
	unsigned char mask;
	int a, j, i, matriz[7][20];
	i = j = 0;
	scanf_s("%d", &a);	//leitura das matrízes quadradas ou não	//a=número de colunas
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < a; j++)
		{
			scanf_s("%d", &matriz[i][j]);
		}
	}
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < a; j++) //pra cada i, um j é comparado com os 8 valores de mask
		{
			for (mask = 0x80; mask; mask >>= 1)
			{
				printf("%c", matriz[i][j] & mask ? '∗' : ' ');
			}
		}
		printf("\n ");
	}
}
