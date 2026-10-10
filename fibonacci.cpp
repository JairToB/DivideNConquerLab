#include<iostream>
#include<vector>
#include<chrono>

extern std::vector<std::vector<int>> powerMatrixLog(std::vector<std::vector<int>> matrix, int position);
int fibonacciLinear(int position){
    int accumulator = 1;
    int current = 1;
    int previous = 0;
    int find = 0;
    if (position == 0) return 0;
    if (position == 1) return 1;
    while(position != accumulator){
        find = previous + current;
        previous = current;
        current = find;
        accumulator++;
    }
    return find;
}

int fibonacciLogarithmic(int position, std::vector<std::vector<int>> matrix){
    std::vector<std::vector<int>> c (2, std::vector<int>(2));
    c = powerMatrixLog(matrix, position);
    return c[1][0];
}

double measureFibonacciLinear(int position) {
    auto start = std::chrono::high_resolution_clock::now();
    fibonacciLinear(position);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count();
}

double measureFibonacciLogarithmic(int position, const std::vector<std::vector<int>>& matrix) {
    auto start = std::chrono::high_resolution_clock::now();
    fibonacciLogarithmic(position, matrix);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count();
}

int main(){
    int increase = 10000;
    int n = 1000000;
    std::vector<std::vector<int>> matrix (2, std::vector<int>(2));
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;
    for(int i = 10000; i < n; i += increase){
        long long totalTimeFibonacciLinear = measureFibonacciLinear(i);
        long long totalTimeFibonacciLogarithmic = measureFibonacciLogarithmic(i, matrix);
        std::cout << i << " " << totalTimeFibonacciLinear << " " << totalTimeFibonacciLogarithmic << std::endl;
    }

    return 0;
}
