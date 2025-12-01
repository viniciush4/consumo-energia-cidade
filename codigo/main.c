// LEONARDO NASCIMENTO DOS SANTOS
// VINÍCIUS BERGER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

int main ()
{
	// Inicializa a cidade
	Cidade = NULL;
	
	// Interface do programa
	printf ("\t\t\t\t>>> Bem Vindo ao Programa <<<\n\n\t\t>>> Administracao de Leitura de Consumo de Energia Eletrica <<<\n\n");
		printf ("Para executar, digite o nome do arquivo de entrada.txt:\n");
	
	// Guarda o nome do arquivo de entrada
	char nomeArquivo[tamNome];
	scanf (" %[^\n]", nomeArquivo);

	// Insere os bairros
	inserirBairro(1,"Bairro Um");
	inserirBairro(2,"Bairro Dois");
	inserirBairro(13,"Bairro Treze");
	inserirBairro(17,"Bairro Dezessete");

	// Lê o arquivo de entrada e cria o protocolo de saída
	lerArquivo(nomeArquivo);
	
	// Libera todos os espaços alocados que porventura não foram liberados
	removerTodosOsBairrosDaCidade ();
	
	return (EXIT_SUCCESS);
}



