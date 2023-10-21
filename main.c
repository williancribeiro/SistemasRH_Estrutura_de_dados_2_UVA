#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    char cargo[50];
    int idade;
    float salario;
    struct Funcionario* esquerda;
    struct Funcionario* direita;
} Funcionario;

Funcionario* criarFuncionario(char nome[], char cargo[], int idade, float salario) {
    Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
    strcpy(novoFuncionario->nome, nome);
    strcpy(novoFuncionario->cargo, cargo);
    novoFuncionario->idade = idade;
    novoFuncionario->salario = salario;
    novoFuncionario->esquerda = NULL;
    novoFuncionario->direita = NULL;
    return novoFuncionario;
}

Funcionario* inserirFuncionario(Funcionario* raiz, char nome[], char cargo[], int idade, float salario) {
    if (raiz == NULL) {
        return criarFuncionario(nome, cargo, idade, salario);
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao < 0) {
        raiz->esquerda = inserirFuncionario(raiz->esquerda, nome, cargo, idade, salario);
    } else if (comparacao > 0) {
        raiz->direita = inserirFuncionario(raiz->direita, nome, cargo, idade, salario);
    }else {
        printf("Funcionario com nome %s ja existe na arvore.\n", nome);
    }

    return raiz;
}

void consultarFuncionario(Funcionario* raiz, char nome[]) {
    if (raiz == NULL) {
        printf("Funcionario nao encontrado.\n");
        return;
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao < 0) {
        consultarFuncionario(raiz->esquerda, nome);
    } else if (comparacao > 0) {
        consultarFuncionario(raiz->direita, nome);
    } else {
        printf("Nome: %-20s\tCargo: %-20s\tIdade: %-3d\tSalario: %.2f\n", raiz->nome, raiz->cargo, raiz->idade, raiz->salario);
    }
}

Funcionario* consultarNome(Funcionario* raiz, char nome[]) {
    if (raiz == NULL) {
        return NULL;
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao < 0) {
        return consultarNome(raiz->esquerda, nome);
    } else if (comparacao > 0) {
        return consultarNome(raiz->direita, nome);
    } else {
        return raiz;
    }
}

void atualizarFuncionario(Funcionario* raiz, char nome[], char novoCargo[], int novaIdade, float novoSalario) {
    if (raiz == NULL) {
        printf("Funcionario nao encontrado.\n");
        return;
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao < 0) {
        atualizarFuncionario(raiz->esquerda, nome, novoCargo, novaIdade, novoSalario);
    } else if (comparacao > 0) {
        atualizarFuncionario(raiz->direita, nome, novoCargo, novaIdade, novoSalario);
    } else {
        strcpy(raiz->cargo, novoCargo);
        raiz->idade = novaIdade;
        raiz->salario = novoSalario;
        printf("Funcionario atualizado com sucesso.\n");
    }
}

void listarFuncionarios(Funcionario* raiz) {
    if (raiz == NULL) {
        return;
    }

    listarFuncionarios(raiz->esquerda);
    printf("Nome: %-20s\tCargo: %-20s\tIdade: %-3d\tSalario: %.2f\n", raiz->nome, raiz->cargo, raiz->idade, raiz->salario);

    listarFuncionarios(raiz->direita);
}

void encontrarFuncionariosComIdadeMaiorQue(Funcionario* raiz, int idade) {
    if (raiz == NULL) {
        return;
    }

    encontrarFuncionariosComIdadeMaiorQue(raiz->esquerda, idade);
    if (raiz->idade > idade) {
        printf("Nome: %-20s\tCargo: %-20s\tIdade: %-3d\tSalario: %.2f\n",
               raiz->nome, raiz->cargo, raiz->idade, raiz->salario);
    }
    encontrarFuncionariosComIdadeMaiorQue(raiz->direita, idade);
}

