# Sistema de Administração de Consumo de Energia Elétrica

Sistema desenvolvido em C para gerenciar e monitorar o consumo de energia elétrica em uma estrutura hierárquica de cidade, bairros, ruas e casas.

## 📋 Descrição

Este projeto implementa um sistema de leitura e administração de consumo de energia elétrica utilizando Tipos Abstratos de Dados (TAD) e estruturas de dados encadeadas. O software processa comandos de um arquivo de entrada e gera um relatório detalhado das operações realizadas.

## 🎓 Contexto Acadêmico

**Instituição:** Universidade Federal do Espírito Santo (UFES)  
**Curso:** Ciência da Computação  
**Disciplina:** Estrutura de Dados I  
**Autores:** Leonardo Nascimento dos Santos e Vinícius Berger  
**Professor:** Thomas Walter Rauber  
**Ano:** 2015

## 🏗️ Estrutura do Sistema

O sistema organiza os dados em uma hierarquia de quatro níveis:

```
CIDADE
└── BAIRRO (id, nome)
    └── RUA (id, nome)
        └── CASA (id, número, consumo, nome do consumidor)
```

### Características das Estruturas

- **Cidade:** Lista encadeada de bairros
- **Bairro:** Contém id, nome e lista de ruas
- **Rua:** Contém id, nome e lista de casas
- **Casa:** Contém id, número, consumo acumulado e nome do consumidor

## 🚀 Funcionalidades

### Operações Administrativas

| Unidade | Operação | Parâmetros |
|---------|----------|------------|
| Bairro | Incluir | id do bairro, nome |
| Rua | Incluir | id do bairro, id da rua, nome |
| Rua | Eliminar | id do bairro, id da rua |
| Casa | Incluir | id do bairro, id da rua, id da casa, número, nome do consumidor |
| Casa | Eliminar | id do bairro, id da rua, id da casa |

### Operações de Medição

| Unidade | Operação | Parâmetros |
|---------|----------|------------|
| Casa | Registrar consumo | id do bairro, id da rua, id da casa, consumo |
| Casa | Medir consumo | id do bairro, id da rua, id da casa |
| Rua | Medir consumo | id do bairro, id da rua |
| Bairro | Medir consumo | id do bairro |
| Cidade | Medir consumo | - |

## 📁 Arquivos do Projeto

- `main.c` - Arquivo principal com interface do usuário
- `tad.c` - Implementação das estruturas e funções
- `tad.h` - Protótipos e definições
- `makefile` - Automação da compilação
- `teste.txt` - Arquivo de exemplo com comandos
- `documentacao.pdf` - Documentação completa do projeto

## 🔧 Compilação e Execução

### Compilar o projeto

```bash
make
```

Ou manualmente:

```bash
gcc -c tad.c
gcc -c main.c
gcc -o main tad.o main.o
```

### Executar o programa

```bash
./main
```

O programa solicitará o nome do arquivo de entrada. Digite o nome do arquivo (ex: `teste.txt`).

### Limpar arquivos objeto

```bash
make clean
```

## 📝 Formato do Arquivo de Entrada

O arquivo de entrada deve seguir a sintaxe:

```
<unidade> <ação> <parâmetros>
```

### Exemplos de Comandos

```
rua incluir 1 1 "Rua Steve Jobs"
casa incluir 1 1 3 4 "João Alfredo"
casa consumir 1 1 3 50.0
casa medir 1 1 3
rua medir 1 1
bairro medir 1
cidade medir
rua eliminar 2 2
casa eliminar 1 1 3
```

### Regras de Sintaxe

- Elementos separados por espaço ou tabulação
- Nomes entre aspas duplas
- IDs devem ser números inteiros não-negativos
- Consumo é um número decimal (float)

## 📤 Arquivo de Saída

O sistema gera automaticamente o arquivo `protocolo_saida.txt` contendo:

- Confirmações de operações bem-sucedidas
- Mensagens de erro detalhadas
- Valores de consumo medidos

### Exemplos de Saída

**Sucesso:**
```
Rua incluida com sucesso. Bairro id: 1 Rua id: 1 Rua nome: Rua Steve Jobs
Casa incluida com sucesso. Bairro id: 1 Rua id: 1 Casa id: 3 Casa nr: 4 Consumidor nome: João Alfredo
Consumo registrado com sucesso. Bairro id: 1 Rua id: 1 Casa id: 3 Consumo: 50.00
Medição da casa realizada com sucesso. Bairro id: 1 Rua id: 1 Casa id: 3 consumo: 50.00
```

**Erro:**
```
ERRO: Já existe uma rua com este id vinculada ao bairro. Bairro id: 1 Rua id: 1
ERRO: O id da rua não pode ser negativo. Bairro id: 1 Rua id: -2
ERRO: Bairro inexistente. Bairro id: 15
```

## ⚠️ Tratamento de Erros

O sistema valida e trata os seguintes erros:

- **Erro 11:** Rua não pertence ao bairro
- **Erro 12:** Casa não pertence à rua
- **Erro 13:** Rua com ID duplicado no bairro
- **Erro 14:** Casa com ID duplicado na rua
- **Erro 15:** Bairro inexistente
- **Erro 16:** ID de bairro negativo
- **Erro 17:** ID de rua negativo
- **Erro 18:** Ação inexistente
- **Erro 19:** Unidade inexistente
- **Erro 20:** Erro na abertura do arquivo
- **Erro 21:** Bairro com ID duplicado
- **Erro 22:** ID de casa negativo
- **Erro 23:** Número de casa negativo
- **Erro 24:** Consumo negativo
- **Erro 25:** Falha na alocação de memória

## 🧪 Validação e Testes

O projeto foi validado utilizando:

- **Valgrind:** Verificação de vazamento de memória
- **Casos de teste:** Arquivos com comandos válidos e inválidos
- **Testes de robustez:** Verificação de tratamento de erros

## 💡 Conceitos Implementados

- Tipos Abstratos de Dados (TAD)
- Listas encadeadas simples
- Alocação dinâmica de memória
- Encapsulamento de dados
- Ordenação por inserção (casas ordenadas por número)
- Tratamento robusto de erros

## 🛠️ Ferramentas Utilizadas

- **Linguagem:** C
- **Sistema Operacional:** Linux Mint
- **Compilador:** GCC (GNU Compiler Collection)
- **Depurador:** Valgrind
- **Editores:** Notepad++, Gedit
- **Bibliotecas:** stdio.h, stdlib.h, string.h

## 📚 Referências

CELES, Waldemar; CERQUEIRA, Renato; RANGEL, José Lucas. **Introdução a estruturas de dados: com técnicas de programação em C.** 11ª triagem. Rio de Janeiro: Elsevier, 2004.

## 📄 Licença

Projeto acadêmico desenvolvido para fins educacionais na UFES.

---

**Nota:** Os bairros 1, 2, 13 e 17 são inicializados automaticamente ao executar o programa.
