/**
  *This program is implemented using Dynamic Programming.
**/


#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("-------------------------------------------------------------------\n    Programme to find length of longest increasing sequence  \n-------------------------------------------------------------------\n");
    int n,i,j,*a,*b,k;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    b = (int *)malloc(n*sizeof(int));
    printf("Enter the array...\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i] = 1;
    }
    int max = 0;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]<a[i]){
                k = b[j]+1;
                if(b[i]<k)
                    b[i] = k;
            }
        }
        if(max<b[i])
            max = b[i];
    }
    printf("The length of the longest monotone increasing subsequence is: %d\n",max);
    return 0;
}
