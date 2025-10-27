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
 #include "node.h"


Node *head = NULL;

vector newVector(char name[], float x, float y, float z){
  vector v;
  strncpy(v.name, name, sizeof(v.name));
  v.name[sizeof(v.name) - 1] = '\0';
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}
Node* new_node(Node *next, Node *prev, char name[], float x, float y, float z){
  Node *returnNode = malloc(sizeof(Node));
  returnNode->vectors = newVector(name, x, y, z);
  returnNode->next = next;
  returnNode->prev = prev;
  return returnNode;
}
Node* get_node(int index){
  if(index == -1){
    return NULL;
  }
  Node* search = head;
  for(int i = 0; i < index; i++){
    search = search->next;
  }
  return search;
}
int find_vector(char* name, int print){
  Node* search = head;
  int index = 0;
  while(search != NULL){
    if(strcmp(search->vectors.name, name) == 0){
      return index;
    }
    index++;
    search = search->next;
  }
  if(print == 1){printf("Error: no such vector exists(-h for help)\n");}
  return -1;
 }

 float getX(char* name){
   return get_node(find_vector(name, 0))->vectors.x;
 }

 float getY(char* name){
   return get_node(find_vector(name, 0))->vectors.y;
 }

 float getZ(char* name){
   return get_node(find_vector(name, 0))->vectors.z;
 }

 void print_vector(int i){
  Node* search = head;
  int index = 0;
  while(search != NULL){
    if(index == i){
      printf("%s = %.2f, %.2f, %.2f\n", search->vectors.name, search->vectors.x, search->vectors.y, search->vectors.z);
      return;
    }
    index++;
    search = search->next;
  }
   
 }

 void print_vectors(){
  Node* search = head;
  int index = 0;
  while(search != NULL){
    if(search->vectors.name[0] == '\0'){
      break;
    }
    printf("%s = %.2f, %.2f, %.2f\n", search->vectors.name, search->vectors.x, search->vectors.y, search->vectors.z);
    search = search->next;
    index++;
  }
 } 

 void assign(char name[], float x, float y, float z){
    // Node* prev = NULL;
    Node* search = head;
    Node* used_vector = get_node(find_vector(name, 0));
    if(used_vector != NULL){
      strcpy(used_vector->vectors.name, name);
      used_vector->vectors.x = x;
      used_vector->vectors.y = y;
      used_vector->vectors.z = z;
      print_vector(find_vector(used_vector->vectors.name, 0));
    }
    else{
      if(head==NULL){
        head = new_node(NULL, NULL, name, x, y, z);
        print_vector(find_vector(head->vectors.name, 0));
      }
      else{
        while(search->next != NULL){
          search = search->next;
        }
        search->next = new_node(NULL, search, name, x, y, z);
        print_vector(find_vector(search->next->vectors.name, 0));
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
// void clear() {
//     memset(vectors, 0, sizeof(vector) * 10);
// }
void clear_list() {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;  // Save next node
        free(current);         // Free current node
        current = next;        // Move to next
    }

    head = NULL; // Set original head to NULL
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
    printf("  save                 Save all stored vectors and their values to a new or existing file.\n");
    printf("  load                 Load stored vectors and their values from a file.\n");
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
    printf("  - Vector names are case-sensitive.\n");
    printf("  - Spaces are required around operators (=, +, -, *).\n");
    printf("  - Floating point values are supported.\n");
    printf("\nExamples:\n");
    printf("  a = 1.0 2.0 3.0\n");
    printf("  a 1.0 2.0 3.0\n");
    printf("  b = 4,5,6\n");
    printf("  c = a + b\n");
    printf("  d = c * 2\n");
    printf("  a + d\n");
 }
 void save(){
  char answer[10];
  Node *current = head;
  FILE* fptr;
  char* filename = (char*)malloc(20*sizeof(char));
  printf("Enter filename:\n");
  fgets(filename, 20, stdin);
  filename[strcspn(filename, "\n")] = '\0';
  fptr = fopen(filename, "r");
  if(fptr != NULL){
    fclose(fptr);
    printf("File already exists. Overwrite?(Y/N)\n");
    scanf("%s", answer);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    if(strcmp(answer, "Y") == 0){
      fptr = fopen(filename, "w");
      while(current != NULL){
        fprintf(fptr, "%s",current->vectors.name);
        fprintf(fptr,", ");
        fprintf(fptr, "%f" ,current->vectors.x);
        fprintf(fptr,", ");
        fprintf(fptr, "%f" ,current->vectors.y);
        fprintf(fptr,", ");
        fprintf(fptr, "%f\n" ,current->vectors.z);
        current = current->next;
      }
        fclose(fptr);
    }
  }
  else{
    fptr = fopen(filename, "w");
    while(current != NULL){
      fprintf(fptr, "%s",current->vectors.name);
      fprintf(fptr,", ");
      fprintf(fptr, "%f" ,current->vectors.x);
      fprintf(fptr,", ");
      fprintf(fptr, "%f" ,current->vectors.y);
      fprintf(fptr,", ");
      fprintf(fptr, "%f\n" ,current->vectors.z);
      current = current->next;
    }
    fclose(fptr);
  free(filename);
 }
}