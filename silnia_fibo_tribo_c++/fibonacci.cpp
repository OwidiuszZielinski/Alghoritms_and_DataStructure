#include <iostream>
#include <chrono>
using namespace std;

unsigned long int fibonacciIteracyjnie(unsigned int n){
    unsigned long int first = 0;
    unsigned long int sec = 1;
        for (int i = 2; i <= n; i++) {
           sec = first + sec;
           first = sec - first; 
        }
        return sec;
    
}
unsigned long int fibonacciRekurencyjnie(unsigned int n){
     if(n == 1 || n == 2){
            return 1;
        }
        else
            return fibonacciRekurencyjnie(n-1)+fibonacciRekurencyjnie(n-2);
    
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    
      std::cout<<fibonacciIteracyjnie(30)<< "\n"; 
    
    
    auto end = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Czas wykonywania iteracyjnie to: " << duration << " microseconds.\n" << endl;


    auto startRek = chrono::high_resolution_clock::now();
    
      std::cout<<fibonacciRekurencyjnie(30)<< "\n";
    
    
    auto endRek = chrono::high_resolution_clock::now(); 
    auto durationRek = chrono::duration_cast<chrono::microseconds>(endRek - startRek).count();
    cout << "Czas wykonywania Rekurencyjnie to: " << durationRek << " microseconds." << endl;
    
    return 0;
}