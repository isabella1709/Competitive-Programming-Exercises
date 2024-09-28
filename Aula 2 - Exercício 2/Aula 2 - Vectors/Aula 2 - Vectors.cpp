#include <iostream>   // Biblioteca para operações de entrada e saída padrão
#include <fstream>    // Biblioteca para operações de leitura e escrita em arquivos
#include <vector>     // Biblioteca para utilizar a estrutura de dados vector
#include <string>     // Biblioteca para manipulação de strings
#include <algorithm>  // Biblioteca para algoritmos padrão, como sort
#include <random>     // Biblioteca para geração de números aleatórios
#include <chrono>     // Biblioteca para manipulação de tempo e relógio de alta resolução
#include <execution>
#include <iostream>
#include <future>
#include <numeric>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

using namespace std;
using vi = vector<int>;              // Alias para `vector<int>`
using vvi = vector<vector<int>>;     // Alias para `vector<vector<int>>`
using vll = vector<long long>;
//using exec_seq = execution::sequenced_policy; // Alias para execution::seq

void print_vector(const vi& vec) { //função para printar vetor
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void read_vi(vi& vec, int n) {
    if (n > 0) vec.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
}

int main() {
    FAST_IO;

    int n, t;

    // Lendo o tamanho do vetor `n` e o valor de `t` para os múltiplos
    cin >> n >> t;

    vi vector;  // Vetor de tamanho `n`
    read_vi(vector, n);

    vvi results; vi subvector;

    // Itera sobre cada elemento do vetor
    for (int i = 0; i < n; i++) { 

        int sum = 0;
        vi subvector;

        for (int j = i; j < n; j++) {
            sum += vector[j]; 
            subvector.push_back(vector[j]);

            if (sum % t == 0) {
                results.push_back(subvector);
            }
        }

    }

    cout << results.size();

    return 0;
}
