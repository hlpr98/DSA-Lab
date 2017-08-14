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
		printf("%d. %d\n",i++,ptr->data);
		ptr = ptr->link;
	}
	printf("%d. %d\n...................\n",i,ptr->data);	
	
}

void delete(int pos){
	int i,temp;
	
	struct Node *ptr=NULL,*p;	
	if(pos<n){
		p = root;
		for(i=1;i<=pos-1;i++){
			p = p->link;
		}
		temp = p->data;
		p->data = p->link->data;
		p->link->data = temp;
		p->link = p->link->link;
		n = n-1;
		display();
	}
	else
		printf("...................\nThis is the last node, hence can\'t be deleted in this way\n...................\n");
}

void main(){
	int i,j,k;
	struct Node *ptr=NULL,*ptrDum=NULL;
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
	printf("Enter the node to be deleted\n");
	scanf("%d",&k);
	delete(k);

}
		
