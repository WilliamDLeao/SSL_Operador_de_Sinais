# Processamento de Sinais Unidimensionais em C++

Este projeto implementa operações básicas de manipulação de sinais digitais. O foco foi a clareza didática, mostrando como os dados se comportam matematicamente em cada transformação.

## 📈 Discussão dos Resultados

### A) Reflexão ($x[-n]$)
A reflexão inverte a ordem das amostras. O que era o fim do sinal passa a ser o começo. 
* **Resultado esperado:** Se o sinal original crescia (ex: `1, 2, 3`), o refletido decresce (`3, 2, 1`). É o equivalente a "dar um espelho" no sinal no eixo vertical.

### B) Escala Temporal
Nesta implementação, usamos **Interpolação Linear** para mudar a escala. 
* **Fator > 1 (Expansão):** O sinal fica mais longo. Como o código calcula a média entre os pontos vizinhos, o gráfico parece mais "suave", preenchendo os espaços vazios de forma inteligente em vez de apenas repetir valores.
* **Fator < 1 (Compressão):** O sinal é encurtado (decimação). Algumas amostras são "espremidas" e o sinal perde detalhes, mantendo apenas a forma geral.

### C) Alteração de Amplitude
Esta é uma operação linear simples que afeta apenas o eixo vertical (altura).
* **Resultado:** Multiplicar por um fator maior que 1 aumenta o "volume" ou energia do sinal. Se o fator for entre 0 e 1, o sinal é atenuado. A forma do sinal e sua posição no tempo permanecem idênticas.

### D) Deslocamento Temporal ($x[n - k]$)
Aqui analisamos dois cenários de memória:
* **Domínio Fixo:** O sinal se move para o lado, mas o tamanho do vetor não muda. Se você empurrar o sinal para a direita, os valores que saírem da borda são perdidos e o começo é preenchido com zeros.
* **Domínio Expandido:** O vetor cresce para acomodar o movimento. Isso é ideal para garantir que nenhuma informação do sinal original seja perdida, independentemente de quanto você o desloque.

### E) Soma com Degrau
Ao somar um degrau (um valor constante em todas as amostras), estamos aplicando um **deslocamento vertical** ou "Offset DC".
* **Resultado:** O sinal inteiro "sobe" ou "desce" no gráfico. Se você tem um sinal que varia entre 0 e 2 e soma um degrau de 5, o novo sinal variará entre 5 e 7.

---

## 🛠️ Como Compilar e Executar

1.  Certifique-se de ter os arquivos `main.cpp`, `signal.cpp` e `signal.hpp` na mesma pasta.
2.  Abra o terminal e compile:
    ```bash
    g++ main.cpp signal.cpp signal.hpp -o ex
    ```
3.  Execute o programa:
    ```bash
    ./ex
    ```

## 💻 Estrutura do Código

* **`signal.hpp`**: Define a classe `Signal` e as assinaturas das funções.
* **`signal.cpp`**: Contém a lógica de cálculo (interpolação, loops de inversão e lógica de deslocamento).
* **`main.cpp`**: Interface simples para o usuário digitar os dados e ver os resultados no terminal.

---