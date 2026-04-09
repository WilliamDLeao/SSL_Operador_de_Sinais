#include "signal.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

Signal::Signal(int tamanho) : dados(tamanho, 0.0) {}

void Signal::definirAmostra(int indice, double valor) {
    if (indice >= 0 && indice < (int)dados.size()) {
        dados[indice] = valor;
    }
}

void Signal::plotar(const std::string& titulo) const {
    std::cout << "\n>>> " << titulo << " <<<" << std::endl;

    if (dados.empty()) return;

    double maxAmp = 0, minAmp = 0;
    for (double v : dados) {
        if (v > maxAmp) maxAmp = v;
        if (v < minAmp) minAmp = v;
    }

    int altura = static_cast<int>(maxAmp - minAmp) + 2;
    if (altura < 5) altura = 5;

    for (int y = altura; y >= -1; --y) {
        if (y >= 0) std::cout << std::setw(3) << y + (int)minAmp << " | ";
        else std::cout << "    | ";

        for (int x = 0; x < (int)dados.size(); ++x) {
            int valorNormalizado = static_cast<int>(dados[x] - minAmp);
            
            if (y == valorNormalizado) {
                std::cout << " o "; 
            } else if (y == -1) {
                std::cout << "---"; 
            } else if (y >= 0 && y < valorNormalizado) {
                 std::cout << " | "; 
            } else {
                std::cout << "   "; 
            }
        }
        std::cout << std::endl;
    }

   
    std::cout << "      ";
    for (int x = 0; x < (int)dados.size(); ++x) {
        std::cout << std::setw(2) << x << " ";
    }
    std::cout << "\n" << std::endl;
}

Signal Signal::refletir() const {
    int n = (int)dados.size();
    Signal resultado(n);
    for (int i = 0; i < n; ++i) {
        resultado.dados[i] = dados[n - 1 - i];
    }
    return resultado;
}

Signal Signal::escalarTempo(double fator) const {
    int novoTamanho = static_cast<int>(dados.size() * fator);
    if (novoTamanho < 1) novoTamanho = 1;
    Signal resultado(novoTamanho);

    for (int i = 0; i < novoTamanho; ++i) {
        double posicaoOriginal = i / fator;
        int esquerda = static_cast<int>(std::floor(posicaoOriginal));
        int direita = esquerda + 1;
        
        if (direita < (int)dados.size()) {
            double pesoDireita = posicaoOriginal - esquerda;
            double pesoEsquerda = 1.0 - pesoDireita;
            resultado.dados[i] = (dados[esquerda] * pesoEsquerda) + (dados[direita] * pesoDireita);
        } else if (esquerda < (int)dados.size()) {
            resultado.dados[i] = dados[esquerda];
        }
    }
    return resultado;
}

Signal Signal::alterarAmplitude(double fator) const {
    Signal resultado((int)dados.size());
    for (int i = 0; i < (int)dados.size(); ++i) {
        resultado.dados[i] = dados[i] * fator;
    }
    return resultado;
}

Signal Signal::deslocar(int k, bool expandir) const {
    if (!expandir) {
        Signal resultado((int)dados.size());
        for (int i = 0; i < (int)dados.size(); ++i) {
            int novoIndice = i + k;
            if (novoIndice >= 0 && novoIndice < (int)dados.size()) {
                resultado.dados[novoIndice] = dados[i];
            }
        }
        return resultado;
    } else {
        int novoTamanho = (int)dados.size() + std::abs(k);
        Signal resultado(novoTamanho);
        int offset = (k > 0) ? k : 0;
        for (int i = 0; i < (int)dados.size(); ++i) {
            resultado.dados[i + offset] = dados[i];
        }
        return resultado;
    }
}

Signal Signal::somarDegrau(double ampDegrau) const {
    Signal resultado((int)dados.size());
    for (int i = 0; i < (int)dados.size(); ++i) {
        resultado.dados[i] = dados[i] + ampDegrau;
    }
    return resultado;
}