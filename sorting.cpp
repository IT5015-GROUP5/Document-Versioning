#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
void readRec(records bookRecs);
void writeRec(records bookRecs);
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
	records book_record;

	return 0;
}

void readRec(records bookRecs)
{
	int i, j;
	FILE * fp;
	fp = fopen("library.txt", "r");

	if(fp!=NULL){
		for(i=0, j=0; i< N+2; i++) // the +2 is for the header in the text file
		{
			if(i==2){
				fscanf(fp, "%d %s %s %s %s %d", &(bookRecs[j].book_no), bookRecs[j].title, bookRecs[j].author, bookRecs[j].ISBN, bookRecs[j].contents, bookRecs[j].page_no);
				j++;
			}
			
		}	
	}else{
		printf("Error in reading file.");
	}
		
	
}

void writeRec(records bookRecs)
{
	int x;
	
	FILE * fp;
	int i;
	printf("Placing in file...");
	
	if(sizeof(records) != 0){
		
		fp= fopen("library.txt","w");
		for(i=0; i < N+2; i++) {
			fprintf(fp, "\n\n%-10s%-30s%15s%15s%15s%20s%15s","Book #","Title","Author", "ISBN", "Contents", "Page #");
			fprintf(fp, "\n%-10s%-30s%15s%15s%15s%20s%15s","---","---------------","--------","--------", "--------", "--------");
			fprintf(fp, "\n%-10d", bookRecs[i].book_no);
			fprintf(fp, "%-30s", bookRecs[i].title);	
			fprintf(fp, "%15s", bookRecs[i].author);
			fprintf(fp, "%15s", bookRecs[i].ISBN);
			fprintf(fp, "%20s", bookRecs[i].contents);
			fprintf(fp, "%15d", bookRecs[i].page_no);
		}
	}
	
	fclose(fp);
}

void sort(records data[])
{
	char choice, orderType;
	
	do {
		//	Option Panel
		printf("Sort by\n");
		printf("1 - Book Number\n");
		printf("2 - Page Number\n");
		printf("3 - Book Title\n");
		printf("4 - ISBN\n");
		printf("5 - Contents\n");
		printf("6 - Book Author\n");
		printf("X - Exit\n\n");
		printf("Enter your choice: ");
		scanf("%c", &choice);

		if (choice != 'X' || choice != 'x') {
			//	Order Option Panel
			do {
				print("\n\n Order by\n");
				printf("A - Descending Order\n");
				printf("B - Ascending Order\n");
				printf("X - Exit\n\n");
				printf("Enter what order: ");
				scanf("%c", &orderType);
			} while (orderType != 'A' && orderType != 'a'  && orderType != 'B' && orderType != 'b');
		}	

		//	switch case for the chosen option
		switch(choice) {
			case '1': 	sortBookNum(data, orderType);
					break;
			case '2': 	sortPageNum(data, orderType);
					break;
			case '3': 	sortTitle(data, orderType);
					break;
			case '4': 	sortISBN(data, orderType);
					break;
			case '5': 	sortContents(data, orderType);
					break;
			case '6': 	sortAuthor(data, orderType);
					break;
		}
	} while (choice != 'X' && choice != 'x');
}

//	Function for sorting book number in ascending or descending order
void sortBookNum(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(records[i].book_no < records[j].book_no) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(records[i].book_no > records[j].book_no) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting page number in ascending or descending order
void sortPageNum(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(records[i].page_no < records[j].page_no) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(records[i].page_no > records[j].page_no) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book title in ascending or descending order
void sortTitle(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].title, records[j].title)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].title, records[j].title)>0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting ISBN in ascending or descending order
void sortISBN(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].ISBN, records[j].ISBN)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].ISBN, records[j].ISBN)>0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book contents in ascending or descending order
void sortContents(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].contents, records[j].contents)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].contents, records[j].contents)>0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

//	Function for sorting book author in ascending or descending order
void sortAuthor(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].author, records[j].author)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].author, records[j].author)>0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}
}

void display(records data)
{
	int i;
	printf("BOOKS:\n");
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
