#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


#ifndef VECTOR_H
#define VECTOR_H

#define start_size 10

typedef int32_t item;

typedef struct vector {
    item *list;
    uint32_t capacity;
    uint16_t length;
} vector;

// Starts the vector
void initialize(vector *v);

// Returns the length of the vector
int length(vector *v);

// Returns the capacity of the vector
int capacity(vector *v);

/*
    Resizes the vector to a given size
    Fails if the new size is smaller than the lenght of the vector
*/
void resize(vector *v, int new_size);

// Shrinks the capacity to the length of the vector
void shrink_to_fit(vector *v);

// Adds a new item to the end of the vector
void push_back(item i, vector *v);

void move_right(int index, vector *v);

void move_left(int index, vector *v);

// Removes the element of a given position
void remove_at(int index, vector *v);

/*
    Given an element, searches for its position and removes the first occurence
    Returns false if element is not present
*/
bool remove_elem(item elem, vector *v);

// Removes the last element from the vector
void pop_back(vector *v);

// Inserts an element in a given position
bool insert(item i, vector *v, int index);

// Returns the element of a given index
item elemat(int index, vector *v);

// Searches for a given element in the vector
// Uses Linear Search
int find(item elem, vector *v);

// Prints the vector
void showVector(vector *v);

// Clears the vector's elements
// Note: doesn't change the memory allocated
void clear(vector *v);

// Clears the vector's elements and frees the allocated memory
void destroy(vector *v);

#endif // VECTOR_H