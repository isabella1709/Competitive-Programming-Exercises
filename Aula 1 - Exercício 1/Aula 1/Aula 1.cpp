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

int main(int argc, char* argv[]) {
    FAST_IO;

    cin.tie(nullptr);

    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <nome_do_arquivo>\n";
        return 1;  
    }

    ifstream file(argv[1]);
    
    if (!file) {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << "\n";
        return 1;
    }

    string line;
    getline(file, line); 

    int size = stoi(line);

    vi vec;
    vec.reserve(size);

    int num;

    while (file >> num) {
        vec.push_back(num); 
    }

    file.close();

    int esquerda = 0, direita = 0, soma = 0, resposta = 0;
    bool achei = false;

    for (size_t i = 0; i < vec.size(); ++i) {
        soma += vec[i];
    }

    for (size_t i = 0; i < vec.size(); ++i) {
        direita = ( soma - esquerda) - vec[i];

        if (esquerda == direita) {
            resposta = i;
            achei = true;
        }

        esquerda += vec[i];
    }


    achei ? cout << resposta : cout << -1;
    
    return 0;  // Indica que o programa terminou com sucesso.
}