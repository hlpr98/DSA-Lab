#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *left;
	struct Node *right;

};
struct Node *root = NULL;
struct Node *foot = NULL;

int n=0;

void display(){
	struct Node *ptr=NULL;
	ptr = root;
	int i=1;
	printf("...................\nThe list is..\n");
	ptr = root;
	while(ptr->right!=root){
		printf("%d. %d	  ",i++,ptr->data);
		ptr = ptr->right;
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
		ptr->right = root;
		root->left = ptr;
		root = ptr;
		ptr->data = j;
		ptr->left = NULL;
		foot->right = root;
		n = n+1;
	}
	
	else if(pos==n){
		printf("Enter the data: ");
		scanf("%d",&j);
		ptr = (struct Node *)malloc(sizeof(struct Node));
		p=root;
		while(p->right!=root){
			p=p->right;
		}
		
		ptr->right = root;
		foot = ptr;
		ptr->data = j;
		p->right = ptr;
		ptr->left = p;
		n = n+1;
	}
	else{
		printf("Enter the data: ");
		scanf("%d",&j);
		ptr = (struct Node *)malloc(sizeof(struct Node));
		p = root;
		for(i=1;i<pos-1;i++){
			p = p->right;
		}
		printf("%d\n",p->data);
		ptr->data = j;
		ptr->right = p->right;
		ptr->left = p;
		p->right->left = ptr;
		p->right = ptr;
		n = n+1;
	}
	printf("...................\nAfter inserting\n");
	display();
}

void delete(int pos){
	int i,j;
	
	struct Node *ptr=NULL,*p;
	if(pos==1){
		root->right->left = foot;
		root = root->right;
		foot->right = root;
		n = n-1;
		
	}
	
	else if(pos==n){
		ptr = root;
		p=root->right;
		while(p->right!=root){
			ptr = ptr->right;
			p=p->right;
		}		
		ptr->right = root;
		foot = ptr;
		n = n-1;
	}
	else{
		p = root;
		for(i=1;i<pos-1;i++){
			p = p->right;
		}
		p->right->right->left = p;
		p->right = p->right->right;
		n = n-1;
	}
	printf("...................\nAfter deleting\n");
	display();
		
	
}
void main(){
	int i,j,k;
	struct Node *ptr,*p;
	printf("Enter the no of node: ");
	scanf("%d",&n);
	printf("Enter the data: \n");
	for(i=0;i<n;i++){
		ptr =(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&ptr->data);
		ptr->right = root;
		foot = ptr;
		if(i==0){
			ptr->left = foot;
			root = ptr;
			ptr->left = NULL;
		}
		else{
			ptr->left = p;
			p->right = ptr;
			
		}	
		p = ptr;
	}
	
	display();		
			
	while(1){			
		printf("...................\nEnter your choice..\n1.Insert\t\t2.Delete\n3. Exit\nYour choice...  ");
		scanf("%d",&i);
		switch(i){
			case 1:
				printf("...................\nEnter your choice..\n1.Insert at beginning\n2.Insert in end\n3.Insert at a given position\nYour choice..  "); 			
				scanf("%d",&j);
				if(j==1)
					insert(1);
				else if(j==2){
					
				
					insert(n);	
					}
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
				printf("...................\nThe program is terminated\n...................\n");
				exit(0);
				break;
			default:
				printf("Wrong index... Try again\n...................\n");
			break;
			}
		}

}
