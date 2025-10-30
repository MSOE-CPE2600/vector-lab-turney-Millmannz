# Vector Lab
## Description
A miniature MATLAB program desgined to create and store vectors and perform vector math.
## Compile instructions
Use the command 'make' in linux terminal. 'make clean' can be used to remove resulting files.
## Running program
To run the program enter the executable in the terminal using './lab7' command line options are not supported in this program.
## Commands list
### 'quit'
Exit the program
### 'clear'
Clears the list of stored vectors
### 'list'
Prints a list of stored vectors
### 'save'
Save stored vectors to a new or existing file
### 'load'
Load a set of stored vectors from a file
## Dynamic Memory use
This program utilizes the linked-list data structure to allow for dynamic storage of vectors. These values are kept while the program is running and can be saved at any time but will be cleared and freed to prevent memory leakage at the end of the program.