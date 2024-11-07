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
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvs = vector<char>;
using vll = vector<long long>;
using exec_seq = execution::sequenced_policy;

void print_vector(const vll& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void read_vector(vvs& vec, char n) {
    if (n > 0) vec.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        char x;
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

    int n;

    cin >> n;

    vvs word; vvs word_reverse = word;
    read_vector(word, n);

    reverse(word_reverse.begin(), word_reverse.end());

    if (word == word_reverse) {
        cout << "It's palindrome";
    }
    else {
        cout << "It's not a palindrome";
    }

    return 0;
}