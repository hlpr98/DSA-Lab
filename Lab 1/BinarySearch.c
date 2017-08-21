#include<stdio.h>
void main(){
    int *ptr,*root,*rootDup,n,i,j,key;
    printf("Give the no data points\n");
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));
    root = ptr;
    rootDup = root;
    printf("enter the data points\n");
    for(i=0;i<n;i++){
        scanf("%d",ptr);
        ptr++;
    }
    
    ptr = root;
    printf("enter the \"KEY\" to be searched\n");
    scanf("%d",&key);
           
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
    root = rootDup;
    
    int min = 0;
    int max = n-1;
    int flag = -1;
    
    while(min<max){
        int mid = (int)((min+max)/2);
        if(key == *root){
            printf("The \"KEY\" entered has been found\n");
            flag = 0;
            break;
        }
        
        if(key == *(root+n-1)){
            printf("The \"KEY\" entered has been found\n");
            flag = 0;
            break;
        }
        
        
        if(key<*(ptr+mid)){
            max = mid-1;
        }
        else if(key>*(ptr+mid)){
            min = mid+1;
        }
        else if(key == *(ptr+mid)){
            printf("The \"KEY\" entered has been found\n");
            flag = 0;
            break;
        }
    }
    
    if(flag !=0){
        printf("The \"KEY\" wasn't found\n");
    }
}
        
        
        
    
    
    
    
    
    
    
    
    
