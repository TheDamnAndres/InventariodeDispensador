#define MAX_N 50
#define MAX 100

int menuPrincipal();
void verProductos(int* codigos, char nombres[][MAX_N], float* precios, char detalles[][MAX], int numProductos);
void ingresarProducto(int* codigos, char nombres[][MAX_N], float* precios, char detalles[][MAX], int* numProductos);
void modificarProducto(int* codigos, char nombres[][MAX_N], float* precios, char detalles[][MAX], int numProductos);
void eliminarProducto(int* codigos, char nombres[][MAX_N], float* precios, char detalles[][MAX], int* numProductos);
void salir();
