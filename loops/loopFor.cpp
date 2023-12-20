#include <iostream>
using namespace std;

int main(){

    int chave[5];
    int estrelas[2];

    //Loop for que mostra números de 1 a 10
    for (int i=1; i<=10; i++){
        cout << i << endl;
    }

    //Loops while que mostra números de 1 a 10 (avalia e faz depois)
    int i = 1;
    while (i <= 10){
        cout << i << endl;
        i++;
    }

    //Loop do while que mostra números de 1 a 10 (faz e avalia depois)
    i = 1;
    do {
        cout << i << endl;
        i++;
    } while (i <= 10);

}