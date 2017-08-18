/**
  *Here the only extra memory is used by
  *variable "sum".
**/

#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("---------------------------------------------------\n    Programme to find the missing number  \n---------------------------------------------------\n");
    int n,i,*a,sum=0;
    printf("Enter the size of the array(i.e \"n-1\"): ");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));

    printf("Enter the array...\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum = sum+a[i];
    }
    printf("The missing number is: %d\n",(n*(n+1)/2)-sum);
}
