#include <iostream>
using namespace std;

int main()
{
    int vet[30];
    cout << "Digite 30 numeros inteiros: " << endl;
    for (int i=0; i<30; i++)
        cin >> vet[i];
    int maior = vet[0];
    int menor = vet[0];
    for (int i=1; i<30; i++) {
        if (vet[i] > maior) maior = vet[i];
        if (vet[i] < menor) menor = vet[i];
    }

    cout << "Maior: " << maior << endl;
    cout << "Menor: " << menor << endl;

    return 0;
}