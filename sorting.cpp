#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define N 20

//	Structure
typedef struct node{
	int book_no;
	int page_no;
	char title[255];
	char ISBN[255];
	char contents[255];
	char author[255];
}records[N];

//	Prototype
void readRec(records);
void writeRec(records);
void sort(records);
void display(records);

//	Prototypes for the sorting method
void sortBookNum(records, char);
void sortPageNum(records, char);
void sortTitle(records, char);
void sortISBN(records, char);
void sortContents(records, char);
void sortAuthor(records, char);

int main()
{
	printf("\t\t\t\tWELCOME TO E-LIBRARY!!!\n");
	records book_record;
	readRec(book_record);
	sort(book_record);
	
	return 0;
}

void readRec(records R)
{
	int i;
	FILE *fp;
    char filename[15]="library.txt"; 
	fp = fopen(filename, "r");
	
	printf("Reading File...\n\n");
	if(fp!=NULL){
		for(i=0; i<N; i++) 
		{
			fscanf(fp, "%d %d %s %s %s %s", &(R[i].book_no), &(R[i].page_no), R[i].title, R[i].ISBN, R[i].contents, R[i].author);
		}	
	}else{
		printf("Error in reading file.");
	}
	printf("Reading Success...\n\n");
	
	fclose(fp);
}

void writeRec(records R)
{
	int i;
	FILE * fp;
    char filename[15]="library.txt";
    fp = fopen(filename, "w");
	
	printf("Placing in file...\n");
	for(i=0; i<N; i++){
		fprintf(fp, "%d %d %s %s %s %s \n", R[i].book_no, R[i].page_no, R[i].title, R[i].ISBN, R[i].contents, R[i].author);
	}
	printf("Process Completed...\n");
	
	fclose(fp);
}

void sort(records data)
{	
	char choice, orderType;
	
	do {
		//	Option Panel
		printf("Sort by\n");
		printf("A - Book Number\n");
		printf("B - Page Number\n");
		printf("C - Book Title\n");
		printf("D - ISBN\n");
		printf("E - Contents\n");
		printf("F - Book Author\n");
		printf("X - Exit\n\n");
		printf("Enter your choice: ");
		_flushall();
		scanf("%c", &choice);
		if (choice != 'X' && choice != 'x') {
			//	Order Option Panel
			do {
				_flushall();
				printf("\n\n Order by\n");
				printf("A - Descending Order\n");
				printf("B - Ascending Order\n");
				printf("X - Exit\n\n");
				printf("Enter what order: ");
				scanf("%c", &orderType);
			} while (orderType != 'A' && orderType != 'a'  &&  orderType != 'B' && orderType != 'b' && orderType != 'X' && orderType != 'x');
		}	

		//	switch case for the chosen option
		switch(choice) {
			case 'A':
			case 'a':	sortBookNum(data, orderType);
					break;
			case 'B': 
			case 'b':	sortPageNum(data, orderType);
					break;
			case 'C':
			case 'c':	sortTitle(data, orderType);
					break;
			case 'D':
			case 'd':	sortISBN(data, orderType);
					break;
			case 'E':
			case 'e':	sortContents(data, orderType);
					break;
			case 'F':
			case 'f':	sortAuthor(data, orderType);
					break;
		}
		if (choice != 'X' && choice != 'x') {
			display(data);
			writeRec(data);
		}
		
	} while (choice != 'X' && choice != 'x');
	
}

//	Function for sorting book number in ascending or descending order
void sortBookNum(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(data[i].book_no < data[j].book_no) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(data[i].book_no > data[j].book_no) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting page number in ascending or descending order
void sortPageNum(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(data[i].page_no < data[j].page_no) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(data[i].page_no > data[j].page_no) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book title in ascending or descending order
void sortTitle(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].title, data[j].title)<0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].title, data[j].title)>0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting ISBN in ascending or descending order
void sortISBN(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].ISBN, data[j].ISBN)<0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].ISBN, data[j].ISBN)>0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book contents in ascending or descending order
void sortContents(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].contents, data[j].contents)<0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].contents, data[j].contents)>0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book author in ascending or descending order
void sortAuthor(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].author, data[j].author)<0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(data[i].author, data[j].author)>0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}
}

void display(records data)
{
	int i;
	printf("BOOKS:\n\n");
	for(i = 0; i < N; i++){ //loop through the data
		printf("Book No: %d\n",data[i].book_no);
		printf("Title: %s\n",data[i].title);
		printf("Author: %s\n",data[i].author);
		printf("ISBN: %s\n",data[i].ISBN);
		printf("Page No: %d\n",data[i].page_no);
		printf("Content:\n %s",data[i].contents);
		printf("\n\n");
	}
}
