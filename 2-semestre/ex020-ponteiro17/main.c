#include <stdio.h>

void adicionarNum(int *array, int *size) {
    if(*size<8) {
        (*size)++;
        for(int i = 0; i<(*size); i++) {
            if(*(array+i) == -1) {
                printf("==> Digite o valor que deseja adicionar: ");
                scanf("%d", (array+i));
                break;
            }
        }
    } else {
        printf("[AVISO]: o array-list esta cheio.\n");
    }
}

void removerNum(int *array, int *size) {
    int numRemovido;
    int encontrado = 0;

    printf("Digite o numero que deseja remover: ");
    scanf("%d", &numRemovido);
    for(int i = 0; i<(*size); i++) {
        if((*array+i)==numRemovido) {
            encontrado = 1;
            *(array+i) = *(array+i+1);
            *(array+i+1) = -1;
            (*size)--;
            break;
        }
    }
    if((*size)==0) {
        printf("[ERRO]: array esta vazio.\n");
    }
    if(encontrado!=1) {
        printf("[ERRO]: valor nao encontrado.\n");
    }

    // int find;
    // if(*size > 0) {
    //     (*size)--;
    //     int numRemovido;
    //     printf("==> Digite o valor que deseja remover: ");
    //     scanf("%d", &numRemovido);

    //     if(*size==0) {
    //         *(array)=-1;
    //     } else {
    //         for(int i = 0; i<(*size); i++) {
    //             if(*(array+i) == numRemovido) {
    //                 *(array+i) = *(array+i+1);
    //                 *(array+i+1) = -1;
    //                 find = 1;
    //                 break;
    //             } else {
    //                 printf("[ERRO]: valor nao encontrado.\n");
    //             }
    //         }

    //         if(find!=1) {
    //             (*size)++;
    //         }
        // }
    // } else {
    //     printf("[ERRO]: nao existem numeros no array.\n");
    // }
}

void exibirArray(int *array, int *size) {
    printf("===> Array-list = [ ");
    for(int i = 0; i<(*size); i++) {
        printf("%d ", *(array+i));
    }
    printf("]\n\n");
}

int main() {
    int size = 8;
    int opcao = 0;
    int *arrayList = (int*) malloc(sizeof(int) * size);

    for(int i = 0; i<size; i++) {
        *(arrayList+i) = -1;
    }

    size = 0;

    do {
        printf("+======================================================+\n");
        printf("|                    MENU DE OPCOES                    |\n");
        printf("|------------------------------------------------------|\n");
        printf("|        1. Digite (1) para adicionar um numero        |\n");
        printf("|        2. Digite (2) para remover um numero          |\n");
        printf("|        3. Digite (3) para sair                       |\n");
        printf("|                                                      |\n");
        printf("+======================================================+\n");
        printf("=> Opcao: ");
        scanf("%d", &opcao);


        switch(opcao) {
        case 1: 
            adicionarNum(arrayList, &size);
            exibirArray(arrayList, &size);
            break;
        case 2:
            removerNum(arrayList, &size);
            exibirArray(arrayList, &size);
            break;
        case 3:
            printf("Fim do programa!");
            break;
        default:
            printf("[ERRO]: opcao invalida. Tente novamente.\n\n");
        }
    } while(opcao!=3);

    return 0;
}