#include <stdio.h>
#include <string.h>
#include "../Librerias/cadenas/cadenas.h"

int main()
{
    char    destino[20],
            original[] = {"Hola"},
            *aux;
    aux = strcpy1(destino, original);
    printf("La cadena original es \"%s\" \n"
           "La cadena destino queda con \"%s\"\n"
           "strcpy devolvio %p y la cadena destino esta en la direccion %p \n",
           original, destino, aux, destino);

    return 0;
}
