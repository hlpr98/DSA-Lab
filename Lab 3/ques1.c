#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *link;
}*root;
int n=0;

void display(){
	struct Node *ptr=NULL;
	ptr = root;
	int i=1;
	printf("...................\nThe list is..\n");
	ptr = root;
	while(ptr->link!=NULL){
		printf("%d. %d	  ",i++,ptr->data);
		ptr = ptr->link;
	}
	printf("%d. %d\n...................\n",i,ptr->data);	
	
}

void insert(int pos){
	int i,j;
	struct Node *ptr=NULL,*p;
	if(pos==1){
		printf("Enter the data: ");
		scanf("%d",&j);
		ptr = (struct Node *)malloc(sizeof(struct Node));
		ptr->link = root;
		root = ptr;
		ptr->data = j;
		n = n+1;
	}
	
	else if(pos==n){
		printf("Enter the data: ");
		scanf("%d",&j);
		ptr = (struct Node *)malloc(sizeof(struct Node));
		p=root;
		while(p->link!=NULL){
			p=p->link;
		}		
		ptr->link = NULL;
		ptr->data = j;
		p->link = ptr;
		n = n+1;
	}
	else{
		printf("Enter the data: ");
		scanf("%d",&j);
		ptr = (struct Node *)malloc(sizeof(struct Node));
		p = root;
		for(i=1;i<pos-1;i++){
			p = p->link;
		}
		ptr->data = j;
		ptr->link = p->link;
		p->link = ptr;
		n = n+1;
	}
	printf("...................\nAfter inserting\n");
	display();
}

void delete(int pos){
	int i,j;
	
	struct Node *ptr=NULL,*p;
	if(pos==1){
		root = root->link;
		n = n-1;
		
	}
	
	else if(pos==n){
		ptr = root;
		p=root->link;
		while(p->link!=NULL){
			ptr = ptr->link;
			p=p->link;
		}		
		ptr->link = NULL;
		n = n-1;
	}
	else{
		p = root;
		for(i=1;i<pos-1;i++){
			p = p->link;
		}
		p->link = p->link->link;
		n = n-1;
	}
	printf("...................\nAfter deleting\n");
	display();
		
	
}


void sort(){
	int i,j,temp,flag;
	struct Node *ptr,*p;
	ptr = root;
	for(i=0;i<n;i++){
		p = root;
		flag = -1;
		for(j=0;j<n-i-1;j++){
			if(p->data>p->link->data){
				temp = p->data;
				p->data = p->link->data;	
				p->link->data = temp;
				flag = 10;			
			}
			p=p->link;

		}
		if(flag==-1)
			break;
		
	}
	printf("...................\nAfter sorting\n");
	display();
		

}

void swapAlter(){
	int i,temp;
	struct Node *ptr,*p;
	p = root;
	ptr = root;
	for(i=0;i<n-3;i++){
		temp = p->data;
		p->data = p->link->data;
		p->link->data = temp;
		p = p->link->link;
		if(p == NULL || p->link==NULL)
			break;
			
	}
	printf("...................\nAfter swapping\n");
	display();
}


void main(){
	int i,j,k;
	struct Node *ptr=NULL,*ptrDum=NULL,*p=NULL;
	printf("Enter the no of nodes:  ");
	scanf("%d",&n);
	printf("Enter the data\n");
	for(i=0;i<n;i++){
		if(i==0){
			ptr = (struct Node *)malloc(sizeof(struct Node));
			root = ptr;
			root->link = NULL;
			scanf("%d",&root->data);
		}
		else{
			ptr = (struct Node *)malloc(sizeof(struct Node));
			ptr->link = NULL;
			scanf("%d",&ptr->data);
			ptrDum->link = ptr;
			
		}

		ptrDum = ptr;
	}
	
	display();		
			
	while(1){			
		printf("...................\nEnter your choice..\n1.Insert\t\t2.Delete\n3.Sort the Elements\t4.k th smallest\n5.k th largest\t\t6.Swap alternate values\n7.Exit\nYour choice...  ");
		scanf("%d",&i);
		switch(i){
			case 1:
				printf("...................\nEnter your choice..\n1.Insert at beginning\n2.Insert in end\n3.Insert at a given position\nYour choice..  "); 			scanf("%d",&j);
				if(j==1)
					insert(1);
				else if(j==2)
					insert(n);	
				else if(j==3){
					printf("Enter the position\n");
					scanf("%d",&k);
					insert(k);
				}
				else
					printf("...................\nWrong index... Try again later\n");
				break;
		
			case 2:
				printf("...................\nEnter your choice..\n1.Delete at beginning\n2.Delete at end\n3.Delete at a given position\nYour choice..  "); 			scanf("%d",&j);
				if(j==1)
					delete(1);
				else if(j==2)
					delete(n);	
				else if(j==3){
					printf("Enter the position\n");
					scanf("%d",&k);
					delete(k);
				}
				else
					printf("...................\nWrong index... Try again later\n");
				break;
			case 3:
				sort();
				break;
			case 4:
				
				printf("...................\nEnter k:  ");
				scanf("%d",&k);
				if(k>n){
					printf("...................\nNo such element present\n");
					break;
				}
				sort();
				p = root;
				for(j=0;j<k-1;j++){
					p = p->link;
				}
				printf("...................\nThe k th smallest is: %d\n",p->data);
				break;
			case 5:
				printf("...................\nEnter k:  ");
				
				scanf("%d",&k);
				if(k>n){
					printf("...................\nNo such element present\n");
					break;
				}
				sort();
				p = root;
				for(j=0;j<n-k;j++){
					p = p->link;
				}
				printf("...................\nThe k th largest is: %d\n",p->data);
				break;
			case 6:
				swapAlter();
				break;
				
			case 7:
				printf("...................\nThe program is terminated\n...................\n");
				exit(0);
				break;
			default:
				printf("Wrong index... Try again\n...................\n");
				break;
		}
	}
				
}
