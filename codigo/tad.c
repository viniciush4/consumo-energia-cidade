// LEONARDO NASCIMENTO DOS SANTOS
// VINÍCIUS BERGER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

struct casa {
	int id, numeroCasa;
	float consumo;
	char nomeConsumidor[tamNome];
	tpCasa* prox;
}; 

struct rua {
	int id;
	char nome[tamNome];
	tpCasa* info;
	tpRua* prox;
}; 

struct bairro {
	int id;
	char nome[tamNome];
	tpRua* info;
	tpBairro* prox;
};

//FUNÇÕES PRINCIPAIS

int inserirBairro (int idBairro, char nome[tamNome])
{
	/*
	RETORNOS
	10 - Bairro incluido com sucesso
	21 - Ja existe um bairro com este id vinculado à cidade
	16 - O id do bairro não pode ser negativo
	25 - Erro de alocação de memória
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o bairro já existe (pelo id)
	tpBairro* resultadoBairro = buscaBairro (idBairro);
	
	if (resultadoBairro==NULL) // se não existe
	{
		// Aloca espaço
		tpBairro* novo = (tpBairro*) malloc(sizeof(tpBairro));
		
		// Verifica erro de alocação de memória
		if(novo==NULL)
		{
			return(25);
		}
		
		// Faz as atribuições
		novo->id = idBairro;
		strcpy (novo->nome, nome);
		
		// Encadeia o elemento
		novo->prox = Cidade;
		novo->info = NULL;
		Cidade = novo;
	
		return(10);
	}
	else
	{
		return(21);
	}
}

int inserirRua (int idBairro, int idRua, char nome[tamNome])
{
	/*
	RETORNOS
	1 - Rua incluida com sucesso
	13 - Já existe uma rua com este id vinculada a este bairro
	15 - Bairro inexistente
	16 - O id do bairro não pode ser negativo
	17 - O id da rua não pode ser negativo
	25 - Erro de alocação de memória
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(17);
	}
	
	// Procura o bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTE
	{
		// Verifica se a rua já existe
		tpRua* resultadoRua = buscaRua (idRua, resultadoBairro);
		
		if(resultadoRua==NULL) // se a rua NÃO EXISTE
		{
			// Aloca espaço
			tpRua* novo = (tpRua*) malloc(sizeof(tpRua));
			
			// Verifica erro de alocação de memória
			if(novo==NULL)
			{
				return(25);
			}
			
			// Faz as atribuições
			novo->id = idRua;
			strcpy (novo->nome, nome);
			novo->info = NULL;
	
			// Encadeia elemento
			novo->prox = resultadoBairro->info;
			
			resultadoBairro->info = novo;
			
			return(1);
		}
		else
		{
			return(13);
		}
	}
	else
	{
		return(15);
	}
}

int inserirCasa (int idBairro, int idRua, int idCasa, int numeroCasa, char nomeConsumidor[tamNome])
{
	/*
	RETORNOS
	7 - Casa incluida com sucesso
	14 - Ja existe uma casa com este id vinculada à rua
	11 - A rua informada não pertence ao bairro.
	15 - Bairro inexistente
	16 - O id do bairro não pode ser negativo
	17 - O id da rua não pode ser negativo
	22 - O id da casa não pode ser negativo
	23 - O numero da casa não pode ser negativo
	25 - Erro de alocação de memória
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(17);
	}
	
	// Verifica se o idCasa é positivo
	if(idCasa < 0)
	{
		return(22);
	}
	
	// Verifica se o numeroCasa é positivo
	if(numeroCasa < 0)
	{
		return(23);
	}
		
	// Procura o bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTE	
	{
		// Procura a Rua
		tpRua* resultadoRua = buscaRua(idRua, resultadoBairro);
		
		if(resultadoRua!=NULL) // se a rua EXISTE
		{
			// Verifica se a Casa já existe
			tpCasa* resultadoCasa = buscaCasa (idCasa, resultadoRua);
			
			if(resultadoCasa==NULL) // se a casa NÃO EXISTE
			{
				// Variáveis auxiliares
				tpCasa* ant = NULL;
				tpCasa* aux = resultadoRua->info;
	
				// Procura a posição de inserção
				while(aux!=NULL && aux->numeroCasa < numeroCasa)
				{
					ant = aux;
					aux = aux->prox;
				}
	
				// Aloca espaço
				tpCasa* novo = (tpCasa*) malloc(sizeof(tpCasa));
				
				// Verifica erro de alocação de memória
				if(novo==NULL)
				{
					return(25);
				}
				
				// Armazena valores	
				novo->id = idCasa;
				novo->numeroCasa = numeroCasa;
				novo->consumo = 0.00f;
				strcpy (novo->nomeConsumidor, nomeConsumidor);
	
				// Encadeia elemento
				if(ant==NULL) // insere elemento no início
				{
					novo->prox = resultadoRua->info;
					resultadoRua->info = novo;
				}
				else // insere elemento no meio
				{
					novo->prox = ant->prox;
					ant->prox = novo;
				}
				
				return(7);
			}
			else
			{
				return(14);
			}
		}
		else
		{
			return(11);
		}
	}
	else
	{
		return(15);
	}
}

int consumirCasa (int idBairro, int idRua, int idCasa, float consumo)
{
	/*
	RETORNOS
	9 - Consumo registrado com sucesso.
	11 - A rua informada não pertence ao bairro.
	12 - A casa informada não pertence à rua
	15 - Bairro inexistente
	16 - O id do bairro não pode ser negativo
	17 - O id da rua não pode ser negativo
	22 - O id da casa não pode ser negativo
	24 - O consumo não pode ser negativo
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(17);
	}
	
	// Verifica se o idCasa é positivo
	if(idCasa < 0)
	{
		return(22);
	}
	
	// Verifica se o consumo é positivo
	if(consumo < 0.00f)
	{
		return(24);
	}
		
	// Procura o bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTE	
	{
		// Procura a Rua
		tpRua* resultadoRua = buscaRua(idRua, resultadoBairro);
		
		if(resultadoRua!=NULL) // se a rua EXISTE
		{
			// Procura a casa
			tpCasa* resultadoCasa = buscaCasa (idCasa, resultadoRua);
			
			if(resultadoCasa!=NULL) // se a casa EXISTE
			{
				resultadoCasa->consumo += consumo;
				return(9);
			}
			else
			{
				return(12);
			}
		}
		else
		{
			return(11);
		}
	}
	else
	{
		return(15);
	}
}

float medirCasa (int idBairro, int idRua, int idCasa)
{
	/*
	RETORNOS
	O valor de consumo - Medição da casa realizada com sucesso
	-11.00 - A rua informada não pertence ao bairro
	-12.00 - A casa informada não pertence à rua
	-15.00 - Bairro inexistente
	-16.00 - O id do bairro não pode ser negativo
	-17.00 - O id da rua não pode ser negativo
	-22.00 - O id da casa não pode ser negativo
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(-16.00f);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(-17.00f);
	}
	
	// Verifica se o idCasa é positivo
	if(idCasa < 0)
	{
		return(-22.00f);
	}
	
	// Procura o bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTE	
	{
		// Procura a Rua
		tpRua* resultadoRua = buscaRua(idRua, resultadoBairro);
		
		if(resultadoRua!=NULL) // se a rua EXISTE
		{
			// Procura a casa
			tpCasa* resultadoCasa = buscaCasa (idCasa, resultadoRua);
			
			if(resultadoCasa!=NULL) // se a casa EXISTE
			{
				return(resultadoCasa->consumo);
			}
			else
			{
				return(-12.00f);
			}
		}
		else
		{
			return(-11.00f);
		}
	}
	else
	{
		return(-15.00f);
	}
}

float medirRua (int idBairro, int idRua)
{
	/*
	RETORNOS
	O valor do consumo - Medicao da rua realizada com sucesso
	-11.00 - A rua informada não pertence ao bairro
	-15.00 - Bairro inexistente
	-16.00 - O id do bairro não pode ser negativo
	-17.00 - O id da rua não pode ser negativo
	*/
	
	float aux = 0.00f;
	tpCasa* c;
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(-16.00f);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(-17.00f);
	}
	
	// Procura o Bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTIR
	{
		// Procura a Rua
		tpRua* resultadoRua = buscaRua(idRua, resultadoBairro);
	
		if(resultadoRua!=NULL) // se a rua EXISTIR
		{
			for(c=resultadoRua->info; c!=NULL; c=c->prox)
			{
				aux += c->consumo;
			}
	
			return(aux);
		}
		else
		{
			return(-11.00f);
		}
	}
	else
	{
		return(-15.00f);
	}
}

