#include <iostream>

using namespace std;

string arr1[] = {"a", "e", "h", "j", "b", "f", "g", "c", "i", "d"};
int arr2[] = {4,6,5,7,8,9,2,1,0,3};

template <typename T, typename K> K add(T a, K b){
    return a + b;
}

template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

int main(){

    int     a = add<int>(1,2);
    long    b = add<long>(1.5,2.3);
    long    c = add<int, long>(1,2.5);
    long    d = add<long, int>(1.5,2);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    for (int i = 0; i < 10; i++){
        cout << arr1[i] << ", ";
    }
    cout << endl;


    for (int i = 0; i < 10; i++){
        cout << arr2[i] << ", ";
    }
    cout << endl;

    bubbleSort(arr1, 10);
    bubbleSort(arr2, 10);

    for (int i = 0; i < 10; i++){
        cout << arr1[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++){
        cout << arr2[i] << ", ";
    }
    cout << endl;
    
    return 0;
}