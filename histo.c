#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}Node;

void push(Node **top, int value)
{
	Node* n=(Node *)malloc(sizeof(Node));
	n->val = value;
	n->next= *top;
	*top = n;
}
void pop(Node **top)
{
	Node* temp=*top;
	(*top)=(*top)->next;
	free(temp);
	temp=NULL;
}
int peek(Node** top)
{
	return (*top)->val;
}
int isEmpty(Node** top)
{
	if(*top == NULL)
	return 1;
	
	return 0;
}
int main()
{
	Node* newnode = NULL;
	int n;
	printf("Enter size of histogram : \n");
	scanf("%d",&n);
	int a[n];
	int i;
	printf("Enter length of each histo : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	Node* top=NULL;
	int j;
	int max=0;
	for(i=0;i<n;i++)
	{
		if(isEmpty(&newnode) || a[i]>a[newnode->val])
		{
			push(&newnode,i);
		}
		else
		{
			while(!isEmpty(&newnode) && a[i]<a[peek(&newnode)])
			{
				int x=a[peek(&newnode)];
				pop(&newnode);
				int y = isEmpty(&newnode) ? i : (i-peek(&newnode)-1);
				int ar = y*x;
				if(max<ar)
				max=ar;
			}
			push(&newnode,i);
		}
	}
	while(!isEmpty(&newnode))
	{
		int x = a[peek(&newnode)];
		pop(&newnode);
		int y = isEmpty(&newnode) ? i : (i-peek(&newnode)-1);
		int ar = y*x;
		if(max<ar)
		max=ar;
	}
	printf(" Max area of histogram rectangle is : %d",max);
return 0;
}
