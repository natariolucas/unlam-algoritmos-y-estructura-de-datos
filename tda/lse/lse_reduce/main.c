#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "../../../Librerias/tda/lse/lse.h"

typedef struct {
    char nombre[50];
    int cantidad;
} t_producto;

void mostrar_producto(const void* vProd);
int sumatoria_stock(const void* vProd, void* vSumatoria, void* extra);

int main()
{
    t_producto productos[5] = {
        {
            "Escoba", 10
        },
        {

            "Balde", 32
        },
        {
            "Rejilla", 55
        },
        {
            "Lavandina", 21
        },
        {
            "Secador", 2
        }
    };

    t_lista lista;
    crear_lista(&lista);
    for(int i = 0; i <= 4; i++) {
        poner_al_final(&lista, &productos[i], sizeof(t_producto));
    }

    printf("----- Mostrar lista antes del reduce -----");
    mostrar_lista(&lista, mostrar_producto);

    int total = 0;
    reduce_lista(&lista, &total, sumatoria_stock, NULL);
    printf("\n--- TOTAL: %d", total);

    printf("\n----- Mostrar lista luego del reduce (Debe quedar igual) -----");
    mostrar_lista(&lista, mostrar_producto);
}

void mostrar_producto(const void* vProd) {
    t_producto prod = *(t_producto*)vProd;
    printf("\n --- Nombre: %s | Cantidad: %d", prod.nombre, prod.cantidad);
}

int sumatoria_stock(const void* vProd, void* vSumatoria, void* extra) {
    t_producto prod = *(t_producto*)vProd;
    int sumatoria = *(int*)vSumatoria;

    sumatoria += prod.cantidad;
    memcpy(vSumatoria, &sumatoria, sizeof(int));
    return 1;
}
