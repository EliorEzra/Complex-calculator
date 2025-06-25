#include "complex.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define FUNCTIONS 9
#define MaxChar 100

char *operations[FUNCTIONS] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real", "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

typedef enum {read_Comp=0, print_Comp, add_Comp ,sub_Comp, mult_Comp_real, mult_Comp_img, mult_Comp_comp, abs_Comp, Stop};


int emptyLine(char line[]);/*checks if the user enter empty line.*/

int whichcommand (char line[]);/*checks which command and return a number that represents it*/

void removeSpaces(char *);/*removing all the spaces from the line.*/

int missingcomma(char comma);/*checks if missing comma*/

int itsNotANum(char *p);/*checks if its not a number*/

int skipDigits(char *p);/*skiping digits, return how much digits to skip.*/

int isNotTheEnd(char *p);/*checks if there is a character after the end of the command*/

char itIsAComplex(char comp);/*checks if its a complex and return a char that represent complex variable*/

complex* whichComplex(char comp);/*return which complex equals the param character*/

int notAComplex(char comp);/*checks if it is not a complex*/

