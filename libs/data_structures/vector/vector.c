#include "vector.h"

//второй коммит

//возвращает структуру-дескриптор вектор из n значений
Vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "Wrong value: capacity");
        exit(1);
    }

    return (Vector) {
            data,
            0,
            n
    };
}

//изменяет количество памяти, выделенное под хранение элементов вектора
void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    }
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "Wrong value: newCapacity = %llu", newCapacity);
        exit(1);
    }

    v->capacity = newCapacity;
    if (newCapacity < v->size) {
        v->size = newCapacity;
    }
}

//удаляет элементы из контейнера, но не освобождает выделенную память
void clear(Vector *v) {
    v->size = 0;
}

//освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(Vector *v) {
    v->capacity = v->size;
}
