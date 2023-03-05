#include <stdio.h> //biblioteca padr�o de entradas e sa�das - respons�vel pela comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel pela aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca tipografia regional
#include <string.h> 
#include <time.h> //lida com data e hora

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int segundos = time(0); //semente rand - n� sempre muda
	srand(segundos);	
	
	//cabe�alho
	printf("********************************************\n\n");
	printf("* Seja bem-vindo ao Jogo de adivinha��es! *\n\n");
	printf("********************************************\n\n");
	printf("\nTente descobrir qual � o n�mero secreto!\n\n");
	
	//definindo as vari�veis
	
	int numerogrande = rand(); //torna o n�mero secreto, um n�mero aleat�rio
	
	int numerosecreto = numerogrande % 100; //sempre retorna um n�mero entre 0 e 99
	
	int chute;
		
	int tentativas = 1;
	
	double pontos = 1000; //pontua��o do jogo
	
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
			continue; //faz ir direto para o i++ - para execu��o desse trecho e deixa o for continuar os demais trechos
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
			printf("\n\n\nAh, que pena, voc� errou!\n\n");
			printf("\nVou te dar uma dica!\n");
			printf("\nO n�mero que voc� digitou � maior do que o n�mero secreto...\n"); 
		}
		else
		{
			printf("\n\n\nAh, que pena, voc� errou!\n\n");
			printf("\nVou te dar uma dica!\n");
			printf("\nO n�mero que voc� digitou � menor do que o n�mero secreto...\n");
		}
		
		tentativas++;
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2; //regra de pontua��o
		
		pontos = pontos - pontosperdidos;
	
	}
	
	printf("\n\nFim de jogo\n\n");
	printf("\n\nVoc� acertou em %d tentativas!\n\n", tentativas);
	printf("\n\nTotal de pontos: %.1f\n\n", pontos);
	
}
	
