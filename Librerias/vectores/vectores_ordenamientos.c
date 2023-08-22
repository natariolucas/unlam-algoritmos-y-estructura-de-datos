int buscarMenor(int* vec, int desde, int hasta);
void intercambiar(int* elem1, int* elem2);

void ordenarBurbujeo(int* vec, int ce) {
    int i=1, huboIntercambios = 1;
    int j;
    while(huboIntercambios && i < ce) {
        huboIntercambios = 0;

        for(j = 0; j < ce-i; j++) {
            if(vec[j] > vec[j+1]) {
                intercambiar(&vec[j], &vec[j+1]);

                huboIntercambios = 1;
            }
        }
        i++;
    }
}

void ordenarSeleccion(int* vec, int ce) {
    int m;

    for(int i = 0; i < ce-1 ; i++) {
        m = buscarMenor(vec, i, ce-1);

        if(m != i)
            intercambiar(&vec[m], &vec[i]);
    }
}

int buscarMenor(int* vec, int desde, int hasta) {
    int m = desde;
    for(int i = desde+1; i <= hasta; i++) {
        if(vec[i] < vec[m])
            m = i;
    }

    return m;
}

void intercambiar(int* elem1, int* elem2) {
    int aux = *elem1;
    *elem1 = *elem2;
    *elem2 = aux;
}

void ordenarInsercion(int* vec, int ce) {
    for(int i = 1; i < ce; i++) {
        int elemAIns = vec[i];
        int j = i-1;
        while (j>= 0 && elemAIns < vec[j]) {
            vec[j+1] = vec[j];
            j--;
        }

        //ElemAIns es el menor de todos, o es mayor o igual que v[j]
        vec[j+1] = elemAIns;
    }

}
