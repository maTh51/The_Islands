#include "mergesort.hpp"

void merge(island *a, int e, int m, int d, island *aux){
    int i, j, k;
    /* copy a and b (reverse) to the aux array */
    for (i = 0; i <= m; i++)
        aux[i] = a[i];
    for (j = m+1; j <= d; j++)
        aux[d-j+m+1] = a[j];

    i = e;
    j = d;
    
    for (k = e; k <= d; k++){
        if (aux[i].ratio <= aux[j].ratio)
            a[k] = aux[i++];
        else
            a[k] = aux[j--];
    }
}

void mergesort(island *a, int e, int d, island *aux) {
    int m = (d+e)/2;
    if (e < d) {
        mergesort(a, e, m, aux);
        mergesort(a, m+1, d, aux);
        merge(a, e, m, d, aux);
    }
}