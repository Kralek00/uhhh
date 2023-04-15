#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    Vector v = createVector(0);
    assert(isEmpty(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 7);
    assert(v.data[0] == 7 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 42);
    assert(v.data[0] == 42 && v.capacity == 1 && v.size == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    Vector v = createVector(0);
    assert(isFull(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    pushBack(&v, 42);
    assert(v.data[1] == 42 && v.capacity == 2 && v.size == 2);

    pushBack(&v, 42);
    pushBack(&v, 100500);
    assert(v.data[3] == 100500 && v.capacity == 4 && v.size == 4);

    pushBack(&v, -100500);
    assert(v.data[4] == -100500 && v.capacity == 8 && v.size == 5);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    pushBack(&v, -720);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVector(&v);
}

void tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    tests();

    Vector v = createVector(SIZE_MAX);
    return 0;
}