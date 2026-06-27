// Diego Dadi Dadalto - 2024200492
// Júlia Passamani Aguiar Santos - 2024200495
// Sol Dias da Silva - 2024201600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bplus.h"
#include "funcionario.h"

// Julia
int main() {
    int opcao;
    printf("Informe a opcao desejada, de acordo com o menu abaixo:\n");
    printf("---------- MENU ----------\n");
    printf("1. Inserir Funcionario\n2. Buscar Funcionario\n3. Excluir Funcionario\n
            4. Listagem por Intervalo\n5. Exibir Estrutura do Indice\n6. Sair\n");
    scanf("%d", &opcao);
    do {
        switch (opcao) {
            case 1:
                // Inserir Funcionario
                char nome[500];
                Data dataNascimento;
                printf("Informe o nome completo do novo funcionario a ser inserido: ");
                scanf("%s", nome);
                printf("Agora, informe a data de nascimento do novo funcionario, no formato DDMMAAAA: ");
                // LER A DATA DE NASCIMENTO
                void *resultadoBusca = buscaBplus();
                int encontrado = (int)resultadoBusca[2];
                if (encontrado == 1) {
                    printf("Funcionario ja existente no sistema.\nSegue os dados completos do mesmo:\n");
                    exibeDadosFuncionario();
                    char atualizacao;
                    printf("Voce deseja realizar alguma atualização no registro desse funcionario? (Digite S para 'sim' ou N para 'não')\n");
                    scanf("%c", &atualizacao);
                    if (atualizacao == 'S') {
                        int tipoAtualizacao;
                        printf("Qual tipo de atualizacao voce desejar realizar? Escolha um numero de acordo com as opcoes abaixo\n");
                        printf("1. Nome\n2. Data de nascimento\n3. Filiacao\n4. Dados de contato\n5. Dados contratuais\n6. Historico de pagamentos\n7. Nao deseja mais realizar atualizacao\n");
                        do {
                            switch (tipoAtualizacao) {
                                // EFETUAR AS DEVIDAS ATUALIZACOES DE REGISTRO
                                case 1:

                                case 2:

                                case 3:

                                case 4:

                                case 5:

                                case 6:

                                case 7:
                                    
                                default:
                                    printf("Opcao invalida. Voce sera redirecionado(a) ao menu de opcoes de atualizacoes.\n");
                            }
                        } while (tipoAtualizacao != 1 && tipoAtualizacao != 2 && tipoAtualizacao != 3 && tipoAtualizacao != 4 && tipoAtualizacao != 5 && tipoAtualizacao != 6 && tipoAtualizacao != 7);
                    } else {
                        if (atualizacao == 'N') {
                            return;
                        }
                    }
                } else {
                    char nomeMae[500];
                    char nomePai[500];
                    char rua[50];
                    int numCasa;
                    char bairro[50];
                    char cidade[50];
                    char estado[50];
                    char telefone[20];
                    char dataContratacao[10];
                    // informacoes de filiacao
                    printf("Informe o nome completo da mae do funcionario a ser registrado: ");
                    scanf("%c", nomeMae);
                    printf("Informe o nome completo do pai do funcionario a ser registrado: ");
                    scanf("%c", nomePai);
                    // informacoes de endereco e contato
                    printf("Informe o nome da rua do funcionario a ser registrado: ");
                    scanf("%c", rua);
                    printf("Informe o numero da casa do funcionario a ser registrado: ");
                    scanf("%d", numCasa);
                    printf("Informe o bairro do funcionario a ser registrado: ");
                    scanf("%c", bairro);
                    printf("Informe a cidade do funcionario a ser registrado: ");
                    scanf("%c", cidade);
                    printf("Informe o estado do funcionario a ser registrado: ");
                    scanf("%c", estado);
                    printf("Informe o telefone do funcionario a ser registrado: ");
                    scanf("%c", telefone);
                    // informacoes contratuais
                    printf("Informe a data de contratacao do funcionario a ser registrado, no formato DDMMAAA: ");
                    scanf("%c", dataContratacao);
                    // status de atividade eh inicializada como ativo (?) e data de desliagmento é inicializada vazia
                    // o vetor de historico de pagamento eh inicializado aqui ou na funcao de inserir?
                    insereBplus();
                }

            case 2:
                // Buscar funcionario
                buscaBplus();

            case 3:
                // Excluir Funcionario
                removeBplus();

            case 4:
                // Listagem por Intervalo
                listagemIntervalo();

            case 5:
                // Exibir Estrutura do Indice
                imprimeBplus();

            case 6:
                // Sair
                liberaBplus();

            default:
                // Opcao invalida
                printf("Opcao invalida. Por favor, escolha uma opcao de acordo com o menu informado:\n");
                printf("---------- MENU ----------\n");
                printf("1. Inserir Funcionario\n2. Buscar Funcionario\n3. Excluir Funcionario\n
                4. Listagem por Intervalo\n5. Exibir Estrutura do Indice\n6. Sair\n");
                scanf("%d", &opcao);
            }
    } while (opcao != 6);
}