float medirBairro (int idBairro)
{
	/*
	RETORNOS
	O valor do consumo - Medição do bairro realizada com sucesso
	-15.00 - Bairro inexistente
	-16.00 - O id do bairro não pode ser negativo
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(-16.00f);
	}
	
	float aux = 0.00f;
	tpRua* r;
	tpCasa* c;
	
	// Procura o Bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISIR
	{
		// Ruas
		for(r=resultadoBairro->info; r!=NULL; r=r->prox)
		{
			// Casas
			for(c=r->info; c!=NULL; c=c->prox)
			{
				aux += c->consumo;
			}
		}
	
		return(aux);
	}
	else
	{
		return(-15.00);
	}
}


float medirCidade ()
{
	/*
	RETORNOS
	O valor do consumo - Medição da Cidade realizada com sucesso
	*/
	
	float aux = 0.00f;
	tpBairro* b;
	tpRua* r;
	tpCasa* c;
	
	// Bairros
	for(b=Cidade; b!=NULL; b=b->prox)
	{
		// Ruas
		for(r=b->info; r!=NULL; r=r->prox)
		{
			// Casas
			for(c=r->info; c!=NULL; c=c->prox)
			{
				aux += c->consumo;
			}
		}
	}
	
	return(aux);
}

int removerCasa (int idBairro, int idRua, int idCasa)
{
	/*
	RETORNOS
	8 - Casa removida com sucesso
	11 - A rua informada não pertence ao bairro
	12 - A casa informada não pertence à rua
	15 - Bairro inexistente
	16 - O id do bairro não pode ser negativo
	17 - O id da rua não pode ser negativo
	22 - O id da casa não pode ser negativo
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(17);
	}
	
	// Verifica se o idCasa é positivo
	if(idCasa < 0)
	{
		return(22);
	}
	
	// Procura o Bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTE
	{
		// Procura a Rua
		tpRua* resultadoRua = buscaRua(idRua, resultadoBairro);
		
		if(resultadoRua!=NULL) // se a rua EXISTE
		{
			tpCasa* ant = NULL;
			tpCasa* aux = resultadoRua->info;
	
			// Procura elemento e guarda o anterior
			while (aux!=NULL && aux->id!=idCasa)
			{
				ant = aux;
				aux = aux->prox;
			}
	
			// Verifica se achou o elemento
			if (aux == NULL)
				return (12); 
	
			// Retira o elemento
			if (ant == NULL)
			{
				// Retira o elemento do início
				resultadoRua->info = aux->prox;
			}
			else
			{
				// Retira o elemento do meio da lista
				ant->prox = aux->prox;
			}
	
			free(aux);
			return (8);
		}
		else
		{
			return(11);
		}
	}
	else
	{
		return(15);
	}
		
}

int removerRua (int idBairro, int idRua)
{
	/*
	RETORNOS
	2 - Rua removida com sucesso
	11 - A rua informada não pertence ao bairro
	15 - Bairro inexistente
	16 - O id do bairro não pode ser negativo
	17 - O id da rua não pode ser negativo
	*/
	
	// Verifica se o idBairro é positivo
	if(idBairro < 0)
	{
		return(16);
	}
	
	// Verifica se o idRua é positivo
	if(idRua < 0)
	{
		return(17);
	}
	
	// Procura o Bairro
	tpBairro* resultadoBairro = buscaBairro(idBairro);
	
	if(resultadoBairro!=NULL) // se o bairro EXISTIR
	{
		tpRua* ant = NULL;                  // ant é o ponteiro para o nó anterior ao que queremos remover
		tpRua* aux = resultadoBairro->info; // aux é o ponteiro para o nó que queremos remover
	
		// Procura elemento e guarda o anterior
		while (aux!=NULL && aux->id!=idRua)
		{
			ant = aux;
			aux = aux->prox;
		}
	
		// Verifica se achou o elemento
		if (aux == NULL)
			return (11);
	
		//Remove todas as casas da rua
		removerTodasAsCasasDaRua (aux);
	
		// Retira o elemento
		if (ant == NULL)
		{			
			// Retira o elemento do início	
			resultadoBairro->info = aux->prox;
		}
		else
		{
			// Retira o elemento do meio da lista
			ant->prox = aux->prox;
		}
	
		free(aux);
		return (2);
	}
	else
	{
		return(15);
	}	
}


