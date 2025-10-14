/**
 * Filename: vector_math.h
 * Description: Declare vector math functions
 * Author: Zac Millmann
 * Date: 10/1/2025
 */

 void add(float* result,float x1, float y1, float z1, float x2, float y2, float z2);
 void subtract(float* result,float x1, float y1, float z1, float x2, float y2, float z2);
 float dot(float x1, float y1, float z1, float x2, float y2, float z2);
 void cross(float* result,float x1, float y1, float z1, float x2, float y2, float z2);
 void scalar(float* result,float x, float y, float z, float scale);
 void scalar_both(float* result,float x1, float y1, float z1, float x2, float y2, float z2);
