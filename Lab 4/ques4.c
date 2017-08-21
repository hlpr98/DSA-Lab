#include<stdio.h>
struct Node{
	int data;
	struct Node *link;


};
struct Node *root = NULL;

int n=0;


int FindLoop(){
    struct Node *slow,*fast;
    int i;
    slow = fast = root;
    while(slow&&fast&&fast->link){
        slow = slow->link;
        fast = fast->link->link;
        if(slow == fast){
            return findPos(slow);
        }


    }
    return -1;

}

int findPos(struct Node *inLoop){
    int k = 1,i;
    struct Node *ptr,*p;
    ptr = inLoop;
    //printf("\nThe nodes in the loop: \n");
    while(1){
        if(ptr->link == inLoop)
            break;
        //printf("%d. %d  ",k,ptr->data);
        ptr = ptr->link;
        k++;


    }
    //printf("%d. %d\n",k,ptr->data);
    ptr = root;
    p = root;
    printf("\nThe no of Nodes in the loop: %d\n",k);
    for(i = 1;i<k;i++){
        ptr = ptr->link;

    }
    k=1;
    while(1){
        ptr = ptr->link;
        p = p->link;
        k++;
        if(p==ptr->link)
            break;
    }
    ptr = p;
    i = k;
    printf("The nodes in the loop: \n");
    while(1){
        printf("%d  ",i++);
        ptr = ptr->link;
        if(ptr==p)
            break;
    }
    return k;
}
void main(){
	int i,j,k;
	struct Node *ptr,*p,*key;
	printf("Enter the no of node: ");
	scanf("%d",&n);
	printf("Enter which node should the loop start from or Enter -1 for no loop: ");
	scanf("%d",&k);
	printf("Enter the data: \n");
	for(i=1;i<=n;i++){
		ptr =(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&ptr->data);
		//ptr->link = root;

		if(i==1){
			ptr->link = NULL;
			root = ptr;

		}
		else{
			ptr->link = NULL;
			p->link = ptr;

		}

		p = ptr;
		if((k>-1)&&(i==(k-1))){

           key = p;
		}
	}

	//printf("%d\n",key->data);
	if(k!=-1)
        p->link = key->link;
	//printf("%d\n",p->link->data);

	int pos = FindLoop();
	if( pos != -1)
        printf("\n\nA loop was found, its starts from the node no: %d\n",pos);
    else
        printf("\nNo loop was found\n");


}
