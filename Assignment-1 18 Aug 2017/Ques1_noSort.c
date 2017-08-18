/**
  *In this program I have used Random QuickSelect
  *algorithm. In this algorithm I use QuickSort's partition
  *but it is done about a randomly chosen pivot, whose position
  *in the sorted array is determined at the end of the partition.
  *This process continues only until we get the k th smallest element's
  *position.This algorithm has a Worst case complexity of O(n^2),
  *an average complexity of "theta(n)".
**/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



int randomPartition(int arr[],int l,int r);

int smallest(int arr[],int l,int r,int k){
    if (k > 0 && k <= r - l + 1){
        int pos = randomPartition(arr, l, r);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return smallest(arr, l, pos-1, k);
        return smallest(arr, pos+1, r, k-pos+l-1);
    }

    return 100000000000;

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int x = arr[r], i = l;
    int j;
    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}


int randomPartition(int arr[], int l, int r){
    int n = r-l+1;
    srand((unsigned)time(NULL));
    int pivot = rand() % n;
    swap(&arr[1 + pivot], &arr[r]);
    return partition(arr, l, r);
}

int main(){
    printf("---------------------------------------------------\n    Programme to find k th smallest number  \n---------------------------------------------------\n");
    int n,i,j,*a,k;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    printf("Enter the array...\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter k: ");
    scanf("%d",&k);
    j = smallest(a,0,n-1,k);
    printf("The k th smallest no is: %d\n",j);
    return 0;
}
