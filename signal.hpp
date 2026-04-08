#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <vector>
#include <string>

class Signal {
public:
    std::vector<double> dados;

    Signal(int tamanho);
    void definirAmostra(int indice, double valor);
    void plotar(const std::string& titulo) const;

    Signal refletir() const;
    Signal escalarTempo(double fator) const;
    Signal alterarAmplitude(double fator) const;
    Signal deslocar(int k, bool expandir) const;
    Signal somarDegrau(double amp) const;
};

#endif