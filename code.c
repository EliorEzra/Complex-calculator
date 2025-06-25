#include "data.h"

int main(int argc, char *argv[]){
	
	FILE* fd;
	node* head;
	int n;
	
	checkArguments(argc);
	
	savingData(argv[1]);
	
	printf("Please enter a nuber that represents the size of a Fibonacci sequence.\nnumber between 0 to %d:\n",MAX_LENGTH);
	
	scanf("%d",&n);

	head = fibonSequence(n);/*create a Fibonacci list and set the head to the nth term.*/
	
	setLastNext(head);/*set the last term next to the head for creating a circular list*/
	
	if(!(fd = fopen(argv[1],"w+"))){
		printf("Error: can not open this file.\n");
		exit(0);
	}
	
	saveInFile(head,fd,n);/*saving the data in the file your entered.*/
	
	printf("your list is :\n");
	
	printList(head,n);
	
	printf("\nyour file is ready now, thank you.\n");
	
	fclose(fd);

	return 0;
}

void checkArguments(int argc){/*protect the main data from user*/
	if(argc != 2){
		printf("Error: illegal number of arguments.\n");
		exit(0);
	}
}

void savingData(char arg[]){
	if(!strcmp(arg,"data.h")){
		printf("you can not edit data.h !\n");
		exit(0);
	}
	if(!strcmp(arg,"code.c")){
		printf("you can not edit code.c !\n");
		exit(0);
	}
}

void setLastNext(node* head){
	
	node* curent = head;

	while(curent->next != NULL){
	curent=curent->next;
	}

	curent->next = head;

}

node* fibonSequence(int n){

	node* fNode = (node*)malloc(sizeof(node));

	if(n < 0){/*if its a ilegal number or somthing else the program stop.*/
	printf("Error: Ilegal number!\n");
	exit(0);
	}
	
	if(n > MAX_LENGTH){/*if the number is more than 45*/
	printf("Error: your number is to high.\n");
	exit(0);
	}
	
	if(!fNode){/*if malloc did not work*/
	printf("Error: there is not enough memory space.\n");
	exit(0);
	}
	
	if(n==0){
	fNode->number = 1;
	fNode->next = NULL;
	return fNode;
	}
	
	if(n==1){
	fNode->number = 1;
	fNode->next = fibonSequence(n-1);
	return fNode;
	}
	
	fNode->number = fibonFaction(n-1)+fibonFaction(n-2);
	fNode->next = fibonSequence(n-1);
	return fNode;
	
}

int fibonFaction(int n){
	
	if(n==0 || n==1)
		return 1;
	
	return fibonFaction(n-1)+fibonFaction(n-2);

}

void saveInFile(node* head,FILE* fd,int n){

	node* curent = head;
	int count=1;/*for a line break every 10 terms*/

	fprintf(fd,"This series represents the Fibonacci series from the n(the number entered) term\n");
	fprintf(fd,"to the 0 term in descending order.\nFor n=%d the series is:\n\n",n);
		
	while(curent && curent->next != head){
		if(!(count++%BREAK_LINE)){
			fprintf(fd,"%d\n--> ",curent->number);
		}
		else
			fprintf(fd,"%d --> ",curent->number);
		
		curent = curent->next;
	}
	
	fprintf(fd,"%d\n",curent->number);
}

void printList(node* head,int n){/*printing to the terminal window.*/

	node* curent = head;
	int count=1;/*for a line break every 10 */
		
	while(curent && curent->next != head){
		if(!(count++%BREAK_LINE)){
			printf("%d\n--> ",curent->number);
		}
		else
			printf("%d --> ",curent->number); 
		
		curent = curent->next;
	}
	
	printf("%d\n",curent->number);
}


