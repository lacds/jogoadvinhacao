#include <stdio.h> //biblioteca padrão de entradas e saídas - responsável pela comunicação com o usuário
#include <stdlib.h> //biblioteca responsável pela alocação de espaço e memória
#include <locale.h> //biblioteca tipografia regional
#include <string.h> 
#include <time.h> //lida com data e hora

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int segundos = time(0); //semente rand - nº sempre muda
	srand(segundos);	
	
	//cabeçalho
	printf("********************************************\n\n");
	printf("* Seja bem-vindo ao Jogo de adivinhações! *\n\n");
	printf("********************************************\n\n");
	printf("\nTente descobrir qual é o número secreto!\n\n");
	
	//definindo as variáveis
	
	int numerogrande = rand(); //torna o número secreto, um número aleatório
	
	int numerosecreto = numerogrande % 100; //sempre retorna um número entre 0 e 99
	
	int chute;
		
	int tentativas = 1;
	
	double pontos = 1000; //pontuação do jogo
	
	while(1)
	{
		setlocale(LC_ALL, "Portuguese");
			
		printf("\n\nTentativa %d\n\n", tentativas);
		printf("\nDigite seu chute: \n\n");
		scanf("%d", &chute);
		printf("\nSeu chute foi: %d", chute);
			
		if(chute<0)
		{
			printf("\n\nNúmeros negativos não valem! Tente novamente.\n");
			continue; //faz ir direto para o i++ - para execução desse trecho e deixa o for continuar os demais trechos
		}
			
		int acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
						
		if(acertou) 
		{
			printf("\n\nParabéns, você acertou!\n");
			printf("\n\nVocê é incrível!!!\n\n");
			
			break;
		}
		else if(maior)
		{
			printf("\n\n\nAh, que pena, você errou!\n\n");
			printf("\nVou te dar uma dica!\n");
			printf("\nO número que você digitou é maior do que o número secreto...\n"); 
		}
		else
		{
			printf("\n\n\nAh, que pena, você errou!\n\n");
			printf("\nVou te dar uma dica!\n");
			printf("\nO número que você digitou é menor do que o número secreto...\n");
		}
		
		tentativas++;
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2; //regra de pontuação
		
		pontos = pontos - pontosperdidos;
	
	}
	
	printf("\n\nFim de jogo\n\n");
	printf("\n\nVocê acertou em %d tentativas!\n\n", tentativas);
	printf("\n\nTotal de pontos: %.1f\n\n", pontos);
	
}
	
