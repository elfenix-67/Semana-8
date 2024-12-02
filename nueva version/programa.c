﻿#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <stdlib.h>

void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}
void iniciar(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos) {
    for (int i = 0; i < MAX_PRODUCTOS; i++) {
        cantidades[i] = 0;
        recursos[i] = 0.0f;
        tiempos[i] = 0.0f;
        for (int j = 0; j < MAX_NOMBRE; j++) {
            nombres[i][j] = '\0';
        }
    }
    *totalProductos = 0;
}
void leer_cadena(char *cadena, int max_len) {
    int valido = 0;
    while (!valido) {
        printf("Ingrese el nombre del producto (solo letras): ");
        fgets(cadena, max_len, stdin);
        cadena[strcspn(cadena, "\n")] = '\0'; 

        valido = 1;
        for (int i = 0; cadena[i] != '\0'; i++) {
            if (!isalpha(cadena[i]) && cadena[i] != ' ') {
                printf("Entrada invalida. Solo se permiten letras y espacios.\n");
                valido = 0;
                break;
            }
        }
    }
}
void ingresar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos) {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float recurso, tiempo;

    leer_cadena(nombre, MAX_NOMBRE);

    printf("Ingrese la cantidad (solo numeros): ");
    while (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
        printf("Entrada invalida. Ingrese un número entero positivo: ");
        while (getchar() != '\n'); 
    }

    printf("Ingrese el recurso necesario: ");
    while (scanf("%f", &recurso) != 1 || recurso <= 0) {
        printf("Entrada inválida. Ingrese un número positivo: ");
        while (getchar() != '\n'); 
    }

    printf("Ingrese el tiempo de producción: ");
    while (scanf("%f", &tiempo) != 1 || tiempo <= 0) {
        printf("Entrada inválida. Ingrese un número positivo: ");
        while (getchar() != '\n'); 
    }

    strcpy(nombres[*totalProductos], nombre);
    cantidades[*totalProductos] = cantidad;
    recursos[*totalProductos] = recurso;
    tiempos[*totalProductos] = tiempo;

    (*totalProductos)++;
    printf("Producto agregado con éxito.\n");

    while (getchar() != '\n'); 
}
void mostrar_productos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos) {
    if (totalProductos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("+----------------------+----------+----------+----------+\n");
    printf("| Nombre del producto | Cantidad | Recursos | Tiempo   |\n");
    printf("+----------------------+----------+----------+----------+\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("| %-20s | %8d | %8.2f | %8.2f |\n", nombres[i], cantidades[i], recursos[i], tiempos[i]);
    }
    printf("+----------------------+----------+----------+----------+\n");
}
void calcular_produccion(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos, float recursosDisponibles, float tiempoDisponible) {
    if (totalProductos == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    if (recursosDisponibles <= 0 || tiempoDisponible <= 0) {
        printf("Los recursos o el tiempo disponibles deben ser mayores que 0.\n");
        return;
    }

    float totalRecursos = 0, totalTiempo = 0;
    for (int i = 0; i < totalProductos; i++) {
        totalRecursos += recursos[i] * cantidades[i];
        totalTiempo += tiempos[i] * cantidades[i];
    }

    printf("Tiempo total de produccion: %.2f\n", totalTiempo);
    printf("Recursos totales necesarios: %.2f\n", totalRecursos);

    if (totalRecursos <= recursosDisponibles && totalTiempo <= tiempoDisponible) {
        printf("La fabrica puede cumplir con la demanda.\n");
    } else {
        printf("No es posible cumplir con la demanda.\n");
    }
}
void editar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos) {
    if (totalProductos == 0) {
        printf("No hay productos registrados.\n");
        printf("Presione Enter para continuar...");
        while (getchar() != '\n');
        return;
    }

    int index;
    printf("Ingrese el índice del producto a editar (1-%d): ", totalProductos);
    while (scanf("%d", &index) != 1 || index < 1 || index > totalProductos) {
        printf("Índice inválido. Ingrese un número entre 1 y %d: ", totalProductos);
        while (getchar() != '\n'); 
    }

    index--; // Ajustar a índice del arreglo

    printf("\n--- Editar producto: %s ---\n", nombres[index]);

    int nuevaCantidad;
    printf("Ingrese nueva cantidad: ");
    while (scanf("%d", &nuevaCantidad) != 1 || nuevaCantidad <= 0) {
        printf("Cantidad inválida. Intente de nuevo: ");
        while (getchar() != '\n');
    }

    float nuevoRecurso;
    printf("Ingrese nuevo recurso necesario: ");
    while (scanf("%f", &nuevoRecurso) != 1 || nuevoRecurso <= 0) {
        printf("Recurso inválido. Intente de nuevo: ");
        while (getchar() != '\n');
    }

    float nuevoTiempo;
    printf("Ingrese nuevo tiempo de producción: ");
    while (scanf("%f", &nuevoTiempo) != 1 || nuevoTiempo <= 0) {
        printf("Tiempo inválido. Intente de nuevo: ");
        while (getchar() != '\n');
    }

    cantidades[index] = nuevaCantidad;
    recursos[index] = nuevoRecurso;
    tiempos[index] = nuevoTiempo;

    printf("\nProducto '%s' editado con éxito.\n", nombres[index]);
    printf("Presione Enter para continuar...");
    while (getchar() != '\n');
}

void eliminar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos) {
    if (*totalProductos == 0) {
        printf("No hay productos registrados.\n");
        printf("Presione Enter para continuar...");
        while (getchar() != '\n');
        return;
    }

    int index;
    printf("Ingrese el índice del producto a eliminar (1-%d): ", *totalProductos);
    while (scanf("%d", &index) != 1 || index < 1 || index > *totalProductos) {
        printf("Índice inválido. Ingrese un número entre 1 y %d: ", *totalProductos);
        while (getchar() != '\n');
    }

    index--; // Ajustar a índice del arreglo

    // Mover elementos para eliminar el producto
    for (int i = index; i < (*totalProductos) - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        recursos[i] = recursos[i + 1];
        tiempos[i] = tiempos[i + 1];
    }

    (*totalProductos)--; // Reducir el contador
    printf("Producto eliminado con éxito.\n");
    printf("Presione Enter para continuar...");
    while (getchar() != '\n');
}