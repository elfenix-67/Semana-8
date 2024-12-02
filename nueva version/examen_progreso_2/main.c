#include <stdio.h>
#include <string.h>
#include "funcion.h"

int main() {
    char texto[100];
    char palabra_larga[100], palabra_corta[100];
    int longitud_larga = 0, longitud_corta = 0;
    printf("Ingrese un texto: ");
    scanf("%[^\n]", texto);
    palabras(texto, palabra_larga, palabra_corta, &longitud_larga, &longitud_corta);
    printf("La palabra con mas caracteres es: '%s' (%d caracteres)\n", palabra_larga, longitud_larga);
    printf("La palabra con menos caracteres es: '%s' (%d caracteres)\n", palabra_corta, longitud_corta);

    return 0;
}
