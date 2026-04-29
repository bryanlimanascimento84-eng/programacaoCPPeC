#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int num;
    cout << "Digite um numero: ";
    cin >> num;

    cout << "Resultado :" << endl;
    if (num >= 1) cout << 0 << endl;
    if (num >= 2) cout << 1 << endl;
    if (num > 2) {
        int a = 0, b = 1;
        for (int i = 3; i <= num; ++i) {
            int c = a + b;
            cout << c << endl;
            a = b;
            b = c;
        }
    }
    return 0;

}

// for (int i = 3; i <= num; ++i) {
//            int c = a + b;
  //          cout << c << endl;
    //        a = b;
      //      b = c;
// processo de calculo para Fibonacci, 
// onde a e b são os dois últimos números da sequência, 
// e c é o próximo número a ser calculado. 
// O loop começa a partir do terceiro número da sequência, 
// pois os dois primeiros números (0 e 1) já são conhecidos. 
// A cada iteração, o próximo número é calculado como a soma dos dois últimos números, 
// impresso na tela, e então os valores de a e b são atualizados para os próximos cálculos.