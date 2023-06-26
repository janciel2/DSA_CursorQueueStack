#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CursorQueueStack.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackList myStack;
	VirtualSpace myVs;
	Queue myQueue;
	Product p;
	Date nd;
	
	bool pushtry, poptry;
	initVS(&myVs);
	initStack(&myStack);
	initQueue(&myQueue);
	
	int i, choice, men = 1, top, frontval;
	String menu[10] = {"Create A New Product", "Push", "Pop", "Peek",
					"Enqueue", "Dequeue",
					"Front", "Display Stack", "Display Queue", 
					"Visualize"	
	};
	
	/* VARIABLES FOR INSERTION */
	int prodId, qty, month, date, year, prodCount = 0;
	String prodName;
	double prodPrice;
	/* ....................... */
	
	while(men != 0)
	{
			system("cls");
			printf("MENU");
			printf("\n----------\n");
			for(i = 0; i < 10; i++)
				{
		
					printf("[%d] %s\n", i+1, menu[i]);
				}
			
			if(prodCount != 0)
				{
					printf("\n\n[YOU HAVE A PRODUCT THAT IS WAITING TO BE INSERTED]: <INSERT IT USING ENQUEUE OR PUSH>\n\n");
				}
			printf("[input the number of your choice <0 to exit the program>]: ");
			scanf("%d", &choice);
			
				switch(choice)
					{
						case 1: if(prodCount == 0)
									{
										printf("\nCREATE A NEW PRODUCT\n");
										printf("[INPUT PRODUCT ID]: ");
										scanf("%d", &prodId);
								
										printf("\n[INPUT PRODUCT NAME]: ");
										fflush(stdin);
										gets(prodName);
								
										printf("[INPUT PRODUCT QUANTITY]: ");
										scanf("%d", &qty);

										printf("[INPUT PRODUCT PRICE]: ");
										scanf("%lf", &prodPrice);
				
										printf("\nINPUT EXPIRATION DATE\n");
										printf("----------------------");
	
										printf("\n[INPUT MONTH] <NOTE THAT NUMBERING STARTS AT 0[JANUARY]>: ");
										scanf("%d", &month);

										printf("\n[INPUT DATE]: ");
										scanf("%d", &date);

										printf("\n[INPUT YEAR]: ");
										scanf("%d", &year);
								
										nd = newDate(date, month, year);
										p = newProduct(prodId, prodName, qty, prodPrice, nd);
								
										if(p.prodID != EMPTY)
											{
												printf("\nSUCCESSFULLY CREATED!~!\n");
												prodCount++;
											}
									}
								else
									{
										printf("\n[YOU STILL HAVE A PRODUCT THAT IS WAITING TO BE INSERTED]: INSERT IT USING PUSH OR ENQUEUE FIRST!\n\n");
									}

								break;
						
						case 2: printf("\nPUSH\n");
						
								if(prodCount != 0)
									{
										pushtry = push(&myVs, &myStack, p);
											if(pushtry)
												{
													printf("\nSUCCESSFULLY INSERTED. . .\n\n");
													prodCount--;
												}
											else
												{
													printf("\nUNSUCCESSFUL. . .\n\n");
												}
									}
								else
									{
										printf("\nNO NEW PRODUCT CREATED[CREATE A NEW PRODUCT FIRST] . . . \n\n");
									}
								
								
								break;
								
						case 3: printf("\nPOP\n");
								poptry = pop(&myVs, &myStack);
									if(poptry)
												{
													printf("\nSUCCESSFULLY POPPED. . .\n\n");
													prodCount--;
												}
											else
												{
													printf("\nUNSUCCESSFUL. . .\n\n");
												}
								break;
						
						case 4: printf("\nPEEK\n");
								peekTop(myVs,myStack);
								break;
						
						case 5: printf("\nENQUEUE\n");
								if(prodCount != 0)
									{
										pushtry = enqueue(&myVs, &myQueue, p);
											if(pushtry)
												{
													printf("\nSUCCESSFULLY INSERTED. . .\n\n");
													prodCount--;
												}
											else
												{
													printf("\nUNSUCCESSFUL. . .\n\n");
												}
									}
								else
									{
										printf("\nNO NEW PRODUCT CREATED[CREATE A NEW PRODUCT FIRST] . . . \n\n");
									}
								break;
						
						case 6: printf("\nDEQUEUE\n");
									poptry = dequeue(&myVs, &myQueue);
									if(poptry)
												{
													printf("\nSUCCESSFULLY DEQUEUED. . .\n\n");
													prodCount--;
												}
											else
												{
													printf("\nUNSUCCESSFUL. . .\n\n");
												}
								break;
								
						case 7: printf("\nFRONT\n");
								front(myVs,myQueue);
								break;
								
						case 8: printf("\nDISPLAY STACK\n");
								displayStack(myVs, myStack);
								break;
							
						case 9: printf("\nDISPLAY QUEUE\n");
								displayQueue(myVs, myQueue);
								break;
						
						case 10: printf("\nVISUALIZE\n");
								visualizeSpace(myVs);
								break;
						
						case 0: printf("\nTHANK YOU FOR USING THE PROGRAM\n");
								men = 0;
								break;
								
						default: printf("\nINVALID OPTION . . .\n");
					}
			
			system("pause");
	}

	
	

	
	
	

	
	return 0;
}
