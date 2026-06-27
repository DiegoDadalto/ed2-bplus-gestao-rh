// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct filiacao {
    char nomeMae[500];
    char nomePai[500];
} Filiacao;

typedef struct endereco {
    char rua[50];
    int numeroCasa;
    char bairro[50];
    char cidade[50];
    char estado[50];
} Endereco;

typedef struct contato {
    Endereco endereco;
    char telefone[20];
} Contato;

typedef struct contrato {
    Data dataContratacao;
    bool statusAtividade;
    Data dataDesligamento; // se aplicavel
} Contrato;

typedef struct pagamentos {
    char mes[10];
    double salario;
} Pagamento;

typedef struct funcionario {
    char nome[500];
    Data dataNascimento;
    Filiacao nomePais;
    Contato dadosContato;
    Contrato dadosContratuais;
    Pagamento historicoPagamento[12];
} Funcionario;

#endif