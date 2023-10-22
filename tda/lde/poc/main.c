#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/lde/lde.h"
#include <strings.h>

#define CANT_ALU 4

typedef struct {
    char nya[100];
    int dni;
} t_alumno;

int comparar_dni(const void* a, const void* b);

int main()
{
    t_lista miLista;
    crear_lista(&miLista);

    t_alumno alumnos[CANT_ALU] = {
        {
            "Lucas Natario", 42394230
        },
        {
            "Jose Perez", 70000000
        },
        {
            "Juan Gomez", 87645232
        },
        {
            "Alberto Rodriguez", 21354878
        }
    };

    for(int i = 0; i < CANT_ALU; i++) {
        printf("\n Inserta en orden en lista: %s - %d", alumnos[i].nya, alumnos[i].dni);
        insertar_en_orden(&miLista, &alumnos[i], sizeof(t_alumno), comparar_dni);
    }
    printf("\n");

    t_alumno primeroLista;
    primero_lista(&miLista, &primeroLista, sizeof(t_alumno));
    printf("\n Se obtiene primero de la lista: %s - %d ", primeroLista.nya, primeroLista.dni);

    t_alumno siguienteLista;
    while(siguiente_lista(&miLista, &siguienteLista, sizeof(t_alumno))) {
        printf("\n Se obtiene siguiente de lista: %s - %d", siguienteLista.nya, siguienteLista.dni);
    }
    printf("\n");

    strcpy(primeroLista.nya, "");
    primeroLista.dni = 0;
    primero_lista(&miLista, &primeroLista, sizeof(t_alumno));
    printf("\n Se obtiene primero de la lista nuevamente: %s - %d ", primeroLista.nya, primeroLista.dni);
    printf("\n");

    printf("\n============ SE PRUEBA LA QUITA ==================");
    t_alumno aluSacar;
    aluSacar.dni = 70000000;
    strcpy(aluSacar.nya, "");
    printf("\n Se hace la quita por DNI de %d", aluSacar.dni);
    sacar_de_lista(&miLista, &aluSacar, sizeof(t_alumno), comparar_dni);
    printf("\n Elemento sacado: %s - %d", aluSacar.nya, aluSacar.dni);
    printf("\n");

    strcpy(primeroLista.nya, "");
    primeroLista.dni = 0;
    primero_lista(&miLista, &primeroLista, sizeof(t_alumno));
    printf("\n Se obtiene primero de la lista nuevamente: %s - %d ", primeroLista.nya, primeroLista.dni);

    strcpy(siguienteLista.nya, "");
    siguienteLista.dni = 0;
    while(siguiente_lista(&miLista, &siguienteLista, sizeof(t_alumno))) {
        printf("\n Se obtiene siguiente de lista: %s - %d", siguienteLista.nya, siguienteLista.dni);
    }
    printf("\n===================================================");



    return 0;
}

int comparar_dni(const void* a, const void* b) {
    t_alumno* alu1 = (t_alumno*)a;
    t_alumno* alu2 = (t_alumno*)b;

    if(alu1->dni < alu2->dni)
        return -1;
    if(alu1->dni > alu2->dni)
        return 1;
    return 0;
}
