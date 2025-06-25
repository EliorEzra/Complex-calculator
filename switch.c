#include "p.h"	

extern complex A, B, C, D, E, F;


void mainFaction(){
char line[MaxChar];	
char *p;
char firstComp,secondComp;
double x,y;
int oper;

while(1){
	printf("Please enter a command:\n");
	
	if(!fgets(line, MaxChar, stdin)){
		printf("you enter EOF before finishig\n");
		stop();
	}
	
	
	printf("your line is:\n%s",line);
	
	if(emptyLine(line)){
		printf("you inserted a blank line\n");
	continue;/*break the loop*/
	}
		
	
	p=line;
	
	oper=whichcommand(line);
	
	removeSpaces(p);
	
	p+=strlen(operations[oper]);
	
	firstComp = itIsAComplex(p[0]);
	
	switch(oper){
		case read_Comp:
			
			if(notAComplex(firstComp))
				break;
			
			
			p++;/*skiping the comp char*/
			
			if(missingcomma(p[0]))
				break;
			
			p++;/*skiping comma*/
			
			if(itsNotANum(p))
				break;
			
			x= atof(p);
			
			p+= skipDigits(p);
			
			if(missingcomma(p[0]))
				break;
			
			p++;/*skiping comma*/

			if(itsNotANum(p))
				break;
			
			y= atof(p);
			
			p+= skipDigits(p);
			
			if(isNotTheEnd(p))
				break;
			
			
			
			read_comp(whichComplex(firstComp), x, y);
			
			break;
		case print_Comp:
		case abs_Comp:
			
			if(notAComplex(firstComp))
				break;
			p++;
			
			if(isNotTheEnd(p))
				break;
				
			(oper == print_Comp) ? print_comp(whichComplex(firstComp)) : abs_comp(*whichComplex(firstComp));
			
			break;
		case add_Comp:
		case sub_Comp:
		case mult_Comp_comp:
			
			if(notAComplex(firstComp))
				break;
			
			p++;
			
			if(missingcomma(p[0]))
				break;
			
			p++;
			
			secondComp = itIsAComplex(p[0]);
		
			if(notAComplex(secondComp))
				break;
			p++;
			
			if(isNotTheEnd(p))
				break;
			
			if(oper == add_Comp)
				add_comp(*whichComplex(firstComp),*whichComplex(secondComp));
				else if(oper == sub_Comp)
					sub_comp(*whichComplex(firstComp),*whichComplex(secondComp));
					else
						mult_comp_comp(*whichComplex(firstComp),*whichComplex(secondComp));
			
			break;
		case mult_Comp_real:
		case mult_Comp_img:
			
			if(notAComplex(firstComp))
				break;
				
			p++;/*skiping the comp char*/
			
			if(missingcomma(p[0]))
				break;
				
			p++;/*skiping comma*/
			
			if(itsNotANum(p))
				break;
			
			x= atof(p);
			
			p+= skipDigits(p);
			
			if(isNotTheEnd(p))
				break;
				
			(oper == mult_Comp_real) ? mult_comp_real(*whichComplex(firstComp),x) : mult_comp_img(*whichComplex(firstComp),x);
			
			
			break;
		case Stop:
			
			if(isNotTheEnd(p))
				break;
			printf("finishing the program.\n");
			stop();
			
			break;
		default:
			printf("Undefined command name.\n");
			break;
		}
	}
}

int emptyLine(char line[]){
	int i;
	for(i=0; line[i]==' ' || line[i]=='\t' || line[i]=='\n'; i++);
	
	if(line[i] == '\0')
		return 1;
		
	return 0;
}

int notAComplex(char comp){
	if(comp == 'N'){
		printf("Undefined complex variable.\n");
		return 1;
	}
	return 0;
}

void removeSpaces(char *str) {
    int i;
    /* To keep track of non-space character count */
    int count = 0;
    
    /* Traverse the given string. If current character 
     is not space, then place it at index 'count++' */
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            str[count++] = str[i]; /* here count is incremented */
    }
    
    str[count] = '\0'; /* finish the string */
}



int whichcommand (char line[]){
	int i,len,space_count=0;
	
	while(line[space_count] == ' ')
	space_count++;/*for ignoring space from before the command*/
	
	for(i=0; i< FUNCTIONS; i++){
		len = strlen(operations[i]);
		
		if(strncmp(line+space_count,operations[i],len)==0){
			/**p+=space_count+len;*/
			return i;
		}
	}

return -1;
}

int missingcomma(char comma){
	if(comma == ',')
		return 0;
	printf("Missing comma.\n");
	return 1;
}

int itsNotANum(char *p){
	int i=0,dot=0;
	
	if(p[0] == '-')
		i++;
	
	for(;p[i] != ',' && p[i] != '\0';i++)
		if(!isdigit(p[i])){ 
			if(p[i] == '.' && dot == 0)/*if its the first dot*/
				dot = 1;
				else{/*if its not a digit and not a dot.*/
					printf("Invalid parameter – not a number");
					return 1;
				}/*end of else*/
				
		}/*end of the first if and the loop*/
	if(i == 0 || (i == 1 && p[0] == '-')){
		printf("Missing parameter");
		return 1;
		}
	
	return 0;

}

int skipDigits(char *p){
	int count=0;
	
	if(p[0] == '-')
		count++;
	
	while(isdigit(p[count]) || p[count] == '.')
		count++;
	
	return count;
}

int isNotTheEnd(char *p){
	
	if(p[0] == '\0')
		return 0;
	
	printf("Extraneous text after end of command");
	return 1;


}


char itIsAComplex(char comp){
	if(comp == 'A')
		return 'A';
	if(comp == 'B')
		return 'B';
	if(comp == 'C')
		return 'C';
	if(comp == 'D')
		return 'D';
	if(comp == 'E')
		return 'E';
	if(comp == 'F')
		return 'F';
		
	return 'N';
}

complex* whichComplex(char comp){
	if(comp == 'A')
		return &A;
	if(comp == 'B')
		return &B;
	if(comp == 'C')
		return &C;
	if(comp == 'D')
		return &D;
	if(comp == 'E')
		return &E;
	if(comp == 'F')
		return &F;
		
	return NULL;/*never reach here.*/
}
