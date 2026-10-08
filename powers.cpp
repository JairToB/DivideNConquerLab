#include<iostream>
#include<vector>
#include<chrono>

int recursivePowerSequential(int x, int n){
    if(n == 0) return 1;
    return x * recursivePowerSequential(x, n - 1);
}

int logarithmPower(int x, int n){
    if(n == 0) return 1;
    if (n % 2 == 0){
        int a = logarithmPower (x, n/2);
        return a * a;
    } else{
        return x * logarithmPower(x,n-1);
    }
}

template <typename F>
long long functionTime(F function, int x, int n){
    auto star = std::chrono::high_resolution_clock::now();
    volatile int dummy = function(x, n);
    (void)dummy;
    auto end = std::chrono::high_resolution_clock::now(); 
    auto total_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - star).count();
    return total_ns;
}

int main(){
    int x;
    std::vector<int> exponents = {10, 50, 100, 500, 1000, 5000, 10000, 20000};
    std::cin>>x;
    std::cout << "# Exponente\tSecuencial(us)\tLogaritmico(us)\n";
    for(size_t i = 0; i < exponents.size(); ++i){
        int n = exponents[i];
        long long t_seq = functionTime(recursivePowerSequential, x, n);
        long long t_log = functionTime(logarithmPower, x, n);

        std::cout << n << "\t" << t_seq << "\t" << t_log << std::endl;
    }

    return 0;
}
