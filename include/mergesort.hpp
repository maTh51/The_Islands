#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <fstream>
#include <string>

struct island{
    int cost;
    int points;
    float ratio;
};


void merge(island *, int, int, int, island *);
void mergesort(island *, int, int, island *);


#endif