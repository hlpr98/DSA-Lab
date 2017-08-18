#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int count = 0;
void transfer(int n,char from, char to, char temp){
    if(n>0){
        transfer(n-1,from,temp,to);
        count++;
        printf("Step %d: Move disk %d from %c to %c\n",count,n,from,to);
        transfer(n-1,temp,to,from);
    }

}

int main(){
    int n;
    printf("-------------------------------------------\n    Programme to solve Tower Of Hanoi  \n-------------------------------------------\n");

    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("The steps to solve are(assuming the 3 towers are, \'L\'-Left  \'R\'-Right  \'C\'-Center:-  \n");
    transfer(n,'L','R','C');


    return 0;
}
