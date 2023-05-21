#include <iostream>
#include <string.h>
using namespace std;

string tribonacci(int n) {
        unsigned long int firstEl = 0;
        unsigned long int secondEl = 0;
        unsigned long int thirdEl = 1;
        unsigned long int trib = 0;
        switch (n) {
            case 1 :{
                return "0";
                break;
            }
            case 2 :{
                return "1";
                break;
            }
            default : {
                if (n <= 0) {
                    return "Element nie moze byc zerowy lub mniejszy od 0";
                }
                for (int i = 3; i < n; i++) {
                    trib = thirdEl + secondEl + firstEl;
                    firstEl = secondEl;
                    secondEl = thirdEl;
                    thirdEl = trib;
                }
            }
        }
        std::string str = std::to_string(trib);
        return "Element nr: " + to_string(n) + " wynosi " + str;

    }


int main() {
    int num;
    cout << "Podaj ktory element ciagu tribonacciego chcesz otrzymac!\n";
    std::cin >> num;
    std::cout << "Potrzebujesz elmentu numer " << num << "\n";
    std::cout << tribonacci(num)<< endl;
    
    
    return 0;
}