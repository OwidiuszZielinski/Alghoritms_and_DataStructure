#include <iostream>
#include <chrono>
using namespace std;

unsigned long int silniaIteracyjnie(unsigned int n){
    unsigned long int sil = 1;
        for (int i = 1; i <= n; i++) {
            sil *= i;
        }
        return sil;
    
}
unsigned long int silniaRekurencyjnie(unsigned int n){
     if(n == 0){
            return 1;
        }
        else
            return n * silniaRekurencyjnie(n-1);
    
}


int main(){
    auto start = chrono::high_resolution_clock::now();
    
      std::cout<<silniaIteracyjnie(50)<< "\n"; 
    
    
    auto end = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Czas wykonywania iteracyjnie to: " << duration << " microseconds.\n" << endl;


    auto startRek = chrono::high_resolution_clock::now();
    
      std::cout<<silniaRekurencyjnie(50)<< "\n";
    
    fputs();

    auto endRek = chrono::high_resolution_clock::now(); 
    auto durationRek = chrono::duration_cast<chrono::microseconds>(endRek - startRek).count();
    cout << "Czas wykonywania Rekurencyjnie to: " << durationRek << " microseconds." << endl return 0;
}
