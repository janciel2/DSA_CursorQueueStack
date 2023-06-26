#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "CursorQueueStack.h"

void initVS(VirtualSpace *vs)
{
	(*vs).avail = 0;
	int i;
	Date d;	
	for(i = 0; i < MAX; i++)
		{
			(*vs).data[i].link = i + 1;
			(*vs).data[i].items = newProduct(EMPTY, EMPTYSTRING, EMPTY, EMPTYPRICE, d = newDate(EMPTY, EMPTY, EMPTY));
		}
	(*vs).data[i - 1].link = -1;
}

void initStack(StackList *s)
{
	(*s) = -1;	
}



void initQueue(Queue *q)
{
	(*q).front = (*q).rear = -1;
  	
}


Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp)
{
	Product p;
	p.prodID = prodID;
	strcpy(p.prodName, prodName);
	p.prodQty = prodQty;
	p.prodPrice = prodPrice;
	p.prodExp = prodExp;
	
	return p;	
}


Date newDate(int date, int month, int year)
{
	Date nd;
	nd.date = date;
	nd.month = month;
	nd.year = year;
	
	return nd;
}

bool push(VirtualSpace *vh, StackList *s, Product p)
{
	bool push = false;
	int temp;
	if((*vh).avail != -1)
		{
		  temp = allocSpace(vh);
		  (*vh).data[temp].items = p;
		  (*vh).data[temp].link = (*s); 
		  (*s) = temp;
		  push = true;
		}
	return push;
}

bool pop(VirtualSpace *vs, StackList *s)
{
	int i, trav, temp;
	bool popped = false;
	if((*s) !=  -1) // we can pop if the space is not empty;
		{
			temp = (*vs).data[(*s)].link;
			deAllocSpace(vs, *s);
			popped = true;
		}
	(*s) = temp;
	return popped;
}

void peekTop(VirtualSpace vs,StackList l)
{
	int i;
	String month = EMPTYSTRING;
	i = l;
	printf("%10s | %30s | %10s | %10s | %20s\n", "Product ID", "Product Name", "Qty", "Price", "Expiration");
	printf("--------------------------------------------------------------------------------------------\n");
	
	if(!isEmptyStack(l))
	{
		printf("%10d | %30s | %10d | %10.2lf | ",vs.data[i].items.prodID, vs.data[i].items.prodName, vs.data[i].items.prodQty, vs.data[i].items.prodPrice);
				if(vs.data[i].items.prodExp.month == 0)
					{
						strcpy(month, "January");
						printf(" %10s -", month);
					}
				
				if(vs.data[i].items.prodExp.month == 1)
					{
						strcpy(month, "February");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 2)
					{
						strcpy(month, "March");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 3)
					{
						strcpy(month, "April");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 4)
					{
						strcpy(month, "May");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 5)
					{
						strcpy(month, "June");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 6)
					{
						strcpy(month, "July");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 7)
					{
						strcpy(month, "August");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 8)
					{
						strcpy(month, "September");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 9)
					{
						strcpy(month, "October");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 10)
					{
						strcpy(month, "November");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 11)
					{
						strcpy(month, "December");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == EMPTY)
					{
						strcpy(month, "EMPTY");
						printf(" %10s -", month);
					}
				printf(" %d - %d\n", vs.data[i].items.prodExp.date, vs.data[i].items.prodExp.year);
	}
	
	else
	{
		printf("\nTHE LIST IS EMPTY\n\n");
	}
printf("--------------------------------------------------------------------------------------------\n");
}

bool enqueue(VirtualSpace *vh, Queue *q, Product p)
{
	int temp, i;
	bool inserted = false;
	if((*vh).avail != -1)
		{
			temp = allocSpace(vh);
				if((*q).rear == -1)
					{
						(*vh).data[temp].items = p;
						(*vh).data[temp].link = (*q).rear;
						(*q).front = temp;
						(*q).rear = temp;	
						inserted = true;
					}
				
				else
					{
						for(i = (*q).rear; i != -1; i = (*vh).data[i].link){}
						
						(*vh).data[temp].items = p;
						(*vh).data[temp].link = i;
						(*vh).data[(*q).rear].link = temp;
						(*q).rear = temp;	
						inserted = true;
					}
		}	
	return inserted;
}
bool dequeue(VirtualSpace *vs, Queue *q)
{
	bool deleted = false;
	int temp;	
	if(!isEmptyQueue(*q))
		{
			temp = (*vs).data[(*q).front].link;
			deAllocSpace(vs, (*q).front);			
		}	
	(*q).front = temp;
}

bool isEmptyQueue(Queue q)
{
	return q.front == -1;
}

//bool isFullQueue(Queue q)
//{
//	return q.rear == MAX - 1;
//}

void front(VirtualSpace vs,Queue q)
{
	int i;
	String month = EMPTYSTRING;
	i = q.front;
	printf("%10s | %30s | %10s | %10s | %20s\n", "Product ID", "Product Name", "Qty", "Price", "Expiration");
	printf("--------------------------------------------------------------------------------------------\n");
	
	if(!isEmptyQueue(q))
	{
	printf("%10d | %30s | %10d | %10.2lf | ",vs.data[i].items.prodID, vs.data[i].items.prodName, vs.data[i].items.prodQty,vs.data[i].items.prodPrice);
				if(vs.data[i].items.prodExp.month == 0)
					{
						strcpy(month, "January");
						printf(" %10s -", month);
					}
				
				if(vs.data[i].items.prodExp.month == 1)
					{
						strcpy(month, "February");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 2)
					{
						strcpy(month, "March");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 3)
					{
						strcpy(month, "April");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 4)
					{
						strcpy(month, "May");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 5)
					{
						strcpy(month, "June");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 6)
					{
						strcpy(month, "July");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 7)
					{
						strcpy(month, "August");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 8)
					{
						strcpy(month, "September");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 9)
					{
						strcpy(month, "October");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 10)
					{
						strcpy(month, "November");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 11)
					{
						strcpy(month, "December");
						printf(" %10s -", month);
					}
				printf(" %d - %d\n", vs.data[i].items.prodExp.date, vs.data[i].items.prodExp.year);
	}
	
	else
	{
		printf("\nTHE QUEUE IS EMPTY\n\n");
	}
printf("--------------------------------------------------------------------------------------------\n");
}


