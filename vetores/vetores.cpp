#include <iostream>
#include <vector>

using namespace std;

vector<int> teste;

string teste = "teste";



int main(){

    teste.push_back(1);
    teste.push_back(2);
    teste.push_back(3);
    teste.push_back(4);
    teste.push_back(5);
    teste.push_back(6);
    teste.push_back(7);
    teste.push_back(8);
    teste.push_back(9);
    teste.push_back(10);

    for(int i = 0; i < teste.size(); i++){
        cout << teste[i] << endl;
    }

    cout << teste.size() << endl;

    return 0;
}