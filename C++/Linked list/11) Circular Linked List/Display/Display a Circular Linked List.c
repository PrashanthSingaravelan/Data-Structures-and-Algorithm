#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;	
}*head;

void Create(int A[],int n)
{
	struct Node *last;
	head=(struct Node*)malloc(sizeof(struct Node));	
	head->data=A[0];
	head->next=head;
	last=head;
	
	int i;
	for(i=1;i<n;i++)
	{
		struct Node *t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
		
void Display(struct Node *ptr)
 {
 	do
 	{
 		printf("%d ",ptr->data);
 		ptr=ptr->next;
	 }while(ptr!=head); 	
 }
 
 void RecursiveDisplay(struct Node *ptr)
{
	static int flag=0;
    if(flag==0 || ptr!=head)
	{
		flag=1;
		printf("%d ",ptr->data);
		RecursiveDisplay(ptr->next);
	}	
}
 
 int main()
 {
 	int A[5]={12,23,34,45,56};
 	Create(A,5);
 	
 	printf("Iterative Display : ");
 	Display(head);
 	
 	printf("\nRecursive Display : ");
 	RecursiveDisplay(head);
 }
