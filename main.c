#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura dos produtos do estoque
struct Produto {
    int id;
    char nome[50];
    float preco;
    int quantidade;
};



void cadastrarProduto();
void listarProdutos();
void excluirProduto();
void salvarProdutoEmArquivo(FILE *hortifruti, struct Produto produto);

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gerenciamento de Produtos HORTIFRUTI LB ---\n");
        printf("1. Cadastrar Produto \n");
        printf("2. Listar Produtos \n");
        printf("3. Excluir Produto \n");
        printf("0. Sair do sistema\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                excluirProduto();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

// cadastrar produto
void cadastrarProduto() {
    struct Produto produto;
    FILE *hortifruti;

    hortifruti = fopen("produtos.txt", "a");
    if (hortifruti == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    printf("\n--- Cadastrar Produto no Estoque ---\n");
    printf("Digite o ID do produto: ");
    scanf("%d", &produto.id);
    printf("Nome do produto: ");
    scanf(" %[^\n]%*c", produto.nome);
    fflush(stdin);
    printf("Preco do produto: ");
    scanf("%f", &produto.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);

    salvarProdutoEmArquivo(hortifruti, produto);
    printf("Produto cadastrado com sucesso no HORTIFRUTI LB!\n");

    // fechar arquivo depois de salvo
    fclose(hortifruti);
}

// salvar produto no arquivo
void salvarProdutoEmArquivo(FILE *hortifruti, struct Produto produto) {
    fprintf(hortifruti, "%d %s %.2f %d\n", produto.id, produto.nome, produto.preco, produto.quantidade);
}

// listar produtos
void listarProdutos() {
    struct Produto produto;
    FILE *hortifruti;

    //arquivo em modo leitura 'r'
    hortifruti = fopen("produtos.txt", "r");
    if (hortifruti == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("\n--- Lista de Produtos do HORTIFRUTI LB ---\n");
    while (fscanf(hortifruti, "%d %49s %f %d", &produto.id, produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        printf("ID: %d | Nome: %s | Preco: R$%.2f | Quantidade: %d\n",
               produto.id, produto.nome, produto.preco, produto.quantidade);
    }

    // fechar arquivo depois da leitura
    fclose(hortifruti);
}

// excluir produto conforme o ID
void excluirProduto() {
    struct Produto produto;
    int id, encontrado = 0;
    FILE *hortifruti, *hortifrutiTemp;

    // abre arquivo em modo de leitura 'r'
    hortifruti = fopen("produtos.txt", "r");
    if (hortifruti == NULL) {
        printf("Erro ao abrir o arquivo original.\n");
        return;
    }

    hortifrutiTemp = fopen("temp.txt", "w");
    if (hortifrutiTemp == NULL) {
        printf("Erro ao criar o arquivo temporário!\n");
        fclose(hortifruti);
        return;
    }

    printf("\n--- Excluir Produto do Estoque ---\n");
    printf("Digite o ID do produto que deseja excluir do estoque: ");
    scanf("%d", &id);

    // le o arquivo original e copia para o temporário, menos o produto excluido
    while (fscanf(hortifruti, "%d %49s %f %d", &produto.id, produto.nome, &produto.preco, &produto.quantidade) != EOF) {
        if (produto.id == id) {
            printf("Produto com o ID %d (%s) excluído com sucesso.\n", produto.id, produto.nome);
            encontrado = 1;
        } else {
            fprintf(hortifrutiTemp, "%d %s %.2f %d\n", produto.id, produto.nome, produto.preco, produto.quantidade);
        }
    }

    // fecha os arquivos
    fclose(hortifruti);
    fclose(hortifrutiTemp);

    if (encontrado) {
        // remove o arquivo original e renomeia o temporario
        remove("produtos.txt");
        rename("temp.txt", "produtos.txt");
    } else {
        printf("Produto com ID %d não encontrado no estoque.\n");
        remove("temp.txt");
    }
}
