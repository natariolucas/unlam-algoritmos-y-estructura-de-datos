#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/tda/cola/tda_cola_dinamica/tda_cola_dinamica.h"
int main()
{

    int elem[15] = {1, 2, 5, 3, 6, 7, 8, 3, 2, 1, 2 ,3 ,4, 5, 3};
    int elemSacar;
    t_cola tc;
    printf("- Se crea cola \n\n");
    crear_cola(&tc);

    printf("--- Se colocan elementos en cola \n");
    for(int i = 0; i<15; i++) {
        poner_en_cola(&tc, &elem[i], sizeof(int));
    }
    printf("\n");
    for(int i = 0; i<15; i++) {
        sacar_de_cola(&tc, &elemSacar, sizeof(int));
        printf("-- (iteracion: %d) elemento sacado: %d \n", i, elemSacar);
    }

    printf("\n");
    printf("- Cola vacia?: %d \n", cola_vacia(&tc) == COLA_VACIA);
    printf("- Cola llena para un int?: %d", cola_llena(&tc, sizeof(int)) == COLA_LLENA);
}
