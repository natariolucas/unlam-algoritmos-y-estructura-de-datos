#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/lse/lse.h"
typedef struct {
    char nya[100];
    char dni[9];
} t_alumno;

void grabar_alumno_arch_bin(void* vInfo, void* vPf);
void leer_alumno_arch_bin(void* vInfo, void* vPf);
void probar_grabar();
void probar_leer();
void mostrar_alumno(const void* vAlu);
int main()
{
    probar_grabar();
    probar_leer();


    //cargar en archivo
}

void probar_grabar() {
    //Grabar en archivo
    t_lista lista;
    crear_lista(&lista);
    t_alumno alumnos[5] = {
        {
            "Lucas Natario", "42394230"
        },
        {

            "Jorge Perez", "11293876"
        },
        {

            "Juan Francisco", "98756421"
        },
        {

            "Alberto Ignacio", "76545667"
        },
        {

            "Jose Fraschetto", "01987232"
        }
    };

    FILE* pf = fopen("alumnos.dat","wb");
    for(int i = 0; i <= 4; i++ ) {
        poner_al_principio(&lista, &alumnos[i], sizeof(t_alumno));
    }

    map_lista(&lista, grabar_alumno_arch_bin, pf);
    fclose(pf);

}

void probar_leer() {
    t_lista lista;

    crear_lista(&lista);
    for(int i = 0; i <= 4; i++ ) {
        t_alumno alumnoVacio;
        poner_al_principio(&lista, &alumnoVacio, sizeof(t_alumno));
    }

    FILE* pf = fopen("alumnos.dat", "rb");
    map_lista(&lista, leer_alumno_arch_bin, pf);
    mostrar_lista(&lista, mostrar_alumno);
}

void grabar_alumno_arch_bin(void* vInfo, void* vPf) {
    FILE* pf = (FILE*)vPf;
    fwrite(vInfo, sizeof(t_alumno),1,pf);
}

void leer_alumno_arch_bin(void* vInfo, void* vPf) {
    FILE* pf = (FILE*) vPf;
    fread(vInfo, sizeof(t_alumno), 1, pf);
}

void mostrar_alumno(const void* vAlu) {
    t_alumno* alu = (t_alumno*) vAlu;
    printf("\n-- Alumno: %s - DNI: %s", alu->nya, alu->dni);
}
