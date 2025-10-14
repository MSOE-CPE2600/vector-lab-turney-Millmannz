/**
 * Filename: input.c
 * Description: Handle user input and parsing
 * Author: Zac Millmann
 * Date: 10/1/2025
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "vector_helper.h"
 #include "vector_math.h"
 #include "vector.h"


// Testing editing again

void help();
void clean_input(const char* inputs, char* output);
void parse_input(char* input);

 int main(void){
    
    char clean_array[132];
    char user_input[132];
    user_input[0] = '\0';

    while(1){
        printf("minimat> ");
        fgets(user_input, 132, stdin);
        clean_input(user_input, clean_array);
        if(strcmp(user_input, "-h\n")==0){help();}
        else if(strcmp(user_input, "list\n")==0){print_vectors();}
        else if(strcmp(user_input, "clear\n")==0){clear();}
        else if(strcmp(user_input, "quit\n") == 0){break;}
        else{
            parse_input(clean_array);
        }
    }
    return 0;
 }

//Clean input by removing extra spaces and commas to make parsing easier
void clean_input(const char* inputs, char* output){
    int i = 0, j = 0;

    while(inputs[i] != '\0'){
        if(inputs[i] == ','){
            if(inputs[i+1] != ' '){
                output[j++] = ' ';
            }
        }
        else if(inputs[i] == ' ' && (inputs[i+1] == ' ' || inputs[i+1] == ',')){
            //Removes extra spaces
        }
        else{
            output[j++] = inputs[i];
        }
        i++;
    }
    output[j] = '\0';

}

 

 void parse_input(char* input){
    float temp_values[3];
    char* token = strtok(input, " ");
    char* token2 = strtok(NULL, " ");
    char* token3 = strtok(NULL, " ");
    char* token4 = strtok(NULL, " ");
    char* token5 = strtok(NULL, " ");
    if(token != NULL && strcmp(token, "") != 0){
        //Used for string comparisons
        token[strcspn(token, "\n")] = '\0';

        //Printing out vector values
        if(token2 == NULL){
            int index = find_vector(token, 1);
            if(index > -1){
                print_vector(index);
            }
        }
        //Assigning vector values
        else if(strcmp(token2, "=") == 0 && token3 != NULL && token4 != NULL){
            //Modify after verifying 2,3,4 are not NULL
            token2[strcspn(token2, "\n")] = '\0';
            token3[strcspn(token3, "\n")] = '\0';
            token4[strcspn(token4, "\n")] = '\0';
            
            if(token5 == NULL){
                assign(token, atof(token3), atof(token4), 0.0);
            }
            else{
                token5[strcspn(token5, "\n")] = '\0';
                //Figure out which operand is used and calculate and assign value
                if(strcmp(token4,"+") == 0 ){

                    if(!is_float(token5) && !is_float(token3)){
                        if(find_vector(token3, 1)> -1){
                            if(find_vector(token5, 1)> -1){
                                add(temp_values, getX(token3), getY(token3), getZ(token3), getX(token5), getY(token5), getZ(token5));
                                assign(token, temp_values[0], temp_values[1], temp_values[2]);
                            }
                        }
                    }

                }
                else if(strcmp(token4,"-") == 0 ){

                    if(!is_float(token5) && !is_float(token3)){
                        if(find_vector(token3, 1)> -1){
                            if(find_vector(token5, 1)> -1){
                                subtract(temp_values, getX(token3), getY(token3), getZ(token3), getX(token5), getY(token5), getZ(token5));
                                assign(token, temp_values[0], temp_values[1], temp_values[2]);
                            }
                        }
                    }

                }
                else if(strcmp(token4,"*") == 0 ){

                    if(is_float(token5) && !is_float(token3)){
                        if(find_vector(token3, 1)>-1){
                            scalar(temp_values, getX(token3), getY(token3), getZ(token3), atof(token5));
                            assign(token, temp_values[0], temp_values[1], temp_values[2]);
                        }
                    }
                    else if(is_float(token3) && !is_float(token5)){
                        if(find_vector(token5, 1)>-1){
                            scalar(temp_values, getX(token5), getY(token5), getZ(token5), atof(token3));
                            assign(token, temp_values[0], temp_values[1], temp_values[2]);
                        }
                    }
                    else if(!is_float(token5) && !is_float(token3)){
                        if(find_vector(token3, 1)> -1){
                            if(find_vector(token5, 1)> -1){
                                scalar_both(temp_values, getX(token3), getY(token3), getZ(token3), getX(token5), getY(token5), getZ(token5));
                                assign(token, temp_values[0], temp_values[1], temp_values[2]);
                            }
                        }
                    }
                    
                }
                else if(strcmp(token4,"x") == 0 ){

                    if(!is_float(token5) && !is_float(token3)){
                        if(find_vector(token3, 1)> -1){
                            if(find_vector(token5, 1)> -1){
                                cross(temp_values, getX(token3), getY(token3), getZ(token3), getX(token5), getY(token5), getZ(token5));
                                assign(token, temp_values[0], temp_values[1], temp_values[2]);
                            }
                        }
                    }

                }
                else{
                    //Assign vector values as long as x y and z are provided
                    if(is_float(token5) && is_float(token3) && is_float(token4)){
                        assign(token, atof(token3), atof(token4), atof(token5));
                    }
                    else{
                        printf("Error: please enter float values and vector names only(-h for help)\n");
                    }
                }
            }
        }
        else if(token3 != NULL){
            //Modify token 2 and 3 after verifying they aren't NULL
            token2[strcspn(token2, "\n")] = '\0';
            token3[strcspn(token3, "\n")] = '\0';


            //Figure out which operand is used and apply operations
            if(strcmp(token2,"+") == 0){

                if(find_vector(token, 1)>-1){
                    if(find_vector(token3, 1)>-1){
                        add(temp_values, getX(token), getY(token), getZ(token), getX(token3), getY(token3), getZ(token3));
                        printf("ans = %.2f, %.2f, %.2f\n", temp_values[0], temp_values[1], temp_values[2]);
                    }
                }

            }
            else if(strcmp(token2,"-") == 0 ){
                if(find_vector(token, 1)>-1){
                    if(find_vector(token3, 1)>-1){
                        subtract(temp_values, getX(token), getY(token), getZ(token), getX(token3), getY(token3), getZ(token3));
                        printf("ans = %.2f, %.2f, %.2f\n", temp_values[0], temp_values[1], temp_values[2]);
                    }
                }
                

            }
            else if(strcmp(token2,"*") == 0 ){
                if(is_float(token3) && !is_float(token)){
                    if(find_vector(token, 1)>-1){
                        scalar(temp_values, getX(token), getY(token), getZ(token), atof(token3));
                        printf("ans = %.2f, %.2f, %.2f\n", temp_values[0], temp_values[1], temp_values[2]);
                    }
                }
                else if(is_float(token) && !is_float(token3)){
                    if(find_vector(token3, 1)>-1){
                        printf("r\n");
                        scalar(temp_values, getX(token3), getY(token3), getZ(token3), atof(token));
                        printf("ans = %.2f, %.2f, %.2f\n", temp_values[0], temp_values[1], temp_values[2]);
                    }
                }
                else if(!is_float(token3) && !is_float(token)){
                    if(find_vector(token, 1)> -1){
                        if(find_vector(token3, 1)> -1){
                            printf("%s * %s = %.2f\n", token, token3, dot(getX(token), getY(token), getZ(token), getX(token3), getY(token3), getZ(token3)));
                        }
                    }
                }
                else{
                    if(find_vector(token, 1)> -1){
                        find_vector(token3, 1);
                    }
                }

            }
            else if(strcmp(token2,"x") == 0 ){

                if(find_vector(token, 1)>-1){
                    if(find_vector(token3, 1)>-1){
                        cross(temp_values, getX(token), getY(token), getZ(token), getX(token3), getY(token3), getZ(token3));
                        printf("ans = %.2f, %.2f, %.2f\n", temp_values[0], temp_values[1], temp_values[2]);
                    }
                }
            }
        }
        else{
            printf("Error: invalid input, try again(-h for help)\n");
        }
    }
 }
