// ============================================================
//  EXERCÍCIO 1 — Qual é o código ASCII da minha letra?
//  Semana 03 | Tipo de dado: char
// ============================================================
//
//  O QUE É O TIPO char?
//  char armazena UM único caractere: uma letra, um número
//  ou um símbolo. Ele ocupa 1 byte na memória.
//
//  O QUE É A TABELA ASCII?
//  Por baixo dos panos, o computador não entende letras —
//  ele só entende números. Por isso, cada caractere tem
//  um número correspondente. Esse mapeamento se chama ASCII.
//  Exemplos:
//    'A' -> 65      'a' -> 97
//    'B' -> 66      'b' -> 98
//    'C' -> 67      'c' -> 99
//
//  O QUE É CASTING?
//  É converter um tipo de dado em outro.
//    (int) 'A'   ->  transforma o char 'A' no número 65
//    (char) 66   ->  transforma o número 66 no char 'B'
//
// ------------------------------------------------------------
//  ENUNCIADO:
//  Crie um programa que leia uma letra digitada pelo usuário
//  e mostre na tela:
//    1) O código ASCII dessa letra.
//    2) O caractere anterior na tabela ASCII (código - 1).
//    3) O caractere seguinte na tabela ASCII (código + 1).
//
// ------------------------------------------------------------
//  EXEMPLO DE SAÍDA ESPERADA:
//
//  Digite uma letra: B
//  Código ASCII de 'B': 66
//  Caractere anterior: A
//  Caractere seguinte: C
//
// ------------------------------------------------------------
//  EXEMPLO DE SAÍDA ESPERADA (outro caso):
//
//  Digite uma letra: a
//  Código ASCII de 'a': 97
//  Caractere anterior: `
//  Caractere seguinte: b
//
// ============================================================
//  GABARITO
// ============================================================

#include <iostream>
using namespace std;

int main() {

    // Declaração das variáveis
    char letra;  // guarda o caractere digitado pelo usuário
    int  codigo; // guarda o número correspondente na tabela ASCII

    // Leitura do caractere
    cout << "Digite uma letra: ";
    cin  >> letra;

    // Convertemos char para int para obter o código ASCII
    codigo = (int) letra;

    // Exibimos o código ASCII
    cout << "Código ASCII de '" << letra << "': " << codigo << endl;

    // Subtraímos 1 do código e convertemos de volta para char
    cout << "Caractere anterior: " << (char)(codigo - 1) << endl;

    // Somamos 1 ao código e convertemos de volta para char
    cout << "Caractere seguinte: " << (char)(codigo + 1) << endl;

    return 0;
}