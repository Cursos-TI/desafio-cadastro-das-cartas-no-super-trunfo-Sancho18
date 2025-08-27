/*
 * Desafio Super Trunfo - Países (Cadastro)
 * Criado por: Vinícius
*/

#include <stdio.h>

// Estrutura para os dados da Carta (Nível Novato)
struct CartaNovato {
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Estrutura para os dados da Carta (Níveis Aventureiro e Mestre)
struct CartaMestre {
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
};

// --- Protótipos ---
void nivelNovato();
void nivelAventureiro();
void nivelMestre();


int main() {
    printf("======================================\n");
    printf("   DESAFIO SUPER TRUNFO - CADASTRO\n");
    printf("======================================\n\n");

    printf("\n--- 🏅 Nível Novato 🏅 ---\n");
    nivelNovato();

    printf("\n\n--- 🛡️ Nível Aventureiro 🛡️ ---\n");
    nivelAventureiro();

    printf("\n\n--- 🏆 Nível Mestre 🏆 ---\n");
    nivelMestre();

    printf("\n\nDesafio finalizado!\n");

    return 0;
}


void nivelNovato() {
    struct CartaNovato carta1, carta2;

    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite a População: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite a População: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);


    printf("\n\n--- CARTAS CADASTRADAS ---\n");
    printf("\nCarta 1:\n");
    printf(" População: %d\n", carta1.populacao);
    printf(" Área: %.2f km²\n", carta1.area);
    printf(" PIB: R$ %.2f bi\n", carta1.pib);
    printf(" Pontos Turísticos: %d\n", carta1.pontosTuristicos);

    printf("\nCarta 2:\n");
    printf(" População: %d\n", carta2.populacao);
    printf(" Área: %.2f km²\n", carta2.area);
    printf(" PIB: R$ %.2f bi\n", carta2.pib);
    printf(" Pontos Turísticos: %d\n", carta2.pontosTuristicos);
}


void nivelAventureiro() {
    struct CartaMestre carta1, carta2;

    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite a População: ");
    scanf("%lu", &carta1.populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);


    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite a População: ");
    scanf("%lu", &carta2.populacao);
    printf("Digite a Área (km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite os Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos de atributos
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9) / carta1.populacao; // Usando notação científica

    carta2.densidade = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9) / carta2.populacao;

    
    printf("\n\n--- CARTAS CADASTRADAS (COM ATRIBUTOS CALCULADOS) ---\n");
    printf("\nCarta 1:\n");
    printf(" População: %lu\n", carta1.populacao);
    printf(" Área: %.2f km²\n", carta1.area);
    printf(" PIB: R$ %.2f bi\n", carta1.pib);
    printf(" Densidade: %.2f hab/km²\n", carta1.densidade);
    printf(" PIB per Capita: R$ %.2f\n", carta1.pibPerCapita);

    printf("\nCarta 2:\n");
    printf(" População: %lu\n", carta2.populacao);
    printf(" Área: %.2f km²\n", carta2.area);
    printf(" PIB: R$ %.2f bi\n", carta2.pib);
    printf(" Densidade: %.2f hab/km²\n", carta2.densidade);
    printf(" PIB per Capita: R$ %.2f\n", carta2.pibPerCapita);
}


void nivelMestre() {
    struct CartaMestre carta1, carta2;

    // A parte de cadastro seria idêntica à do nível aventureiro,
    // então vamos usar valores fixos aqui para focar na comparação.
    carta1 = (struct CartaMestre){1000000, 50000.0f, 200.0f, 150};
    carta2 = (struct CartaMestre){800000, 60000.0f, 180.0f, 200};

    // Cálculos
    carta1.densidade = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1e9) / carta1.populacao;
    carta1.superPoder = (float)carta1.populacao + carta1.area + (carta1.pib * 1e9) + (float)carta1.pontosTuristicos + carta1.pibPerCapita + (1.0 / carta1.densidade);

    carta2.densidade = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1e9) / carta2.populacao;
    carta2.superPoder = (float)carta2.populacao + carta2.area + (carta2.pib * 1e9) + (float)carta2.pontosTuristicos + carta2.pibPerCapita + (1.0 / carta2.densidade);


    printf("\n\n--- RESULTADO DAS COMPARAÇÕES ---\n");
    
    // 1 para carta 1 vence, 0 para carta 2 vence
    int vencedor; 
    
    vencedor = carta1.populacao > carta2.populacao;
    printf("População (maior vence): Vence a Carta %d\n", vencedor ? 1 : 2);

    vencedor = carta1.area > carta2.area;
    printf("Área (maior vence): Vence a Carta %d\n", vencedor ? 1 : 2);

    vencedor = carta1.pib > carta2.pib;
    printf("PIB (maior vence): Vence a Carta %d\n", vencedor ? 1 : 2);
    
    vencedor = carta1.pontosTuristicos > carta2.pontosTuristicos;
    printf("Pontos Turísticos (maior vence): Vence a Carta %d\n", vencedor ? 1 : 2);

    vencedor = carta1.densidade < carta2.densidade;
    printf("Densidade (menor vence): Vence a Carta %d\n", vencedor ? 1 : 2);

    printf("\n--- SUPER PODER ---\n");
    printf("Carta 1: %.2f\n", carta1.superPoder);
    printf("Carta 2: %.2f\n", carta2.superPoder);
    vencedor = carta1.superPoder > carta2.superPoder;
    printf("Super Poder (maior vence): Vence a Carta %d\n", vencedor ? 1 : 2);
}