#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r){
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
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
    mergeSort(a,0,n-1);
    printf("The k th smallest no is: %d\n",a[k-1]);
    return 0;
}
