#include <stdio.h> //biblioteca padr�o de entradas e sa�das - respons�vel pela comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel pela aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca tipografia regional
#include <string.h> 
#include <time.h> //lida com data e hora

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	//cabe�alho
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem-vindo(a) ao \n");
    printf("     |_|_|nnnn nnnn|_|_|      Jogo de Adivinha��o!\n");
    printf("    |" "  |  |_|  |"  " |                         \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

  
	
	//definindo as vari�veis
	int segundos = time(0); //semente rand - n� sempre muda
	srand(segundos);
	
	int numerogrande = rand(); //torna o n�mero secreto, um n�mero aleat�rio
	
	int numerosecreto = numerogrande % 100; //sempre retorna um n�mero entre 0 e 99
	int chute;
	int tentativas = 1;
	double pontos = 1000; //pontua��o do jogo
	
	int acertou = 0;
	
	int nivel; //Menu de n�vel
	printf("Em qual n�vel de dificuldade voc� quer jogar?\n\n");
	printf("\t1 - F�cil\n");
	printf("\t2 - M�dio\n");
	printf("\t3 - Dif�cil\n"); 
	printf("\nN�vel desejado: "); 
	scanf("%d", &nivel);
	
	int numerodetentativas; //definindo n� de tentativas permitidas
	
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
			printf("\n\nN�meros negativos n�o valem! Tente novamente.\n");
			continue; //faz ir direto para o i++ - para execu��o desse trecho e deixa o for continuar os demais trechos
		}
			
		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
						
		if(acertou) 
		{
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
	
	printf("\n\n\n\nFim de jogo.\n\n");
		
	if(acertou) 
	{
		printf("\n\nParab�ns, voc� ganhou!\n\n\n");
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
		printf("\nVoc� � incr�vel!!!\n\n");
		printf("\n\nVoc� acertou em %d tentativas!\n\n", tentativas);
		printf("\n\nTotal de pontos: %.1f\n\n", pontos);
	}
	else
	{
		printf("\n\n\nAh, que pena, voc� perdeu!\n\n");
		
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
	    printf("\n\n");			
				
		printf("\nMas, n�o desista, tente novamente!\n\n\n");
		printf("\n\n");	
	}
		
}

	

	
