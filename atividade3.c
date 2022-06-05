/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Strings e funcoes
* Disciplina: AEDs I / Programacao Estruturada
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Andre Neves Medeiros
* Data......: 17/09/2020
*-------------------------------------------------------------*/
#include <stdio.h>

int tamanho(char *linha) 
{
 	int tamanho = 0;
    while( linha[tamanho] != '\0' ) 
	{	
    	tamanho++;
	}
    return tamanho;
}

int contaSubstring(char *substr, char *linha) 
{
	int i, j, encontrado, contador = 0;
    int substrTamanho, linhaTamanho;

	substrTamanho = tamanho(substr);
	linhaTamanho = tamanho(linha);

    for(i = 0; i <= linhaTamanho - substrTamanho; i++)
    {
        encontrado = 1;
        for(j = 0; j < substrTamanho; j++)
        {
            if(linha[i + j] != substr[j])
            {
                encontrado = 0;
                break;
            }
        }

        if(encontrado == 1)
        {
            contador++;
        }
    }

    return contador;
}

void reversa(char *linha) 
{
	int i, j;
	
	for(i = 0, j = tamanho(linha) - 1; i < j; i++, j--) 
	{
		char temp = linha[i];
		linha[i] = linha[j];
		linha[j] = temp;
	}
}

int main() 
{
	int conta, numLinha = 0 ;
	char linha[100], substring[20];
	fgets(substring, 18, stdin);
	substring[tamanho(substring) - 1] = 0;
	do 
	{
		fgets(linha, 98, stdin);
		linha[tamanho(linha) - 1] = 0;
		if (linha[0]) 
		{
			conta = contaSubstring(substring, linha);
			printf("\'% s\' ocorreu %d vez(es) na linha %d\n", substring, conta, ++numLinha);
			reversa(linha);
			printf("reversa = %s\n", linha);
		}
	} while (linha [0]);
}
