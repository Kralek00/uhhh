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

//освобождает память, выделенную вектору.
void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

//третий коммит

//выводит значение "истина", если вектор v пустой, иначе "ложь"
bool isEmpty(Vector *v) {
    return v->size == 0;
}

//выводит значение "истина", если вектор v заполнен, иначе "ложь"
bool isFull(Vector *v) {
    return v->size == v->capacity;
}

//возвращает i-ый элемент вектора v
int getVectorValue(Vector *v, size_t i) {
    return *(v->data + i);
}

//добавляет элемент x в конец вектора v
void pushBack(Vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }

    *(v->data + v->size++) = x;
}

//удаляет последний элемент из вектора v
void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    v->size--;
}

//четвертый коммит

//возвращает указатель на index-ый элемент вектора v.
int *atVector(Vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

//возвращает указатель на последний элемент вектора v
int *back(Vector *v) {
    return v->data + v->size - 1;
}

//возвращает указатель на нулевой элемент вектора v
int *front(Vector *v) {
    return v->data;
}