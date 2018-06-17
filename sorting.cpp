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

	for(i=0, j=0; i< N+2; i++) // the +2 is for the header in the text file
	{
		if(i==2){
			fscanf(fp, "%d", bookRecs[j].book_no);
			fgets(bookRecs[j].title, 255, fp);
			fgets(bookRecs[j].author, 255, fp);
			fgets(bookRecs[j].ISBN, 255, fp);
			fgets(bookRecs[j].contents, 255, fp);
			fscanf(fp, "%d", bookRecs[j].page_no);
			j++;
		}
		
	}	
	
}

void writeRec(records bookRecs)
{
	int x;
	
	FILE * fp;
	
	printf("Placing in file...");
	
	if(sizeof(records) != 0){
		
		fp= fopen("library.txt","w");
		
		fprintf(fp, "\n\n%-10s%-30s%15s%15s%15s%20s%15s","Book #","Title","Author", "ISBN", "Contents", "Page #");
		fprintf(fp, "\n%-10s%-30s%15s%15s%15s%20s%15s","---","---------------","--------","--------", "--------", "--------");
		fprintf(fp, "\n%-10d", bookRecs.book_no);
		fprintf(fp, "%-30s", bookRecs.title);	
		fprintf(fp, "%15s", bookRecs.author);
		fprintf(fp, "%15s", bookRecs.ISBN);
		fprintf(fp, "%20s", bookRecs.contents);
		fprintf(fp, "%15d", bookRecs.page_no);
	}
	
	fclose(fp);
}

void sort(records data[])
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
	print("\n\n Order by\n");
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
void sortBookNum(records data[], char orderType)
{
	records temp;
	int i, j;
	if(orderType == 'A' || orderType == 'a') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(records[i].book_no < records[j].book_no)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].book_no, records[j].book_no)>0) {
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
				if(records[i].page_no < records[j].page_no)<0) {
					temp = records[i];
					records[i] = records[j];
					records[j] = temp;
				}
			}
		}
	}else if(orderType == 'B' || orderType == 'b') {
		for(i=0; i<N; i++) {
			for(j=i+1; j<N; j++) {
				if(strcmp(records[i].page_no, records[j].page_no)>0) {
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
