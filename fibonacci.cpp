#include<iostream>
#include<vector>
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

int main(){
    int p;
    std::cin >> p;
    std::vector<std::vector<int>> matrix (2, std::vector<int>(2));
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    int result = fibonacciLogarithmic(p, matrix);

    std::cout << result << std::endl; 
    return 0;
}
