#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 50
#define MAX 100

int menuPrincipal(){
    int opcion = 0;
    printf("\t\tMENU\n\n");
    printf("1)\n"
           "      __,_____\n"
           "     / __.==--\"  Ver sustancias \n"
           "    /#(-'\n"
           "    `-' \n\n");
    printf("2) \n"
           "     __,_____\n"
           "    / __.==--\"   Ingresar nuevo sustancia\n"
           "   /#(-'\n"
           "   `-'\n\n");
    printf("3)\n"
           "     __,_____\n"
           "    / __.==--\"   Modificar sustancia \n"
           "   /#(-'\n"
           "   `-'\n\n");
    printf("4) \n"
           "    __,_____\n"
           "   / __.==--\"    Eliminar sustancia\n"
           "  /#(-'\n"
           "  `-' \n\n");
    printf("5) \n"
           "    __,_____\n"
           "   / __.==--\"    Salir\n"
           "  /#(-'\n"
           "  `-'\n\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    return opcion;
}

void verProductos(int *id, char sustancias[][MAX_N], float *precios, char detalles[][MAX], int numSus) {
    printf("\t\t\tSUSTANCIAS\n");
    for (int i = 0; i < numSus; i++) {
        printf("ID            AKA               MAGIA               VALOR: \n");
        printf("%d            %s                %s                   %.2f    \n", id[i], sustancias[i], detalles[i], precios[i]);
        printf("-----------------------------------------------------------\n");
    }

    if(numSus == 0){
        printf("No hay sustancias exixtentes");
    }
}

void ingresarProducto(int *id, char sustancias[][MAX_N], float *precios, char detalles[][MAX], int *numSus) {

    if (*numSus >= MAX) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    int codigo = rand() % 9000 + 1000;
    char nombre[MAX_N];
    float precio;
    char detalle[MAX];

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre);

    printf("Ingrese el detalle del producto: ");
    scanf(" %[^\n]s", detalle);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    id[*numSus] = codigo;
    strcpy(sustancias[*numSus], nombre);
    precios[*numSus] = precio;
    strcpy(detalles[*numSus], detalle);

    (*numSus)++;

    printf("Producto agregado con éxito.\n");
}

void modificarProducto(int *id, char sustancias[][MAX_N], float *precios, char detalles[][MAX], int numSus) {
    int id2;

    printf("Ingrese el código del producto a modificar: ");
    scanf("%d", &id2);

    for (int i = 0; i < numSus; i++) {
        if (id[i] == id2) {
            char nombre[MAX_N];
            float precio;
            char detalle[MAX];

            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", nombre);

            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precio);

            printf("Ingrese el nuevo detalle del producto: ");
            scanf(" %[^\n]s", detalle);

            strcpy(sustancias[i], nombre);
            precios[i] = precio;
            strcpy(detalles[i], detalle);

            printf("Producto modificado con éxito.\n");
            return;
        }
    }

    printf("No existe ninguna sustancia con ese ID.\n");
}

void eliminarProducto(int *id, char sustancias[][MAX_N], float *precios, char detalles[][MAX], int *numSus) {
    int idelete;

    printf("ID del producto a eliminar: ");
    scanf("%d", &idelete);

    for (int i = 0; i < *numSus; i++) {
        if (id[i] == idelete) {
            for (int j = i; j < (*numSus) - 1; j++) {
                id[j] = id[j + 1];
                strcpy(sustancias[j], sustancias[j + 1]);
                precios[j] = precios[j + 1];
                strcpy(detalles[j], detalles[j + 1]);
            }

            (*numSus)--;

            printf("Producto eliminado con éxito.\n");
            return;
        }
    }

    printf("No existen sustancias con ese ID.\n");
}

void salir(){

    printf("                     :::!~!!!!!:.\n"
           "                  .xUHWH!! !!?M88WHX:.\n"
           "                .X*#M@$!!  !X!M$$$$$$WWx:.\n"
           "               :!!!!!!?H! :!$!$$$$$$$$$$8X:\n"
           "              !!~  ~:~!! :~!$!#$$$$$$$$$$8X:\n"
           "             :!~::!H!<   ~.U$X!?R$$$$$$$$MM!\n"
           "             ~!~!!!!~~ .:XW$$$U!!?$$$$$$RMM!\n"
           "               !:~~~ .:!M\"T#$$$$WX??#MRRMMM!\n"
           "               ~?WuxiW*`   `\"#$$$$8!!!!!!!!!\n"
           "             :X- M$$$$       `\"T#$T~!8$WUXU~\n"
           "            :X  ~#$$$m:        ~!~ ?$$$$$$\n"
           "          :!`.-   ~T$$$$8xx.  .xWW- ~\"\"##*\"\n"
           ".....   -~~:<` !    ~?T#$$@@W@*?$$      /`\n"
           "W$@@M!!! .!~~ !!     .:XUW$W!~ `\"~:    :\n"
           "#\"~~`.:x/`!!  !H:   !WM$$$$Ti.: .!WUn+!`\n"
           ":::~:!!`:X~ .: ?H.!u \"$$$B$$$!W:U!T$$M~\n"
           ".~~   :X@!.-~   ?@WTWo(\"*$$$W$TH$! `\n"
           "Wi.~!X$?!-~    : ?$$$B$Wu(\"**$RM!\n"
           "$R@i.~~ !     :   ~$$$$$B$$en:``\n"
           "?MXT@Wx.~    :     ~\"##*$$$$M~\n\n");


}