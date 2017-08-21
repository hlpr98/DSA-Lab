#include<stdio.h>
void main(){

    int *ptr,*root,*rootDup,i,n,j;
    printf("Give the no of data points\n"):
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));
    root = ptr;
    rootDup = root;
    printf("Enter the data points\n");
    
    for(i=0;i<n;i++){
        scanf("%d",ptr);
        ptr++;
    }
    
    ptr = root;
    
    for(i=0;i<n;i++){
        ptr = root;
        int min = *ptr;
        int pos = i;
        for(j=i;j<n;j++){
            if(*ptr<min){
                min = *ptr;
                pos = j;
            }
            ptr++;
        }
        int swap = *root;
        *root = min;
        ptr = rootDup + pos;
        *ptr = swap;
        root++;
    }
    ptr = rootDup;
    printf("Data in ascending order...\n");
    for(i=0;i<n;i++){
        printf("%d",*ptr);
        ptr++;
    }
}
        
        
