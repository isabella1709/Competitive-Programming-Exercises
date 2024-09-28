#include <iostream>   // Biblioteca para operações de entrada e saída padrão
#include <fstream>    // Biblioteca para operações de leitura e escrita em arquivos
#include <vector>     // Biblioteca para utilizar a estrutura de dados vector
#include <string>     // Biblioteca para manipulação de strings
#include <algorithm>  // Biblioteca para algoritmos padrão, como sort
#include <random>     // Biblioteca para geração de números aleatórios
#include <chrono>     // Biblioteca para manipulação de tempo e relógio de alta resolução

using namespace std;
using vi = vector<int>;              // Alias para `vector<int>`
using vvi = vector<vector<int>>;     // Alias para `vector<vector<int>>`
using uint = unsigned int;           // Alias para `unsigned int`
using mt19937_gen = mt19937;         // Alias para `mt19937`

void print_vector(const vi& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " "; 
    }
    cout << endl;
}

void read_vector(vi& vec, int n) {
    if (n > 0) vec.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        vec.push_back(x);
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);

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

    if (achei) {
        cout << resposta;

    }else{
        cout << -1;
    }
    
    return 0;  // Indica que o programa terminou com sucesso.
}