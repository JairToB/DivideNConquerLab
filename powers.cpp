#include<iostream>

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

int main(){
    int x;
    int n;
    std::cin>>x;
    std::cin>>n;
    int result = logarithmPower(x,n);
    std::cout<<result<<std::endl;
    return 0;
}