// FUNÇÕES AUXILIARES
void removerTodosOsBairrosDaCidade ()
{
	tpBairro* aux = Cidade;
	
	while(aux!=NULL)
	{
		tpBairro* aux2 = aux->prox; // guarda ref. prox elemento
		removerTodasAsRuasDoBairro (aux);
		free(aux);                // libera mem. apontada por aux
		aux = aux2;                // faz apontar para o prox
	}		
}

void removerTodasAsRuasDoBairro (tpBairro* b)
{
	tpBairro* aux = b;
	
	while(aux->info!=NULL)
	{
		tpRua* aux2 = aux->info->prox; // guarda ref. prox elemento
		removerTodasAsCasasDaRua (aux->info);
		free(aux->info);               // libera mem. apontada por aux
		aux->info = aux2;              // faz apontar para o prox
	}
	
}

void removerTodasAsCasasDaRua (tpRua* r)
{
	tpRua* aux = r;
	
	while(aux->info!=NULL)
	{
		tpCasa* aux2 = aux->info->prox; // guarda ref. prox elemento
		free(aux->info);               // libera mem. apontada por aux
		aux->info = aux2;              // faz apontar para o prox
	}
}


tpBairro* buscaBairro (int idBairro)
{
	tpBairro* aux;
	
	for(aux=Cidade; aux!=NULL; aux=aux->prox)
	{
		if(aux->id == idBairro)
			return(aux);
	}
	return NULL;
}