Funcionario* excluirFuncionario(Funcionario* raiz, char nome[]) {
    if (raiz == NULL) {
        printf("Funcionario nao encontrado.\n");
        return raiz;
    }

    int comparacao = strcmp(nome, raiz->nome);

    if (comparacao < 0) {
        raiz->esquerda = excluirFuncionario(raiz->esquerda, nome);
    } else if (comparacao > 0) {
        raiz->direita = excluirFuncionario(raiz->direita, nome);
    } else {
        // Achou o elemento a ser removido
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            // Caso 1: N� a ser exclu�do sem filhos
            printf("\nRemocao - caso 1 = %s\n\n", raiz->nome);
            free(raiz);
            raiz = NULL;
        } else if (raiz->esquerda == NULL || raiz->direita == NULL) {
            // Caso 2: N� a ser exclu�do com 1 filho
            printf("\nRemocao - caso 2 = %s\n\n", raiz->nome);
            Funcionario* temp = raiz;
            if (raiz->esquerda)
                raiz = raiz->esquerda;
            else
                raiz = raiz->direita;
            free(temp);
        } else {
            // Caso 3: N� a ser exclu�do com 2 filhos
            printf("\nRemocao - caso 3 = %s\n\n", raiz->nome);
            Funcionario* f = raiz->esquerda;
            while (f->direita)
                f = f->direita;
            char tempNome[50];  // Nova matriz tempor�ria para o nome
            strcpy(tempNome, raiz->nome);  // Copiar o nome atual para tempNome
            strcpy(raiz->nome, f->nome);  // Copiar o nome de f para raiz
            strcpy(f->nome, tempNome);  // Copiar o nome de tempNome para f
            raiz->esquerda = excluirFuncionario(raiz->esquerda, nome);
        }
    }
    return raiz;
}


void listarSalariosDecrescente(Funcionario* raiz) {
    if (raiz == NULL) {
        printf("Nenhum funcionario na arvore.\n");
        return;
    }

    float salarios[100];  // Supomos um m�ximo de 100 funcion�rios
    char nomes[100][50];  // Supomos um m�ximo de 100 funcion�rios com nomes de at� 50 caracteres
    char cargos[100][50]; // Supomos um m�ximo de 100 funcion�rios com cargos de at� 50 caracteres
    int totalFuncionarios = 0;

    coletarSalariosRecursivoComNomesECargos(raiz, salarios, nomes, cargos, &totalFuncionarios);

    if (totalFuncionarios > 1) {
        // Ordene os sal�rios em ordem decrescente usando o m�todo da bolha (bubble sort)
        for (int i = 0; i < totalFuncionarios - 1; i++) {
            for (int j = i + 1; j < totalFuncionarios; j++) {
                if (salarios[i] < salarios[j]) {
                    float tempSalario = salarios[i];
                    salarios[i] = salarios[j];
                    salarios[j] = tempSalario;

                    char tempNome[50];
                    strcpy(tempNome, nomes[i]);
                    strcpy(nomes[i], nomes[j]);
                    strcpy(nomes[j], tempNome);

                    char tempCargo[50];
                    strcpy(tempCargo, cargos[i]);
                    strcpy(cargos[i], cargos[j]);
                    strcpy(cargos[j], tempCargo);
                }
            }
        }
    }

    for (int i = 0; i < totalFuncionarios; i++) {
        printf("Nome: %-20s\tCargo: %-20s\tSalario: %.2f\n", nomes[i], cargos[i], salarios[i]);
    }
}

void coletarSalariosRecursivoComNomesECargos(Funcionario* raiz, float salarios[], char nomes[][50], char cargos[][50], int* totalFuncionarios) {
    if (raiz == NULL) {
        return;
    }

    coletarSalariosRecursivoComNomesECargos(raiz->esquerda, salarios, nomes, cargos, totalFuncionarios);

    salarios[*totalFuncionarios] = raiz->salario;
    strcpy(nomes[*totalFuncionarios], raiz->nome);
    strcpy(cargos[*totalFuncionarios], raiz->cargo);
    (*totalFuncionarios)++;

    coletarSalariosRecursivoComNomesECargos(raiz->direita, salarios, nomes, cargos, totalFuncionarios);
}


void imprimirMenu() {
    printf("\n#########################");
    printf("\n=-=-=-Sistemas RH:=-=-=-\n");
    printf("#########################\n\n");
    printf("1. Incluir Funcionario\n");
    printf("2. Consultar Funcionario\n");
    printf("3. Listar Idade Maior que um Valor\n");
    printf("4. Listar Todos os Funcionarios\n");
    printf("5. Excluir Funcionario\n");
    printf("6. Atualizar Funcionario\n");
    printf("7. Listar Maiores Salarios\n");
    printf("8. Sair\n");
}

