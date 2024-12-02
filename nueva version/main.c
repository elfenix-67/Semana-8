#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50
void imprimir_logo() {
    printf("             ________________________________________________\n");
    printf("            /                                                \\\n");
    printf("           |    _________________________________________     |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |  C:\\> _                                 |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |                                         |    |\n");
    printf("           |   |_________________________________________|    |\n");
    printf("           |                                                  |\n");
    printf("            \\_________________________________________________/\n");
    printf("                   \\___________________________________/\n");
    printf("                ___________________________________________\n");
    printf("             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_ \n");
    printf("          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_ \n");
    printf("       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_ \n");
    printf("    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_ \n");
    printf(" _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_ \n");
    printf(":-------------------------------------------------------------------------:\n");
    printf("`---._.-------------------------------------------------------------._.---'  \n");
    printf("TAREA: FABRICA\n");
}
int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int cantidades[MAX_PRODUCTOS];
    float recursos[MAX_PRODUCTOS];
    float tiempos[MAX_PRODUCTOS];
    int totalProductos = 0;

    iniciar(nombres, cantidades, recursos, tiempos, &totalProductos);

    int opcion;
    do {
        limpiar_pantalla();
        imprimir_logo();
        printf("\n1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Calcular producción\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        while (getchar() != '\n'); // Limpiar el buffer de entrada

        limpiar_pantalla();

        if (opcion == 1) {
            ingresar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
            printf("\nProducto ingresado correctamente. Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        } else if (opcion == 2) {
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        } else if (opcion == 3) {
            float recursosDisponibles, tiempoDisponible;
            printf("Ingrese los recursos disponibles: ");
            scanf("%f", &recursosDisponibles);
            while (getchar() != '\n'); // Limpiar el buffer
            printf("Ingrese el tiempo disponible: ");
            scanf("%f", &tiempoDisponible);
            while (getchar() != '\n'); // Limpiar el buffer
            calcular_produccion(nombres, cantidades, recursos, tiempos, totalProductos, recursosDisponibles, tiempoDisponible);
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        } else if (opcion == 4) {
            editar_producto(nombres, cantidades, recursos, tiempos, totalProductos);
            printf("\nProducto editado correctamente. Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        } else if (opcion == 5) {
            eliminar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
            printf("\nProducto eliminado correctamente. Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        } else if (opcion == 6) {
            printf("\nSaliendo del programa...\n");
            break; // Salir del bucle
        } else {
            printf("\nOpción inválida. Presione Enter para continuar...");
            while (getchar() != '\n'); // Esperar Enter
        }
    } while (opcion != 6);

    return 0;
}
