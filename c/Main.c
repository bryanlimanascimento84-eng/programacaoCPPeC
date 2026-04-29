#include <stdio.h>
int main(){
    int numero, r;
    printf("Introduza um número: ");
    numero = scanf("%d", &numero);
    
    if ( numero <= 0 || numero ==1) {
        printf("Entrada inválida\n");
        return 0;
    }
    r = numero % 2;
    if (r == 0){
        printf("número é par\n");
    }
    else {
        printf("número é impar\n");
    }
    return 0;
}
