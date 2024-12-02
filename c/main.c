#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float recursos[MAX_PRODUCTOS];
    float tiempos[MAX_PRODUCTOS];
    int totalProductos = 0;

    iniciar(nombres, cantidades, recursos, tiempos, &totalProductos);

    int opcion;
    do {
        printf("\n1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Calcular producción\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        while (getchar() != '\n'); // Limpiar buffer

        if (opcion == 1) {
            ingresar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
        } 
        else if (opcion == 2) {
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);
        } 
        else if (opcion == 3) {
            float recursosDisponibles, tiempoDisponible;
            printf("Ingrese los recursos disponibles: ");
            scanf("%f", &recursosDisponibles);
            printf("Ingrese el tiempo disponible: ");
            scanf("%f", &tiempoDisponible);
            calcular_produccion(nombres, cantidades, recursos, tiempos, totalProductos, recursosDisponibles, tiempoDisponible);
        } 
        else if (opcion == 4) {
            editar_producto(nombres, cantidades, recursos, tiempos, totalProductos);
        } 
        else if (opcion == 5) {
            eliminar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
        } 
        else if (opcion == 6) {
            printf("Saliendo...\n");
        } 
        else {
            printf("Opción inválida.\n");
        }
    } while (opcion != 6);

    return 0;
}
