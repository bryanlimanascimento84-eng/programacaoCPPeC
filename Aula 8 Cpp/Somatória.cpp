#include <iostream>
using namespace std;

int main (){
    int num;
    cout << "Introduza um numero: ";
    cin >> num;

    int res =0;

    cout << "Resultado é :" << endl;
    for (int i = 1; i <= num; ++i){
        res += i;

}
    cout << res  << endl;

    cout << "Programa finalizado." << endl;
       
    return 0;
}