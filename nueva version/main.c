#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

void imprimir_logo() {
    printf("             ________________________________________________\n");
    printf("            /                                                \\\n");
    printf("           |    _________________________________________     |    \n");
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
        printf("3. Calcular produccion\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        while (getchar() != '\n');  

        limpiar_pantalla();

if (opcion == 1) {
    ingresar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
    printf("\nProducto ingresado correctamente. Presione Enter para continuar...");
    while (getchar() != '\n'); 
} else if (opcion == 2) {
    int subopcion;
    do {
        limpiar_pantalla();
        printf("Submenu - Mostrar Productos:\n");
        printf("1. Mostrar productos en orden original\n");
        printf("2. Mostrar productos en orden alfabetico\n");
        printf("3. Mostrar productos por cantidad (mayor a menor)\n");
        printf("4. Mostrar productos por cantidad (menor a mayor)\n");
        printf("5. Volver al menu principal\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &subopcion);
        while (getchar() != '\n');  

        if (subopcion == 1) {
            limpiar_pantalla();
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);
        } else if (subopcion == 2) {
            limpiar_pantalla();
            ordenar_productos_alfabetico(nombres, cantidades, recursos, tiempos, totalProductos);
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);  // Mostrar después de ordenar
        } else if (subopcion == 3) {
            limpiar_pantalla();
            ordenar_productos_por_cantidad(nombres, cantidades, recursos, tiempos, totalProductos, 1);
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);  // Mostrar después de ordenar
        } else if (subopcion == 4) {
            limpiar_pantalla();
            ordenar_productos_por_cantidad(nombres, cantidades, recursos, tiempos, totalProductos, 0);
            mostrar_productos(nombres, cantidades, recursos, tiempos, totalProductos);  // Mostrar después de ordenar
        } else if (subopcion == 5) {
            printf("Volviendo al menu principal...\n");
        } else {
            printf("Opcion invalida. Intente de nuevo.\n");
        }

        if (subopcion != 5) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n');  
        }

    } while (subopcion != 5);
        } else if (opcion == 3) {
            int subopcion;
            do {
                limpiar_pantalla();
                printf("Submenu - Calcular Produccion:\n");
                printf("1. Elegir producto para calcular\n");
                printf("2. Volver al menu principal\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &subopcion);
                while (getchar() != '\n');

                if (subopcion == 1) {
                    int productoElegido;
                    printf("Seleccione el producto para calcular (1-%d): ", totalProductos);
                    scanf("%d", &productoElegido);
                    while (getchar() != '\n');

                    if (productoElegido >= 1 && productoElegido <= totalProductos) {
                        printf("\nProducto seleccionado:\n");
                        printf("Nombre: %s\n", nombres[productoElegido - 1]);
                        printf("Cantidad: %d\n", cantidades[productoElegido - 1]);
                        printf("Recurso necesario: %.2f\n", recursos[productoElegido - 1]);
                        printf("Tiempo de produccion: %.2f\n", tiempos[productoElegido - 1]);

                        float recursosDisponibles, tiempoDisponible;
                        printf("Ingrese los recursos disponibles: ");
                        scanf("%f", &recursosDisponibles);
                        while (getchar() != '\n');
                        printf("Ingrese el tiempo disponible: ");
                        scanf("%f", &tiempoDisponible);
                        while (getchar() != '\n');

                        calcular_produccion(nombres, cantidades, recursos, tiempos, totalProductos, recursosDisponibles, tiempoDisponible);
                        printf("\nPresione Enter para continuar...");
                        getchar();
                    } else {
                        printf("Opcion invalida. El numero de producto no existe.\n");
                        getchar();
                    }
                } else if (subopcion == 2) {
                    printf("Volviendo al menu principal...\n");
                } else {
                    printf("Opcion invalida. Intente de nuevo.\n");
                }

                if (subopcion != 2) {
                    printf("Presione Enter para continuar...");
                    getchar();
                }

            } while (subopcion != 2);
        } else if (opcion == 4) {
            editar_producto(nombres, cantidades, recursos, tiempos, totalProductos);
            printf("\nProducto editado correctamente. Presione Enter para continuar...");
            getchar();
        } else if (opcion == 5) {
            eliminar_producto(nombres, cantidades, recursos, tiempos, &totalProductos);
            printf("\nProducto eliminado correctamente. Presione Enter para continuar...");
            getchar();
        } else if (opcion == 6) {
            printf("\nSaliendo del programa...\n");
            break;
        } else {
            printf("\nOpcion invalida. Presione Enter para continuar...");
            getchar();
        }

    } while (opcion != 6);

    return 0;
}
