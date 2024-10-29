#include <stdio.h>

struct Candidato {  
    int numero;
    char nome[50];
    int votos;
};

int votar(struct Candidato candidatos[], int totalCandidatos) {
    int voto;
    printf("Digite o número do candidato (1 a 99): ");
    scanf("%d", &voto);
    int encontrado = 0;
    for (int i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].numero == voto) {
            candidatos[i].votos++;
            encontrado = 1;
            printf("Voto computado para %s!\n", candidatos[i].nome);
            return 1;
        }
    }
    if (!encontrado) {
        printf("Número de candidato inválido!\n");
        return 0;
    }
    return 0;
}

void apurarVotos(struct Candidato candidatos[], int totalCandidatos) {
    printf("\nResultado da apuração de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) { 
        printf("%s (Número %d): %d votos\n", candidatos[i].nome, candidatos[i].numero, candidatos[i].votos);
    }
}

void percentualVotos(struct Candidato candidatos[], int totalCandidatos, int totalVotos) {
    if (totalVotos == 0) {
        printf("Nenhum voto computado ainda.\n");
        return;
    }
    printf("\nPercentual de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        float percentual = (float)candidatos[i].votos / totalVotos * 100; 
        printf("%s: %.2f%% dos votos\n", candidatos[i].nome, percentual);
    }
}

int main() {
    struct Candidato candidatos[3] = {{10, "João da Padaria", 0}, {20, "Maria da Farmácia", 0}, {30, "Zé do Gás", 0}};
    int opcao;
    int totalVotos = 0;
    int totalCandidatos = 3;
    
    do {
        printf("\nMenu de opções:\n");
        printf("1. Votar\n");
        printf("2. Apurar\n");
        printf("3. Emitir percentual de votos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                totalVotos += votar(candidatos, totalCandidatos);
                break; 
            case 2:
                apurarVotos(candidatos, totalCandidatos);
                break; 
            case 3:
                percentualVotos(candidatos, totalCandidatos, totalVotos);
                break;
            case 4:
                printf("Saindo...\n");
                break; 
            default:
                printf("Opção inválida!\n");
                break; 
        }
    } while (opcao != 4);

    return 0;
}