tpRua* buscaRua (int idRua, tpBairro* resultadoBairro)
{
	tpRua* aux;
	
	for(aux=resultadoBairro->info; aux!=NULL; aux=aux->prox)
	{
		if(aux->id == idRua)
			return(aux);
	}
	return NULL;
}

tpCasa* buscaCasa (int idCasa, tpRua* resultadoRua)
{
	tpCasa* aux;
	
	for(aux=resultadoRua->info; aux!=NULL; aux=aux->prox)
	{
		if(aux->id == idCasa)
			return(aux);
	}
	return NULL;
}	

void lerArquivo(char nomeArquivo[tamNome])
{
	char tipo[tamNome], acao[tamNome], nome[tamNome], nomeConsumidor[tamNome];
	int idBairro, idRua, idCasa, numeroCasa, auxInt;
	float consumo, auxFloat;


	FILE* arq;
	FILE* arq2;
	arq = fopen(nomeArquivo,"r");
	arq2 = fopen("protocolo_saida.txt", "w");
	
	if(arq == NULL)
	{
		erro20
		exit (0);
	}
	
	while (fscanf(arq,"%s",tipo) != EOF)
	{
		if(strcmp(tipo,"rua") == 0)
		{
			fscanf(arq,"%s",acao);
			
			if(strcmp(acao,"incluir") == 0)
			{
				fscanf (arq,"%d %d %[^\n]",&idBairro ,&idRua, nome);
				
				// executar função
				auxInt = inserirRua (idBairro, idRua, nome);
				
				// escrever no arquivo
				switch(auxInt)
				{
					case 1: sucesso1 break;
					case 13: erro13 break;
					case 15: erro15 break;
					case 16: erro16 break;
					case 17: erro17 break;
					case 25: erro25 break;
				}					
			}
			else
			{
				if(strcmp(acao,"eliminar") == 0)
				{
					fscanf (arq,"%d %d",&idBairro ,&idRua);

					// executar função
					auxInt = removerRua (idBairro, idRua);
					
					// escrever no arquivo
					switch(auxInt)
					{
						case 2: sucesso2 break;
						case 11: erro11 break;
						case 15: erro15 break;
						case 16: erro16 break;
						case 17: erro17 break;
					}					
				}
				else
				{
					if(strcmp(acao,"medir") == 0)
					{
						fscanf (arq,"%d %d",&idBairro ,&idRua);
						
						// executar função
						auxFloat = medirRua (idBairro, idRua);
						
						// escrever no arquivo
						if(auxFloat==(-11.00f))
						{
							erro11
						}
						else
						{
							if(auxFloat==(-15.00f))
							{
								erro15
							}
							else
							{
								if(auxFloat==(-16.00f))
								{
									erro16
								}
								else
								{
									if(auxFloat==(-17.00f))
									{
										erro17
									}
									else
									{
										sucesso5
									}
								}
							}
						}	
					}
					else
					{
						erro18
						fscanf (arq," %[^\n]", acao); // lê o restante da linha
					}
				}
			}
		}
		else
		{
			if(strcmp(tipo,"casa") == 0)
			{
				fscanf(arq,"%s",acao);
				
				if(strcmp(acao,"incluir") == 0)
				{
					fscanf (arq,"%d %d %d %d %[^\n]",&idBairro, &idRua, &idCasa, &numeroCasa, nomeConsumidor);
					
					// executar função
					auxInt = inserirCasa (idBairro, idRua, idCasa, numeroCasa, nomeConsumidor);
					
					// escrever no arquivo
					switch(auxInt)
					{
						case 7: sucesso7 break;
						case 14: erro14 break;
						case 11: erro11 break;
						case 15: erro15 break;
						case 16: erro16 break;
						case 17: erro17 break;
						case 22: erro22 break;
						case 23: erro23 break;
						case 25: erro25 break;
					}
				}
				else
				{
					if(strcmp(acao,"eliminar") == 0)
					{		
						fscanf (arq,"%d %d %d",&idBairro, &idRua, &idCasa);
						
						// executar função
						auxInt = removerCasa (idBairro, idRua, idCasa);
						
						// escrever no arquivo
						switch(auxInt)
						{
							case 8: sucesso8 break;
							case 11: erro11 break;
							case 12: erro12 break;
							case 15: erro15 break;
							case 16: erro16 break;
							case 17: erro17 break;
							case 22: erro22 break;
						}
					}
					else
					{
						if(strcmp(acao,"consumir") == 0)
						{
							fscanf (arq,"%d %d %d %f",&idBairro, &idRua, &idCasa, &consumo);
							
							// executar função
							auxInt = consumirCasa (idBairro, idRua, idCasa, consumo);
																		
							// escrever no arquivo
							switch(auxInt)
							{
								case 9: sucesso9 break;
								case 11: erro11 break;
								case 12: erro12 break;
								case 15: erro15 break;
								case 16: erro16 break;
								case 17: erro17 break;
								case 22: erro22 break;
								case 24: erro24 break;
							}
						}
						else
						{
							if(strcmp(acao,"medir") == 0)
							{
								fscanf (arq,"%d %d %d",&idBairro, &idRua, &idCasa);
								
								// executar função
								auxFloat = medirCasa (idBairro, idRua, idCasa);
								
								// escrever no arquivo
								if(auxFloat==(-11.00f))
								{
									erro11
								}
								else
								{
									if(auxFloat==(-12.00f))
									{
										erro12
									}
									else
									{
										if(auxFloat==(-15.00f))
										{
											erro15
										}
										else
										{
											if(auxFloat==(-16.00f))
											{
												erro16
											}
											else
											{
												if(auxFloat==(-17.00f))
												{
													erro17
												}
												else
												{
													if(auxFloat==(-22.00f))
													{
														erro22
													}
													else
													{
														sucesso6
													}
												}
											}
										}
									}
								}
							}
							else
							{
								erro18
								fscanf (arq," %[^\n]", acao); // lê o restante da linha
							}
						}
					}
				}
			}
			else
			{
				if(strcmp(tipo,"bairro") == 0)
				{
					fscanf(arq,"%s",acao);
						
					if(strcmp(acao,"medir") == 0)
					{
						fscanf (arq,"%d",&idBairro);

							// executar função
							auxFloat = medirBairro (idBairro);
							
							// escrever no arquivo
							if(auxFloat==(-15.00f))
							{
								erro15
							}
							else
							{
								if(auxFloat==(-16.00f))
								{
									erro16
								}
								else
								{
									sucesso4
								}
							}
					}
					else
					{
						if(strcmp(acao,"incluir") == 0)
						{
							fscanf (arq,"%d %[^\n]", &idBairro, nome);
							
							//executar função
							auxInt = inserirBairro (idBairro, nome);
							
							//escrever no arquivo
							switch(auxInt)
							{
								case 10: sucesso10 break;
								case 21: erro21 break;
								case 16: erro16 break;
								case 25: erro25 break;
							}
						}
						else
						{
							erro18
							fscanf (arq," %[^\n]", acao); // lê o restante da linha
						}
					}
				}
				else
				{
					if(strcmp(tipo,"cidade") == 0)
					{
						fscanf(arq,"%s",acao);
						
						if(strcmp(acao,"medir") == 0)
						{
							// executar função
							auxFloat = medirCidade ();
							
							// escrever no arquivo
							sucesso3
						}
						else
						{
							erro18
							fscanf (arq," %[^\n]", acao); // lê o restante da linha
						}
							
					}
					else
					{
						erro19
						fscanf (arq," %[^\n]", acao); // lê o restante da linha
						
					}
							
				}
			}
		}				
	}
	
	fclose(arq2);
	fclose(arq);
	printf("Protocolo de saída gerado com sucesso.\n");
}

