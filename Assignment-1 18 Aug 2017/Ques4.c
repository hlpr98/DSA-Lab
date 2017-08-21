/**
  *I have implemented this program by forming a
  *recursive tree, which in each step evaluates
  *cubic power, as follows.
  *               a^x
  *        /       |       \
  *     a^(x/3)  a^(x/3)  a^(x/3)
  *            /    |    \
  *        a^(x/9) a^(x/9) a^(x/9)
  *             and so on...
  *Hence this tree has log(x) to base 3,
  *rather than log(x) to base 2, which is the
  *case in base 2 evaluation. 
  *
  *The base-2 complexity = log(x) to base 2
  *The base-3 complexity = 2(log(x) to base 3)
  *
  *Hence upto certain small value ... base-3 id slower than base-2
 **/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int power1(int a,int x){
    int temp;
    if(x==0)
        return 1;
    temp = power1(a,x/2);
    if(x%2==0)
        return temp*temp;
    else if(x%2==1)
        return temp*temp*a;
    
    return -1;

}

int power(int a,int x){
    int temp;
    if(x==0)
        return 1;
    temp = power(a,x/3);
    if(x%3==0)
        return temp*temp*temp;
    else if(x%3==1)
        return temp*temp*temp*a;
    else if(x%3==2)
        return temp*temp*temp*a*a;
    return -1;

}


void main(){
    int a,x;
    printf("--------------------------------------------\n     Programme to find a^x in base 3    \n--------------------------------------------\n");
    printf("Enter the base(i.e a): ");
    scanf("%d",&a);
    printf("Enter the exponent(i.e x): ");
    scanf("%d",&x);
    clock_t start = clock(),diff;
    int ans1 = power(a,x);
    diff = clock() - start;
    printf("\nThe value of a^x in base 3: %d\nTime of Execution = %ld microseconds\n\n",ans1,diff);
    start = clock();
    int ans2 = power1(a,x);
    diff = clock() - start;
    
    printf("The value of a^x in base 3: %d\nTime of Execution = %ld microseconds\n\n",ans2,diff);
}
