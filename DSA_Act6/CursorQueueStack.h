#ifndef CURSOR_QUEUE_H
#define CURSOR_QUEUE_H
#define MAX 20
#define EMPTY 9999999
#define EMPTYSTRING ""
#define EMPTYPRICE 0.00

#include <stdbool.h>

typedef char String[100];
typedef int StackList;

typedef struct
{
	int date;
	int month;
	int year;
} Date;

typedef struct{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
} Product;

typedef struct{
	Product items;
	int link; //link
} Stype;

typedef struct{
	Stype data[MAX];
	int avail;
} VirtualSpace;

typedef struct{
	int front;
	int rear;
} Queue;

void initStack(StackList *s);
void initQueue(Queue *q);
void initVS(VirtualSpace *vs);

Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);
Date newDate(int date, int month, int year);

bool push(VirtualSpace *vh, StackList *s, Product p);
bool pop(VirtualSpace *vs, StackList *s);
void peekTop(VirtualSpace vs,StackList l);

bool enqueue(VirtualSpace *vh, Queue *q, Product p);
bool dequeue(VirtualSpace *vs, Queue *q);
void front(VirtualSpace vs,Queue q);


void displayQueue(VirtualSpace vs, Queue q);
void displayStack(VirtualSpace vs, StackList s);

bool isEmptyStack(int i);
bool isFullStack(int i);
bool isEmptyQueue(Queue q);
bool isFullQueue(Queue q);

int allocSpace(VirtualSpace *vh);
void deAllocSpace(VirtualSpace *vh, int s);
void visualizeSpace(VirtualSpace vs);


#endif
