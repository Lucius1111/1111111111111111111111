#ifndef GITROJECTS_VECTOR_H
#define GITROJECTS_VECTOR_H


typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

#endif //GITROJECTS_VECTOR_H
