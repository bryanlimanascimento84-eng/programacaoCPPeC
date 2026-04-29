#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int num;
    cout << "Introduza um numero: ";
    cin >> num;

    cout << "Tabuada do " << num << ":" << endl;
    for(int i = 1; i <= 10; i++){
        cout << num << " x " << i << " = " << num * i << endl;
    }
    return 0;

}