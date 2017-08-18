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
  *case in base 2 evaluation. Hence this algorithm is faster.
**/

#include<stdio.h>
#include<stdlib.h>

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
    int ans = power(a,x);
    printf("The value of a^x is: %d\n",ans);
}