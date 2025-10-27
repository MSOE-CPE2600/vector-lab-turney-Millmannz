/**
 * Filename: vector_helper.h
 * Description: Declare helper functions used in parsing and calculations
 * Author: Zac Millmann
 * Date: 10/10/2025
 */

#include "vector.h"
#include "node.h"

void print_vectors();
void clear_list();
int find_vector(char name[], int print);
void print_vector(int i);
void assign(char name[], float x, float y, float z);
float getX(char* name);
float getY(char* name);
float getZ(char* name);
int is_float(const char *input);
void help();
void clear();
void save();
vector newVector(char name[], float x, float y, float z);
Node* new_node(Node *next, Node *prev, char name[], float x, float y, float z);