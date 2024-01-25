#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"


void initialize(vector *v) {
    v->capacity = start_size;
    v->list = malloc(start_size * sizeof(item));
    if (v->list == NULL) {
        printf("Vector Not Allocated");
        exit(EXIT_FAILURE);
    }
    v->length = 0;
}


int length(vector *v) {
    return v->length;
}


int capacity(vector *v) {
    return v->capacity;
}

void resize(vector *v, int new_size) {
    if (new_size < v->length) {
        printf("New size cant be smaller than Vector length\n");
        return;
    }
    v->list = realloc(v->list, new_size * sizeof(item));
    if (v->list == NULL) {
        printf("Vector Not Allocated");
        exit(EXIT_FAILURE);
    }

}


void shrink_to_fit(vector *v) {
    v->list = realloc(v->list, v->length * sizeof(item));
}


void push_back(item i, vector *v) {

    if (v->length >= capacity(v)) {
        v->capacity *= 2;
        resize(v, v->capacity);
    }

    v->list[length(v)] = i;
    v->length++;

}


void move_right(int index, vector *v) {
    for (int i = length(v); i > index; i--) 
        v->list[i] = v->list[i-1];
}


void move_left(int index, vector *v) {
    for (int i = index; i < length(v) - 1; i++) 
        v->list[i] = v->list[i+1];
}


item remove_at(int index, vector *v) {
    item data = elemat(index, v);
    move_left(index, v);
    v->length--;
    return data;
}

bool remove_elem(item elem, vector *v) {
    int index = find(elem, v);
    if (elem == -1)
        return false;
    remove_at(index, v);
    return true;
}


void pop_back(vector *v) {
    v->length--;
}


bool insert(item i, vector *v, int index) {
    if (length(v) >= capacity(v)) {
        v->capacity *= 2;
        resize(v, v->capacity);
    }

    move_right(index, v);

    v->list[index] = i;
    v->length++;

    return true;
}


item elemat(int index, vector *v) {
    if (index < 0 || index >= capacity(v))
    {
        printf("INDEX OUT OF RANGE");
        exit(EXIT_FAILURE);
    }

    return v->list[index];
}


int find(item elem, vector *v) {
    for (int i = 0; i < length(v); i++) {
        if (v->list[i] == elem) 
            return i;
    }

    return -1;
}


void showVector(vector *v) {
    printf("[ ");
    for (int i = 0; i < length(v); i++)
    {
        printf("%d ", elemat(i, v));
    }
    printf("]\n");
}


void clear(vector *v) {
    v->length = 0;
}


void destroy(vector *v) {
    free(v->list);
    v->list = NULL;
    v->length = 0;
}