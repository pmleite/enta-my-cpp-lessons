#include <iostream>
#include <cmath>

using namespace std;

int main(){
    for (float n=0; n<1; n+=0.01){
        cout << "O seno de " << n << " é " << sin(n) << endl;
        cout << "O cosseno de " << n << " é " << cos(n) << endl;    
    }  
    return 0;
}