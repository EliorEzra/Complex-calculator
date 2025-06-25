#include <stdio.h>
#include <math.h>/*for abs*/

typedef struct{
double real;
double imag;
}complex;

void mainFaction();
void initializeVariable();

void read_comp(complex *A,double r,double i);
void print_comp(complex *A);
void add_comp(complex A,complex B);
void sub_comp(complex A,complex B);
void mult_comp_real(complex A,double scale);
void mult_comp_img(complex A,double imag);
void mult_comp_comp(complex A,complex B);
void abs_comp(complex A);


