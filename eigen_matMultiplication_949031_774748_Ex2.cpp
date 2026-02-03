#include <Eigen/Dense>
#include <iostream>
#include <sys/time.h>
#include <vector>

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