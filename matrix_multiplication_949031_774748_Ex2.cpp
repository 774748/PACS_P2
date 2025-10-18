#include <iostream>
#include <vector>
#include <sys/time.h>
#include <random>
using namespace std;

// # Número de repeticiones por tamaño
// reps=5

// # Recorre los tamaños de matriz deseados
// for n in 100 200 500 800 1000 2000
// do
//   echo "=============================="
//   echo "Tamaño de matriz: ${n}x${n}"

//   # Bucle de repeticiones
//   for ((i=1; i<=reps; i++))
//   do
//     echo "--- Ejecución #$i ---"
//     time ./matrix_matMultiplication_949031_774748_Ex2 $n
//     echo ""
//   done

//   echo "=============================="
//   echo ""
// done

// Hacer pocas veces cada uno y sacar la media y en eigen igual

// Para el ejercicio 3
// for n in 100 200 500 800 1000 2000
// do
//   echo "=============================="
//   echo "Tamaño de matriz: ${n}x${n}"
//   strace -c ./matrix_multiplication_949031_774748_Ex2 $n
//   echo ""
// done

vector<vector<double>> matrix_generator(int n);
vector<vector<double>> multiply_matrix(const vector<vector<double>>& A, const vector<vector<double>>& B);

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    struct timeval t_start_all, t_end_all, t_mult_start_all;
    gettimeofday(&t_start_all, NULL);
    vector<vector<double>>  mat1 = matrix_generator(n);
    vector<vector<double>>  mat2 = matrix_generator(n);
    gettimeofday(&t_mult_start_all, NULL);
    vector<vector<double>>  mat3 = multiply_matrix(mat1, mat2);
    gettimeofday(&t_end_all, NULL);
    double elapsed_all = (t_end_all.tv_sec - t_start_all.tv_sec) + (t_end_all.tv_usec - t_start_all.tv_usec) / 1e6;
    double elapsed_mult_all = (t_end_all.tv_sec - t_mult_start_all.tv_sec) + (t_end_all.tv_usec - t_mult_start_all.tv_usec) / 1e6;
    cout << "Total time (seconds): " << elapsed_all << endl
         << "Matrix multiplication time (seconds): " << elapsed_mult_all << endl;
    return 0;
}

vector<vector<double>> matrix_generator(int n) {
    vector<vector<double>> matrix(n, vector<double>(n));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis {-1.0f, 1.0f};
    for (int row = 0; row < n; row++){
        for (int column = 0; column < n; column++){
            matrix[row][column] = dis(gen);
        }
    }
    return matrix;
}

vector<vector<double>> multiply_matrix(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}



