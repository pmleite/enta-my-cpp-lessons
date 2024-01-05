#include <iostream>
using namespace std;


//number to array
int digits[4];
int kaprekarInv[4];

void numberToArray(int n){
    for (int i = 3; i >= 0; i--) {
        digits[i] = n % 10;
        n /= 10;
    }
}

//Kaprekars inversion
void kaprekarConvert(int n[]){
  kaprekarInv[0] = n[0];
  kaprekarInv[1] = n[2];
  kaprekarInv[2] = n[3];
  kaprekarInv[3] = n[1];
}

int main()
{
    numberToArray(1234);
    cout << "teste" << endl;
    return 0;
}