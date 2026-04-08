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

    original.plotar("SINAL ORIGINAL");

    original.refletir().plotar("A - REFLEXAO");
    
    double fEscala;
    std::cout << "\nfator de escala: ";
    std::cin >> fEscala;
    original.escalarTempo(fEscala).plotar("B - ESCALA");
    
    double fAmp;
    std::cout << "\nfator de amplitude: ";
    std::cin >> fAmp;
    original.alterarAmplitude(fAmp).plotar("C - AMPLITUDE");
    
    int k;
    std::cout << "\ndeslocamento k: ";
    std::cin >> k;
    original.deslocar(k, false).plotar("D - FIXO");
    original.deslocar(k, true).plotar("D - EXPANDIDO");
    
    double dAmp;
    std::cout << "\namplitude do degrau: ";
    std::cin >> dAmp;
    original.somarDegrau(dAmp).plotar("E - SOMA DEGRAU");

    return 0;
}