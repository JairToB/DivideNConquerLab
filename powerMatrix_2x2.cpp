#include<iostream>
#include<vector>
std::vector<std::vector<int>> powerMatrixLog(std::vector<std::vector<int>> m, int e){
    if(e == 0){
        m[0][0] = 1;
        m[0][1] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
        return m;
    }
    if(e % 2 == 0){
        std::vector<std::vector<int>> a = powerMatrixLog(m, e/2);
        std::vector<std::vector<int>> z(2, std::vector<int>(2));
        z[0][0] = a[0][0] * a[0][0] + a[0][1] * a[1][0];
        z[0][1] = a[0][0] * a[0][1] + a[0][1] * a[1][1];
        z[1][0] = a[1][0] * a[0][0] + a[1][1] * a[1][0];
        z[1][1] = a[1][0] * a[0][1] + a[1][1] * a[1][1];
        return z;
    }else{
        std::vector<std::vector<int>> c = powerMatrixLog(m, e-1);
        std::vector<std::vector<int>> d(2, std::vector<int>(2));
        d[0][0] = c[0][0] * m[0][0] + c[0][1] * m[1][0];
        d[0][1] = c[0][0] * m[0][1] + c[0][1] * m[1][1];
        d[1][0] = c[1][0] * m[0][0] + c[1][1] * m[1][0];
        d[1][1] = c[1][0] * m[0][1] + c[1][1] * m[1][1];
        
        return d;
    }
}
int main(){
    std::vector<std::vector<int>> matrix(2, std::vector<int>(2));
    int exponent;
    std::cin>>exponent;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            std::cin >> matrix[i][j];
        }
    }
    std::vector<std::vector<int>>result = powerMatrixLog(matrix, exponent);
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            std::cout<< result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
