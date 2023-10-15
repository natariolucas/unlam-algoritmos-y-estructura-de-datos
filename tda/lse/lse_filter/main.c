#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/lse/lse.h"

typedef struct {
    char nombre[100];
    int edad;
} t_persona;

void mostrar_persona(const void* vPersona);
int filtrar_menores(const void* vPersona, void* vExtra);

int main()
{
    t_persona personas[5] = {
        {
            "Lucas Natario", 12
        },
        {

            "Juan Perez", 55
        },
        {
            "Ramon Rodriguez", 80
        },
        {
            "Alberto Sanchez", 15
        },
        {
            "Juan Perez", 33
        }
    };

    t_lista lista;
    crear_lista(&lista);

    for(int i = 0; i <= 4; i++) {
        poner_al_final(&lista, &personas[i], sizeof(t_persona));
    }

    printf("\n----Se muestra lista antes de filtrar-----");
    mostrar_lista(&lista, mostrar_persona);

    filter_lista(&lista, filtrar_menores, NULL);

    printf("\n----Se muestra lista luego de filtrar-----");
    mostrar_lista(&lista, mostrar_persona);
}

int filtrar_menores(const void* vPersona, void* vExtra){
    t_persona persona = *((t_persona*)vPersona);

    return persona.edad >= 18;
}

void mostrar_persona(const void* vPersona) {
    t_persona persona = *((t_persona*)vPersona);
    printf("\n -- Nombre: %s | Edad: %d", persona.nombre, persona.edad);
}
