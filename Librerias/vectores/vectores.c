#include <stdlib.h>
#include "vectores.h"
void mostrarVector(void* vec, int ce, size_t tamElem, fnMostrarElemento mostrar) {
    for(int i; i < ce; i++) {
        mostrar((char*)(vec)+(i*tamElem), i);
    }
}
