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
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

using namespace std;
using vi = vector<int>;              // Alias para `vector<int>`
using vvi = vector<vector<int>>;     // Alias para `vector<vector<int>>`
using vll = vector<long long>;
using exec_seq = execution::sequenced_policy; // Alias para execution::seq

void print_vector(const vll& vec) { //função para printar vetor
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

void read_vvi(vvi& vecs, int n) {
    int index1, index2;

    for (int i = 0; i < n; i++) {
        vi vec;
        cin >> index1 >> index2;
        vec.push_back(index1); vec.push_back(index2);
        vecs.push_back(vec);
    }
}

int main(int argc, char* argv[]) {
    FAST_IO;

    int n, t;
    cin >> n >> t;

    vi humidity; vvi adjustments; 
    auto readTask1 = async(launch::async,  read_vi, ref(humidity, n)); //apenas um teste de async
    auto readTask2 = async(launch::async, read_vvi, ref(adjustments, t)); //apenas um teste de async

    readTask1.wait();
    readTask2.wait();

    vll results;
    results.reserve(humidity.size());


    for (const auto& adjustment : adjustments) {
        int value = adjustment[0];
        int index = adjustment[1];


        humidity[index] += value;

        auto sum = reduce(
            exec_seq{},       // Especifica execução sequencial (garante a ordem de avaliação).
            humidity.begin(),        // Início do intervalo do vetor humidity1.
            humidity.end(),          // Fim do intervalo do vetor humidity1.
            0LL,                      // Valor inicial da soma (0), com tipo long long para evitar estouro.
            [](auto acc, auto val) {  // Usando auto para parâmetros de lambda
                return acc + (val % 2 == 0 ? val : 0);  // Adiciona à soma se o valor for par.
            }
        );

        results.push_back(sum);
    }

    print_vector(results);


    return 0; 
}