#include <iostream>
using namespace std;

int main() {    
    char nome[21];
        cout << "Digite uma palavra (max; 20 caracteres): ";
        cin.getline(nome, 21);
        for (int i=0; nome[i] != '\0'; i++) {
            for (int j=20; nome[j] != '\0'; j--) {
                if (nome[i] == nome[j]) {
                    char temp = nome[i];
                    nome[i] = nome[j];
                    nome[j] = temp;
                cout << nome[i] << "Palindromo" << endl;
                }
                else cout << nome[i] << "Nao e palindromo" << endl;
            }
            return 0;
        }
    }