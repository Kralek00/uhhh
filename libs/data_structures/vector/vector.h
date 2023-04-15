#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void popBack(Vector *v);

int* atVector(Vector *v, size_t index);

int* back(Vector *v);

int* front(Vector *v);
#endif //VECTOR_VECTOR_H
