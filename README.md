# MAPA (Linguagem e Técnicas de Programação)
**Disciplina**: Linguagem e Técnicas de Programação - Unicesumar

Este projeto é o Mapa de Disciplina da Unicesumar, com foco na linguagem C.

## Descrição
O código fornecido pela universidade apresenta uma série de funcionalidades e desafios relacionados a um sistema de votação em C. Abaixo estão os principais problemas identificados no código inicial, que foram abordados e corrigidos:

### Desafios Iniciais
1. **Validação de Número do Candidato**  
   - Quando um número inválido de candidato é digitado, o sistema deveria exibir a mensagem "Número de candidato inválido!". Esta validação não estava funcionando corretamente.
   
2. **Apuração de Votos**  
   - A função de apuração estava mostrando uma contagem incorreta dos votos para cada candidato.
   
3. **Percentual de Votos**  
   - A opção de emitir o percentual de votos apresentava valores errados, não calculando corretamente o percentual de votos de cada candidato.

4. **Funcionamento do Menu**  
   - O menu apresentava um comportamento inesperado: ao selecionar a opção 1, 2 ou 3, as subsequentes também eram executadas sem interrupção.

## Código Original
O código fornecido pela universidade pode ser acessado [aqui](https://github.com/Navelogic/MAPA-LINGUAGEM-E-TECNICAS-DE-PROGRAMA--O/blob/main/unicesumar.c).

## Soluções Implementadas

### Problema 1: Mensagem de "Número de candidato inválido"
O código já verifica se o número do candidato é válido, mas não estava mostrando a mensagem corretamente. Para resolver, corrigi o fluxo de retorno da função `votar`, garantindo que a mensagem seja exibida se o candidato não for encontrado.
```c
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
````
### Problema 2: Exibição incorreta da apuração de votos
Na função `apurarVotos`, o loop `for` começava com i = 1 em vez de i = 0, fazendo com que o primeiro candidato não fosse exibido corretamente.
```c
void apurarVotos(struct Candidato candidatos[], int totalCandidatos) {
    printf("\nResultado da apuração de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        printf("%s (Número %d): %d votos\n", candidatos[i].nome, candidatos[i].numero, candidatos[i].votos);
    }
}
````
### Problema 3: Percentual de votos incorreto
O cálculo do percentual de votos estava incorreto na função `percentualVotos`. Ajustei o cálculo para usar o número de votos do candidato dividido pelo total de votos, multiplicado por 100.
```c
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
````
### Problema 4: Execução das opções subsequentes no menu
A ausência de `break` após cada case no switch fazia com que as próximas opções fossem executadas em sequência. A adição dos break resolveu o problema :)
```c
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
````
## Código Corrigido Completo
O código completo, com todas as correções, pode ser acessado [aqui](https://github.com/Navelogic/MAPA-LINGUAGEM-E-TECNICAS-DE-PROGRAMA--O/blob/main/resposta.c).