int main() {
    Funcionario* raiz = NULL;

    raiz = inserirFuncionario(raiz, "Joao", "Gerente", 35, 3500.00);
    raiz = inserirFuncionario(raiz, "Paula", "Engenheiro", 28, 8000.50);
    raiz = inserirFuncionario(raiz, "Roberto", "Dev", 27, 4000.20);
    raiz = inserirFuncionario(raiz, "Ana", "Desenvolvedor", 27, 9000);
    raiz = inserirFuncionario(raiz, "Renata", "Medica", 30, 15000);
    raiz = inserirFuncionario(raiz, "Willian", "Analista JR", 27, 4000.20);
    raiz = inserirFuncionario(raiz, "Carlos", "Designer", 40, 4200.45);
    raiz = inserirFuncionario(raiz, "Luciana", "Contador", 32, 3200.30);
    raiz = inserirFuncionario(raiz, "Marcio", "Suporte", 38, 1500);
    raiz = inserirFuncionario(raiz, "Amanda", "Marketing", 29, 2000);



    int opcao;
    char nome[50];
    char cargo[50];
    char novoCargo[50];
    int idade;
    int novaIdade;
    float salario;
    float novoSalario;

    do {
        imprimirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do funcionario: ");
                scanf("%s", nome);
                printf("Digite o cargo do funcionario: ");
                scanf("%s", cargo);
                printf("Digite a idade do funcionario: ");
                scanf("%d", &idade);
                printf("Digite o salario do funcionario: ");
                scanf("%f", &salario);
                raiz = inserirFuncionario(raiz, nome, cargo, idade, salario);
                break;
            case 2:
                printf("Digite o nome do funcionario para consultar: ");
                scanf("%s", nome);
                consultarFuncionario(raiz, nome);
                break;
            case 3:
                printf("Digite a idade para encontrar funcionarios com idade maior que: ");
                scanf("%d", &idade);
                printf("Funcionarios com idade maior que %d:\n", idade);
                encontrarFuncionariosComIdadeMaiorQue(raiz, idade);
                break;
            case 4:
                printf("Lista de todos os funcionarios:\n");
                listarFuncionarios(raiz);
                break;
            case 5:
                printf("Digite o nome do funcionario para excluir: ");
                scanf("%s", nome);
                raiz = excluirFuncionario(raiz, nome);
                printf("Funcionario excluido com sucesso.\n");
                break;
            case 6:
                printf("Digite o nome do funcionario para atualizar: ");
                scanf("%s", nome);

                Funcionario* funcionario = consultarNome(raiz, nome);
                if (funcionario == NULL) {
                    printf("Funcionario nao encontrado.\n");
                } else {
                    char resposta;
                    char tempNome[50];
                    char tempCargo[50];
                    int tempIdade = funcionario->idade;
                    float tempSalario = funcionario->salario;

                    printf("Deseja atualizar o cargo? (s/n): ");
                    scanf(" %c", &resposta);
                    if (resposta == 's' || resposta == 'S') {
                        printf("Digite o novo cargo: ");
                        scanf(" %[^\n]", tempCargo);
                    } else {
                        strcpy(tempCargo, funcionario->cargo);
                    }

                    printf("Deseja atualizar a idade? (s/n): ");
                    scanf(" %c", &resposta);
                    if (resposta == 's' || resposta == 'S') {
                        printf("Digite a nova idade: ");
                        scanf("%d", &tempIdade);
                    }

                    printf("Deseja atualizar o salario? (s/n): ");
                    scanf(" %c", &resposta);
                    if (resposta == 's' || resposta == 'S') {
                        printf("Digite o novo salario: ");
                        scanf("%f", &tempSalario);
                    }

                    atualizarFuncionario(raiz, nome, tempCargo, tempIdade, tempSalario);
                }
                break;

            case 7:
                printf("Salarios mais altos:\n");
                listarSalariosDecrescente(raiz);
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
