#include <stdio.h> //biblioteca padr�o de entradas e sa�das - respons�vel pela comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel pela aloca��o de espa�o e mem�ria
#include <locale.h> //biblioeca tipografia regional
#include <string.h> 

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	//cabe�alho
	printf("********************************************\n\n");
	printf("* Seja bem-vindo ao Jogo de adivinha��es! *\n\n");
	printf("********************************************\n\n");
	printf("\nTente descobrir qual � o n�mero secreto!\n\n");
	
	//definindo as vari�veis
	int numerosecreto = 42;
		
	int chute;
	
	int tentativas = 1;
	
	
	while(1)
	{
		setlocale(LC_ALL, "Portuguese");
			
		printf("\n\nTentativa %d\n\n", tentativas);
		printf("\nDigite seu chute: \n\n");
		scanf("%d", &chute);
		printf("\nSeu chute foi: %d", chute);
			
		if(chute<0)
		{
			printf("\n\nN�meros negativos n�o valem! Tente novamente.\n");
			continue; //continue faz ir direto para o i++ - para execu��o desse trecho e deixa o for continuar os demais trechos
		}
			
		int acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
						
		if(acertou) 
		{
			printf("\n\nParab�ns, voc� acertou!\n");
			printf("\n\nVoc� � incr�vel!!!\n\n");
			
			break;
		}
		else if(maior)
		{
			printf("\n\nAh, que pena, voc� errou!\n\n");
			system("cls"); 
			printf("\nVou te dar uma dica!\n");
			printf("\nO n�mero que voc� digitou � maior do que o n�mero secreto...\n"); 
		}
		else
		{
			printf("\n\nAh, que pena, voc� errou!\n\n");
			system("cls"); 
			printf("\nVou te dar uma dica!\n");
			printf("\nO n�mero que voc� digitou � menor do que o n�mero secreto...\n");
		}
		
		tentativas++;
		
	}
	
	printf("\n\nFim de jogo\n\n");
	printf("\n\nVoc� acertou em %d tentativas!\n\n", tentativas);
	
}
	
