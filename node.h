/**
 * Filename: node.h
 * Description: Define node struct
 * Author: Zac Millmann
 * Date: 10/1/2025
 */

 #ifndef NODE_H
 #define NODE_H
 #include "vector.h"

 typedef struct Node{
    vector vectors;
    struct Node* next;
    struct Node* prev;
 } Node;

 #endif