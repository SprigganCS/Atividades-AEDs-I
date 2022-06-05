/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Percurso em matrizes
* Disciplina: AEDs I
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Andre Neves Medeiros
* Data......: 27/08/2020
*-------------------------------------------------------------*/
#include <stdio.h>
int main()
{
	int i, j, n, a, matriz[100][100], ordem[1000];
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &matriz[i][j]);
		}
	}
	//processamento
	ordem[0] = matriz[0][0];
	ordem[1] = matriz[0][1];
	ordem[2] = matriz[1][0];
	ordem[3] = matriz[2][0];
	i = 2;
	j = 0;
	a = 4;
	while (a < n * n - 1)
	{
		while (i > 0 && j < n - 1) //subir diagonal atÃ© i=0 ou j=n  //i=2 j=0 a=4
		{
			ordem[a] = matriz[i - 1][j + 1];
			i--, j++, a++; //i=0 j=2 a=6 //i=1 j=3 a=13
		}
		if ((j + 1) < n)  //condicional descer reto ou direita
		{
			ordem[a] = matriz[i][j + 1];
			j++; //j=3
		}
		else
		{
			ordem[a] = matriz[i + 1][j];
			i++; //i=1 para 3x3 //i=2
		}
		a++;
		//descer diagonal atÃ© i<n ou j<0 //para n=3, i=1 j=2 //i=2 j=3
		while (i < n - 1 && j>0)//para n=4, i=0 j=3 		
		{
			ordem[a] = matriz[i + 1][j - 1];
			i++, j--, a++; // i=3 j=0 a=10 //i=3 j=2 a=14
		}
		//condicional descer reto ou direita
		if ((i + 1) >= n)
		{
			ordem[a] = matriz[i][j + 1];
			j++; //1
		}
		else
		{
			ordem[a] = matriz[i + 1][j];
			i++;
		}
		ordem[(n * n - 1)] = matriz[(n - 1)][(n - 1)];
		a++;
	}
	for (i = 0; i < n * n; i++)
	{
		printf("%d ", ordem[i]);
	}

	return 0;
}

