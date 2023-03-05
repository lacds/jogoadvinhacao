#include <stdio.h> //biblioteca padrão de entradas e saídas - responsável pela comunicação com o usuário
#include <stdlib.h> //biblioteca responsável pela alocação de espaço e memória
#include <locale.h> //biblioteca tipografia regional
#include <string.h> 
#include <time.h> //lida com data e hora

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	//cabeçalho
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem-vindo(a) ao \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

  
	
	//definindo as variáveis
	int segundos = time(0); //semente rand - nº sempre muda
	srand(segundos);
	
	int numerogrande = rand(); //torna o número secreto, um número aleatório
	
	int numerosecreto = numerogrande % 100; //sempre retorna um número entre 0 e 99
	int chute;
	int tentativas = 1;
	double pontos = 1000; //pontuação do jogo
	
	int acertou = 0;
	
	int nivel; //Menu de nível
	printf("Em qual nível de dificuldade você quer jogar?\n\n");
	printf("\t1 - Fácil\n");
	printf("\t2 - Médio\n");
	printf("\t3 - Difícil\n"); 
	printf("\nNível desejado: "); 
	scanf("%d", &nivel);
	
	int numerodetentativas; //definindo nº de tentativas permitidas
	
	int i = 1;
	
	switch(nivel)
	{
		case 1:
		numerodetentativas = 12;
		break;
		
		case 2:
		numerodetentativas = 6;
		break;
		
		default:
		numerodetentativas = 3;	
	}

	for(i = 1; i <= numerodetentativas; i++)
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
			
		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
						
		if(acertou) 
		{
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
	
	printf("\n\n\n\nFim de jogo.\n\n");
		
	if(acertou) 
	{
		printf("\n\nParabéns, você ganhou!\n\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
		printf("\nVocê é incrível!!!\n\n");
		printf("\n\nVocê acertou em %d tentativas!\n\n", tentativas);
		printf("\n\nTotal de pontos: %.1f\n\n", pontos);
	}
	else
	{
		printf("\n\n\nAh, que pena, você perdeu!\n\n");
		
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
	    printf("\n\n");			
				
		printf("\nMas, não desista, tente novamente!\n\n\n");
		printf("\n\n");	
	}
		
}

	

	
