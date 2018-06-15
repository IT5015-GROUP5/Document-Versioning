
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
void sortBookNum(records, orderType);
void sortPageNum(records, orderType);
void sortTitle(records, orderType);
void sortISBN(records, orderType);
void sortContents(records, orderType);
void sortAuthor(records, orderType);

int main()
{
	records book_record;

	return 0;
}

void sort(records data[])
{
	//option panel
	//switch case for the chosen option
}


