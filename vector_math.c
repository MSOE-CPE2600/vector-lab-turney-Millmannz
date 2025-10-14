/**
 * Filename: vector_math.c
 * Description: Define vector math functions
 * Author: Zac Millmann
 * Date: 10/1/2025
 */


void add(float* result,float x1, float y1, float z1, float x2, float y2, float z2){
   result[0] = x1 + x2;
   result[1] = y1 + y2;
   result[2] = z1 + z2;
 }
 void subtract(float* result,float x1, float y1, float z1, float x2, float y2, float z2){
   result[0] = x1 - x2;
   result[1] = y1 - y2;
   result[2] = z1 - z2;
 }
 float dot(float x1, float y1, float z1, float x2, float y2, float z2){
   return ((x1*x2) + (y1*y2) + (z1*z2));
 }
 void cross(float* result,float x1, float y1, float z1, float x2, float y2, float z2){
   result[0] = (y1 * z2) - (z1 * y2);
   result[1] = (z1 * x2) - (x1 * z2);
   result[2] = (x1 * y2) - (y1 * x2);
 }
 void scalar(float* result,float x, float y, float z, float scale){
   result[0] = x * scale;
   result[1] = y * scale;
   result[2] = z * scale;
 }
 void scalar_both(float* result,float x1, float y1, float z1, float x2, float y2, float z2){
   result[0] = x1 * x2;
   result[1] = y1 * y2;
   result[2] = z1 * z2;
 }

