#include<stdio.h>
void main(){
    int *ptr,n,i,j;
    printf("Give the no of data points\n");
    scanf("%d",&n);
    ptr = (int*)malloc(n*sizeof(int));
    printf("Give the data points\n");
    for(i=0;i<n;i++){
        scanf("%d",ptr);
        ptr++;
    }
    ptr = ptr-n;
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(*ptr>*(ptr+1)){
                int swap = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = swap;
            }
            ptr++;
        }
        ptr = ptr-(n-i-1);   
     }
     
     printf("Arranged in ascending order ...\n");
     for(i=0;i<n;i++){
        printf("%d\n",*ptr);
        ptr++;
    }
}
