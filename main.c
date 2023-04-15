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

void test_atVector_nonEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    assert(&v.data[0] == atVector(&v, 0));

    pushBack(&v, 42);
    assert(v.size == 2);

    assert(&v.data[1] == atVector(&v, 1));

    pushBack(&v, 505);
    pushBack(&v, 702);
    assert(v.size == 4);

    assert(&v.data[2] == atVector(&v, 2));

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[3] == atVector(&v, 3));

    pushBack(&v, 13);
    assert(&v.data[4] == atVector(&v, 4));

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[3] == back(&v));

    pushBack(&v, 13);
    assert(&v.data[4] == back(&v));

    popBack(&v);
    assert(&v.data[3] == back(&v));

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[0] == front(&v));

    pushBack(&v, 13);
    assert(&v.data[0] == front(&v));

    popBack(&v);
    assert(&v.data[0] == front(&v));

    reserve(&v, 2);
    assert(&v.data[0] == front(&v));

    deleteVector(&v);
}

void tests() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_nonEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    tests();

    Vector v = createVector(SIZE_MAX);
    return 0;
}