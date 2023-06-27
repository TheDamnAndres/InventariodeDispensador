#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

int main() {

    int id[MAX_PRODUCTOS];
    char sustancias[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    char detalles[MAX_PRODUCTOS][MAX_PRODUCTOS];
    int numProductos = 0;
    int prmenu;

    do {
        prmenu = menuPrincipal();

        switch (prmenu) {
            case 1:
                verProductos(id, sustancias, precios, detalles, numProductos);
                break;
            case 2:
                ingresarProducto(id, sustancias, precios, detalles, &numProductos);
                break;
            case 3:
                modificarProducto(id, sustancias, precios, detalles, numProductos);
                break;
            case 4:
                eliminarProducto(id, sustancias, precios, detalles, &numProductos);
                break;
            case 5:
                salir();
                break;
            default:
                printf("Elija una opcion correcta.\n");        }
    } while (prmenu != 5);

    return 0;
}









