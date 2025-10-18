#include <Eigen/Dense>
#include <iostream>
#include <sys/time.h>
#include <vector>

// g++ -O3 eigen_matMultiplication_949031_774748.cpp -I./eigen-3.4.0 -o eigen_matMultiplication_949031_774748

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
//     time ./eigen_matMultiplication_949031_774748_Ex2 $n
//     echo ""
//   done

//   echo "=============================="
//   echo ""
// done
using namespace Eigen;
using namespace std;


int main(int argc, char* argv[]){
    const int n = atoi(argv[1]);
    struct timeval t_start_all, t_end_all, t_mult_start_all;
    gettimeofday(&t_start_all, NULL);
    MatrixXd A(n,n), B(n,n), C(n,n);
    A.setRandom();
    B.setRandom();

    gettimeofday(&t_mult_start_all, NULL);
    C = A*B;
    gettimeofday(&t_end_all, NULL);
    double elapsed_all = (t_end_all.tv_sec - t_start_all.tv_sec) + (t_end_all.tv_usec - t_start_all.tv_usec) / 1e6;
    double elapsed_mult = (t_end_all.tv_sec - t_mult_start_all.tv_sec) + (t_end_all.tv_usec - t_mult_start_all.tv_usec) / 1e6;   
    cout << "Total time (seconds): " << elapsed_all << endl;
    cout << "Multiplication time (seconds): " << elapsed_mult << endl;
    return 0;
}