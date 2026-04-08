#include "signal.hpp"
#include <iostream>

int main() {
    int tam;
    std::cout << "tamanho do sinal: ";
    std::cin >> tam;

    Signal original(tam);
    for (int i = 0; i < tam; ++i) {
        double v;
        std::cout << "valor em n=" << i << ": ";
        std::cin >> v;
        original.definirAmostra(i, v);
    }

    int opcao = 0;
    while (opcao != 6) {
        std::cout << "\n--- MENU DE OPERACOES ---" << std::endl;
        std::cout << "1. Reflexao" << std::endl;
        std::cout << "2. Mudança de Escala" << std::endl;
        std::cout << "3. Alterar Amplitude" << std::endl;
        std::cout << "4. Deslocamento de Sinal" << std::endl;
        std::cout << "5. Somar Degrau" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Escolha: ";
        std::cin >> opcao;

        if (opcao) {
            original.plotar("SINAL ORIGINAL");
        }

        switch (opcao) {
            case 1: {
                Signal res = original.refletir();
                res.plotar("A - RESULTADO REFLEXAO");
                break;
            }
            case 2: {
                double f;
                std::cout << "fator de escala: ";
                std::cin >> f;
                Signal res = original.escalarTempo(f);
                res.plotar("B - RESULTADO ESCALA");
                break;
            }
            case 3: {
                double f;
                std::cout << "fator de amplitude: ";
                std::cin >> f;
                Signal res = original.alterarAmplitude(f);
                res.plotar("C - RESULTADO AMPLITUDE");
                break;
            }
            case 4: {
                int k;
                std::cout << "valor de k: ";
                std::cin >> k;
                original.deslocar(k, false).plotar("D - RESULTADO FIXO");
                original.deslocar(k, true).plotar("D - RESULTADO EXPANDIDO");
                break;
            }
            case 5: {
                double dAmp;
                std::cout << "amplitude do degrau: ";
                std::cin >> dAmp;
                
                // cria um sinal que e so o degrau pra mostrar na tela
                Signal apenasDegrau(original.dados.size());
                for(int i = 0; i < (int)apenasDegrau.dados.size(); ++i) {
                    apenasDegrau.definirAmostra(i, dAmp);
                }
                
                apenasDegrau.plotar("DEGRAU GERADO (u[n] * amp)");
                
                Signal res = original.somarDegrau(dAmp);
                res.plotar("E - RESULTADO DA SOMA (ORIGINAL + DEGRAU)");
                break;
            }
            case 6:
                std::cout << "encerrando..." << std::endl;
                break;
            default:
                std::cout << "opcao invalida!" << std::endl;
                break;
        }
    }

    return 0;
}