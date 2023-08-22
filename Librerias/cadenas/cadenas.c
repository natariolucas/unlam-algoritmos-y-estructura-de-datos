#include "cadenas.h"

char* strcpy1(char* destino, const char* origen) {
    char *aux = destino;
    while(*origen) {
        *destino = *origen;
        origen++;
        destino++;
    }
    *destino = '\0';

    return aux;
}

/** Menos eficiente que la strcpy1 por direccionar el caracter nulo*/
char* strcpy2(char* destino, const char* origen) {
    char *aux = destino;
    while(*origen) {
        *destino = *origen;
        origen++;
        destino++;
    }
    *destino = *origen;

    return aux;
}

char* strcpy3(char* destino, const char* origen) {
    char *aux = destino;

    //Ordenes de precedencia:
    //  1- Asignacion
    //  2- Evaluacion de la condicion
    //  3- Incremento (Independientemente del resultado de la evaluacion)
    while((*destino = *origen) != '\0'){
        destino++;
        origen++;
    }

    return aux;
}

char* strcpy4(char* destino, const char* origen) {
    char *aux = destino;

    //Ordenes de precedencia:
    //  1- Asignacion
    //  2- Evaluacion de la condicion
    //  3- Incremento (Independientemente del resultado de la evaluacion)
    while((*destino++ = *origen++) != '\0')
        ;
    return aux;
}
