#include <stdio.h>
#include <string.h>
#include "funcion.h"

void palabras(const char *texto, char *palabra_larga, char *palabra_corta, int *longitud_larga, int *longitud_corta) {
    int i = 0, start = 0, len = 0;
    *longitud_larga = 0;
    *longitud_corta = 1000; 
    while (texto[i] != '\0') {
        if (texto[i] == ' ') {
            i++;
            start = i;
            continue;
        }
        len = 0;
        while (texto[i] != ' ' && texto[i] != '\0') {
            len++;
            i++;
        }
        if (len > *longitud_larga) {
            *longitud_larga = len;
            strncpy(palabra_larga, texto + start, len);
            palabra_larga[len] = '\0';
        }
        if (len < *longitud_corta) {
            *longitud_corta = len;
            strncpy(palabra_corta, texto + start, len);
            palabra_corta[len] = '\0'; 
        }
        start = i; 
    }
}
