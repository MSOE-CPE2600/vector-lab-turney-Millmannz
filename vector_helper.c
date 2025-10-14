/**
 * Filename: vector_helper.c
 * Description: Define helper functions used in parsing and calculations
 * Author: Zac Millmann
 * Date: 10/10/2025
 */

 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include "vector.h"

 vector vectors[10];
 int open_index = 0;

//int print is used to contol whether or not the Error statement is printed out
int find_vector(char* name, int print){
   for(int i = 0; i < 10; i++){
      if(strcmp(vectors[i].name, name) == 0){
         return i;
      }
   }
   if(print == 1){printf("Error: no such vector exists(-h for help)\n");}
   return -1;
 }

 float getX(char* name){
   return vectors[find_vector(name, 0)].x;
 }

 float getY(char* name){
   return vectors[find_vector(name, 0)].y;
 }

 float getZ(char* name){
   return vectors[find_vector(name, 0)].z;
 }

 void print_vector(int i){
   printf("%s = %.2f, %.2f, %.2f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
 }

 void print_vectors(){
    for(int i = 0; i < 10; i++){
        if(vectors[i].name[0] == '\0'){
            break;
        }
        printf("%s: %.2f, %.2f, %.2f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
 }

 void assign(char name[], float x, float y, float z){
    // vectors[open_index].name = name;
    int used_index = find_vector(name, 0);
    if(used_index > -1){
      strcpy(vectors[used_index].name, name);
      vectors[used_index].x = x;
      vectors[used_index].y = y;
      vectors[used_index].z = z;
      print_vector(used_index);
    }
    else{
        if(open_index<10){
            strcpy(vectors[open_index].name, name);
            vectors[open_index].x = x;
            vectors[open_index].y = y;
            vectors[open_index].z = z;
            print_vector(open_index);
            open_index++;
        }
        else{
            printf("Error: Only 10 vectors can be stored. Clear vectors or reassign a vector(-h for help)\n");
        }
   }
 }

 int is_float(const char *input) {
    char *endptr;
    strtof(input, &endptr);  // Try to parse float

    // Skip any trailing whitespace
    while (isspace((unsigned char)*endptr)) endptr++;

    // Check if entire string was valid float and nothing is left unparsed
    return *endptr == '\0';
}
void clear() {
    memset(vectors, 0, sizeof(vector) * 10);
}
void help(){
    printf("=== Vector Calculator Help ===\n");
    printf("Interactive program for 3D vector operations.\n");
    printf("Supports assignment, addition, subtraction, dot product, cross product, scalar multiplication,\n");
    printf("vector listing, clearing, and quitting.\n\n");
    printf("Commands:\n");
    printf("  quit                 Exit the program.\n");
    printf("  clear                Clear all stored vectors.\n");
    printf("  list                 List all stored vectors and their values.\n");
    printf("  varname = x y z      Assign a vector (spaces or commas allowed).\n");
    printf("                       Example: a = 1 2 3   or   b = 4,5,6\n");
    printf("  varname              Display the current value of the vector.\n");
    printf("  var1 + var2          Add two vectors and display result.\n");
    printf("  var1 - var2          Subtract two vectors and display result.\n");
    printf("  var * num            Multiply a vector by a scalar.\n");
    printf("  num * var            Multiply a scalar by a vector.\n");
    printf("  result = expr        Assign the result of an operation to a new vector.\n");
    printf("                       Example: c = a + b   or   d = c * 2\n");
    printf("\nNote:\n");
    printf("  - All vectors must have exactly 3 components.\n");
    printf("  - Up to 10 vectors can be stored at once.\n");
    printf("  - Vector names are case-sensitive.\n");
    printf("  - Spaces are required around operators (=, +, -, *).\n");
    printf("  - Floating point values are supported.\n");
    printf("\nExamples:\n");
    printf("  a = 1.0 2.0 3.0\n");
    printf("  b = 4,5,6\n");
    printf("  c = a + b\n");
    printf("  d = c * 2\n");
    printf("  a + d\n");
 }