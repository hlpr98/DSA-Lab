#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *link;


};
struct Node *root = NULL;

int n=0;
struct Node* XOR(struct Node *curr,struct Node *prev){
    struct Node* next;
    next = (struct Node *)((unsigned int)curr^(unsigned int)prev);
    return next;

}
void display(){
	struct Node *curr,*prev,*preDup;

	int i=1;
	curr = root;
	prev = NULL;
	/*if((struct Node *)(((unsigned int)ptr->link)^(unsigned int)p) != NULL){
		ptr = (struct Node *)(((unsigned int)ptr->link)^(unsigned int)p);
		printf("%d. %d*****\n	  ",i++,ptr->data);
	}*/
	printf("...................\nThe list in given order is..\n");

	while(i<n){
            printf("%d. %d    ",i++,curr->data);
            preDup = prev;
            prev = curr;
            curr = XOR(curr->link,preDup);


	}
    printf("%d. %d\n\n",i,curr->data);
    printf("The list in reverse order is(traversed backward)..\n");

    i=1;
    prev = NULL;
    while(i<n){
            printf("%d. %d    ",i++,curr->data);
            preDup = prev;
            prev = curr;
            curr = XOR(curr->link,preDup);


	}
    printf("%d. %d\n...................\n",i,curr->data);

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
		//ptr->link = root;

		if(i==0){
			ptr->link = XOR(root,NULL);
			root = ptr;

		}
		else{
			ptr->link = XOR(p,NULL);
			p->link = XOR(XOR(p->link,NULL),ptr);

		}
		p = ptr;
	}

	display();
}