void displayQueue(VirtualSpace vs, Queue q)
{
	int i;
	String month = EMPTYSTRING;
	printf("%10s | %30s | %10s | %10s | %20s\n", "Product ID", "Product Name", "Qty", "Price", "Expiration");
	printf("--------------------------------------------------------------------------------------------\n");
	for(i = q.front; i != -1; i = vs.data[i].link)
		{  
			if(vs.data[i].items.prodID != EMPTY)
				{			
				
				printf("%10d | %30s | %10d | %10.2lf | ",vs.data[i].items.prodID, vs.data[i].items.prodName, vs.data[i].items.prodQty, vs.data[i].items.prodPrice);
				if(vs.data[i].items.prodExp.month == 0)
					{
						strcpy(month, "January");
						printf(" %10s -", month);
					}
				
				if(vs.data[i].items.prodExp.month == 1)
					{
						strcpy(month, "February");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 2)
					{
						strcpy(month, "March");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 3)
					{
						strcpy(month, "April");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 4)
					{
						strcpy(month, "May");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 5)
					{
						strcpy(month, "June");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 6)
					{
						strcpy(month, "July");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 7)
					{
						strcpy(month, "August");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 8)
					{
						strcpy(month, "September");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 9)
					{
						strcpy(month, "October");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 10)
					{
						strcpy(month, "November");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 11)
					{
						strcpy(month, "December");
						printf(" %10s -", month);
					}
				printf(" %d - %d\n", vs.data[i].items.prodExp.date, vs.data[i].items.prodExp.year);
			} 
		}
												                                        
	
		
	printf("--------------------------------------------------------------------------------------------\n");
} 

bool isEmptyStack(int i)
{
	return i == -1;
				
}

//bool isFullStack(int i)
//{
//	return i == MAX - 1;
//}

void displayStack(VirtualSpace vs, StackList s)
{
	int i;
	String month = EMPTYSTRING;
	printf("%10s | %30s | %10s | %10s | %20s\n", "Product ID", "Product Name", "Qty", "Price", "Expiration");
	printf("--------------------------------------------------------------------------------------------\n");
	
	for(i = s; i != -1; i = vs.data[i].link)
		{
			if(vs.data[i].items.prodID != EMPTY)
			{
				if(vs.data[i].items.prodID != EMPTY)
				{			
				
				printf("%10d | %30s | %10d | %10.2lf | ",vs.data[i].items.prodID, vs.data[i].items.prodName, vs.data[i].items.prodQty, vs.data[i].items.prodPrice);
				if(vs.data[i].items.prodExp.month == 0)
					{
						strcpy(month, "January");
						printf(" %10s -", month);
					}
				
				if(vs.data[i].items.prodExp.month == 1)
					{
						strcpy(month, "February");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 2)
					{
						strcpy(month, "March");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 3)
					{
						strcpy(month, "April");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 4)
					{
						strcpy(month, "May");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 5)
					{
						strcpy(month, "June");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 6)
					{
						strcpy(month, "July");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 7)
					{
						strcpy(month, "August");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 8)
					{
						strcpy(month, "September");
						printf(" %10s -", month);
					}
					
				if(vs.data[i].items.prodExp.month == 9)
					{
						strcpy(month, "October");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 10)
					{
						strcpy(month, "November");
						printf(" %10s -", month);
					}
				if(vs.data[i].items.prodExp.month == 11)
					{
						strcpy(month, "December");
						printf(" %10s -", month);
					}
				printf(" %d - %d\n", vs.data[i].items.prodExp.date, vs.data[i].items.prodExp.year);
			}
			
		}
	}
	printf("--------------------------------------------------------------------------------------------\n");
}

void visualizeSpace(VirtualSpace vs)
{
	int i;
	
	printf("%5s | %15s | %10s\n", "INDEX", "DATA", "LINK");
	printf("------------------------------------\n");
	for(i = 0; i < MAX; i++)
		{
			if(vs.data[i].items.prodID != EMPTY)
				{
					printf("%5d |", i);
					printf("%5 | %d", vs.data[i].items.prodID);
					printf("%5 | %15 | %d", vs.data[i].link);
					
				}
			else if(vs.data[i].items.prodID == EMPTY)
				{
					printf("%5d |", i);
					printf("%5 | %15s", "EMPTY");
					printf("%5 | %15 | %d", vs.data[i].link);
				}
			printf("\n");
		}
	printf("------------------------------------\n");
}

int allocSpace(VirtualSpace *vh)
{
	int temp = -1;
	if((*vh).avail != -1)
		{
			temp = (*vh).avail;
			(*vh).avail = (*vh).data[(*vh).avail].link;
		}
	return temp;
}

void deAllocSpace(VirtualSpace *vh, int s)
{
	int temp;
	Date d;
	
	if((*vh).avail != 0)
		{
			//change the values to empty
			temp = s;
			(*vh).data[temp].items = newProduct(EMPTY, EMPTYSTRING, EMPTY, EMPTYPRICE, d = newDate(EMPTY, EMPTY, EMPTY));
			(*vh).data[temp].link = (*vh).avail;
			(*vh).avail = (temp);
		}
}
