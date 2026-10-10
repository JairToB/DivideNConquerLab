#include<iostream>

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

int main(){
    int p;
    std::cin >> p;
    int result = fibonacciLinear(p);
    std::cout << result << std::endl; 
    return 0;
}
