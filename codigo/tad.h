// LEONARDO NASCIMENTO DOS SANTOS
// VINÍCIUS BERGER

typedef struct casa tpCasa;
typedef struct rua tpRua;
typedef struct bairro tpBairro;

#define tamNome 31

// PROTOCOLOS DE SAÍDA: SUCESSO
#define sucesso1 fprintf(arq2, "Rua incluida com sucesso. Bairro id: %d Rua id: %d Rua nome: %s\n", idBairro, idRua, nome);
#define sucesso2 fprintf(arq2, "Rua removida com sucesso. Bairro id: %d Rua id: %d\n", idBairro, idRua);
#define sucesso3 fprintf(arq2, "Medição da Cidade realizada com sucesso. Consumo: %.2f\n", auxFloat);
#define sucesso4 fprintf(arq2, "Medição do bairro realizada com sucesso. Bairro id: %d consumo: %.2f\n", idBairro, auxFloat);
#define sucesso5 fprintf(arq2, "Medicao da rua realizada com sucesso. Bairro id: %d Rua id: %d consumo: %.2f\n", idBairro, idRua, auxFloat);
#define sucesso6 fprintf(arq2, "Medição da casa realizada com sucesso. Bairro id: %d Rua id: %d Casa id: %d consumo: %.2f\n", idBairro, idRua, idCasa, auxFloat);
#define sucesso7 fprintf(arq2, "Casa incluida com sucesso. Bairro id: %d Rua id: %d Casa id: %d Casa nr: %d Consumidor nome: %s\n", idBairro, idRua, idCasa, numeroCasa, nomeConsumidor);
#define sucesso8 fprintf(arq2, "Casa removida com sucesso. Bairro id: %d Rua id: %d Casa id: %d\n", idBairro, idRua, idCasa);
#define sucesso9 fprintf(arq2, "Consumo registrado com sucesso. Bairro id: %d Rua id: %d Casa id: %d Consumo: %.2f\n", idBairro, idRua, idCasa, consumo);
#define sucesso10 fprintf(arq2, "Bairro incluido com sucesso. Bairro id: %d\n", idBairro);

// PROTOCOLOS DE SAÍDA: ERROS
#define erro11 fprintf(arq2, "ERRO: A rua informada não pertence ao bairro. Bairro id: %d Rua id: %d\n", idBairro, idRua);
#define erro12 fprintf(arq2, "ERRO: A casa informada não pertence à rua. Bairro id: %d Rua id: %d Casa id: %d\n", idBairro, idRua, idCasa);
#define erro13 fprintf(arq2, "ERRO: Ja existe uma rua com este id vinculada ao bairro. Bairro id: %d Rua id: %d\n", idBairro, idRua);
#define erro14 fprintf(arq2, "ERRO: Ja existe uma casa com este id vinculada à rua. Bairro id: %d Rua id: %d Casa id: %d\n", idBairro, idRua, idCasa);
#define erro15 fprintf(arq2, "ERRO: Bairro inexistente. Bairro id: %d\n", idBairro);
#define erro16 fprintf(arq2, "ERRO: O id do bairro não pode ser negativo. Bairro id: %d\n", idBairro);
#define erro17 fprintf(arq2, "ERRO: O id da rua não pode ser negativo. Bairro id: %d Rua id: %d\n", idBairro, idRua);
#define erro18 fprintf(arq2, "ERRO: Acao inexistente.\n");
#define erro19 fprintf(arq2, "ERRO: Unidade inexistente.\n");
#define erro20 printf("Erro na abertura do arquivo.\n");
#define erro21 fprintf(arq2, "ERRO: Ja existe um bairro com este id vinculado à cidade. Bairro id: %d\n", idBairro);
#define erro22 fprintf(arq2, "ERRO: O id da casa não pode ser negativo. Bairro id: %d Rua id: %d Casa id: %d\n", idBairro, idRua, idCasa);
#define erro23 fprintf(arq2, "ERRO: O numero da casa não pode ser negativo. Bairro id: %d Rua id: %d Casa id: %d Nr Casa: %d\n", idBairro, idRua, idCasa, numeroCasa);
#define erro24 fprintf(arq2, "ERRO: O consumo não pode ser negativo. Bairro id: %d Rua id: %d Casa id: %d Consumo: %.2f\n", idBairro, idRua, idCasa, consumo);
#define erro25 fprintf(arq2, "ERRO: Nao foi possível alocar memória. Programa abortado.\n");

// DECLARA A CIDADE
tpBairro* Cidade;

// CIDADE
float medirCidade ();
void removerTodosOsBairrosDaCidade ();

// BAIRRO
int inserirBairro (int idBairro, char nome[tamNome]);
float medirBairro (int idBairro);
tpBairro* buscaBairro (int idBairro);
void removerTodasAsRuasDoBairro (tpBairro* b);

// RUA
int inserirRua (int idBairro, int idRua, char nome[tamNome]);
float medirRua (int idBairro, int idRua);
int removerRua (int idBairro, int idRua);
tpRua* buscaRua (int idRua, tpBairro* resultadoBairro);
void removerTodasAsCasasDaRua (tpRua* r);

// CASA
int inserirCasa (int idBairro, int idRua, int idCasa, int numeroCasa, char nomeConsumidor[tamNome]);
int consumirCasa (int idBairro, int idRua, int idCasa, float consumo);
float medirCasa (int idBairro, int idRua, int idCasa);
int removerCasa (int idBairro, int idRua, int idCasa);
tpCasa* buscaCasa (int idCasa, tpRua* resultadoRua);

// AUXILIAR
void lerArquivo(char nomeArquivo[tamNome]);
