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
	records book_record;

	return 0;
}

void readRec(records R)
{
	int i;
	FILE * fp;
    char filename[16]="library.txt"; 
	fp = fopen(filename, "r");

	if(fp!=NULL){
		for(i=0, j=0; i< N+2; i++) // the +2 is for the header in the text file
		{
			if(i == 2){
				fscanf(fp, "%d", &(R[j].book_no));
				fscanf(fp, "%d", &(R[j].page_no));
				fgets(R[j].title, 25, fp);
				fgets(R[j].ISBN, 11, fp);
				fscanf(fp, "%s.", R[j].contents);
				fscanf(fp, "%s", R[j].author);
				j++;
			}
			
		}	
	}else{
		printf("Error in reading file.");
	}	
	
}

void writeRec(records R)
{
	int x;
	
	FILE * fp;
    	char filename[15]="library.txt";
	
	printf("Placing in file...");
	
	if(sizeof(records) != 0){
		
		fp= fopen(filename,"w");
		
		fprintf(fp, "\n\n%-10s%-30s%15s%15s%15s%20s%15s","Book #","Title","Author", "ISBN", "Contents", "Page #");
		fprintf(fp, "\n%-10s%-30s%15s%15s%15s%20s%15s","---","---------------","--------","--------", "--------", "--------");
		fprintf(fp, "\n%-10d", R[0].book_no);
		fprintf(fp, "%-30s", R[0].title);	
		fprintf(fp, "%15s", R[0].author);
		fprintf(fp, "%15s", R[0].ISBN);
		fprintf(fp, "%20s", R[0].contents);
		fprintf(fp, "%15d", R[0].page_no);
	}
	
	fclose(fp);
}

void sort(records data)
{
	char choice, orderType;
	
	//	Option Panel
	printf("Sort by\n");
	printf("1 - Book Number\n");
	printf("2 - Page Number\n");
	printf("3 - Book Title\n");
	printf("4 - ISBN\n");
	printf("5 - Contents\n");
	printf("6 - Book Author\n");
	printf("0 - Book Number\n\n");
	printf("Enter your choice: ");
	scanf("%c", &choice);
	
	//	Order Option Panel
	printf("\n\n Order by\n");
	printf("A - Descending Order\n");
	printf("B - Ascending Order\n");
	scanf("%c", &orderType);	
	
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
		case '0': 	break;
	}
}

//	Function for sorting book number in ascending or descending order
void sortBookNum(records data, char orderType)
{
	struct node temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if((data[i].book_no < data[j].book_no)<0) {
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(data[i].book_no < data[j].book_no) {
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
				if(data[i].page_no < data[j].page_no) {
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
