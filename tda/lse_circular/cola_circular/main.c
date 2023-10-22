#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/lse_circular/cola_circular/cola_circular.h"

typedef struct {
    char nya[100];
    int dni;
} t_alumno;

int main()
{
    t_cola cola;
    crear_cola(&cola);

    t_alumno alumnos[5] = {
        {
            "Lucas Natario", 42394230
        },
        {
            "Jorge Perez", 32456213
        },
        {
            "Juan Gomez", 98726534
        },
        {
            "Alberto Gutierrez", 23645716
        },
        {
            "Armando Casas", 23645728
        }
    };

    for(int i = 0; i < 5; i++) {
        printf("\nSe inserta alumno: %s - %d", alumnos[i].nya, alumnos[i].dni);
        poner_en_cola(&cola, &alumnos[i], sizeof(t_alumno));
    }

    printf("\n\n Se termina de insertar || Cola Vacia?: %d || Cola llena?: %d", cola_vacia(&cola), cola_llena(&cola, sizeof(t_alumno)));

    t_alumno alumnoFrente;
    frente_de_cola(&cola, &alumnoFrente, sizeof(t_alumno));
    printf("\n\n Se observa el frente: %s - %d", alumnoFrente.nya, alumnoFrente.dni);
    printf("\n Cola Vacia?: %d || Cola llena?: %d", cola_vacia(&cola), cola_llena(&cola, sizeof(t_alumno)));
    printf("\n");

    for(int i = 0; i < 5; i++) {
        sacar_de_cola(&cola, &alumnoFrente, sizeof(t_alumno));
        printf("\n Se saca alumno: %s - %d", alumnoFrente.nya, alumnoFrente.dni);
        printf("\n Cola Vacia?: %d || Cola llena?: %d", cola_vacia(&cola), cola_llena(&cola, sizeof(t_alumno)));
        printf("\n");
    }

    printf("\n\n Se termina de sacar || Cola Vacia?: %d || Cola llena?: %d", cola_vacia(&cola), cola_llena(&cola, sizeof(t_alumno)));

    return 0;
}
