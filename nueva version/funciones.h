#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

void iniciar(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos);
void leer_cadena(char *cadena, int max_len);
void ingresar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos);
void mostrar_productos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos);
void calcular_produccion(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos, float recursosDisponibles, float tiempoDisponible);
void editar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int totalProductos);
void eliminar_producto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], int cantidades[MAX_PRODUCTOS], float recursos[MAX_PRODUCTOS], float tiempos[MAX_PRODUCTOS], int *totalProductos);
void limpiar_pantalla();
#endif
