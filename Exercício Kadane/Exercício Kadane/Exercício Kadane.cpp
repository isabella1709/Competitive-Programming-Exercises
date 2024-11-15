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

void read_vector(vi& vec, int n) {
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

// Função para encontrar a soma máxima de subarray contíguo
int maxSubArraySum(const vector<int>& nums) {
    // Inicializa com o primeiro elemento do array
    int current_max = nums[0];
    int global_max = nums[0];

    // Percorre o array a partir do segundo elemento
    for (size_t i = 1; i < nums.size(); ++i) {
        // Atualiza current_max
        current_max = max(nums[i], current_max + nums[i]);
        // Atualiza global_max se current_max for maior
        if (current_max > global_max) {
            global_max = current_max;
        }
    }

    return global_max;
}

int main(int argc, char* argv[]) {
    FAST_IO;

    int n;
    cin >> n;

    vi vector;
    read_vector(vector, n);

    int max = maxSubArraySum(vector);

    cout << max;

    return 0;
}
