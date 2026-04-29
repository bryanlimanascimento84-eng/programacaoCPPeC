#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(){
    cout << "Deseja iniciar a contagem? (s/n): ";
    char resposta;
    cin >> resposta;
    if (resposta == 's' || resposta == 'S') {
        cout << "Contagem iniciada!" << endl;
        this_thread::sleep_for(std::chrono::seconds(1)); // Pausa de 1 segundo antes de começar a contagem
        for (int i = 10; i >= 0; --i) {
            cout << i << endl;
            if (i > 0) {
                this_thread::sleep_for(std::chrono::seconds(1)); // Pausa de 1 segundo entre os números
            }
        }
        this_thread::sleep_for(std::chrono::seconds(1)); // Pausa de 1 segundo antes de finalizar
        cout << "Contagem finalizada!" << endl;
    } else {
        cout << "Contagem cancelada." << endl;
    }
    return 0;
}