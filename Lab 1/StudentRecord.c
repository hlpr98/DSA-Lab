#include<stdio.h>
#include<string.h>

struct record{
    char name[20];
    int roll;
    int mark[3];
    int avg;
}rec[100];

int n;
void display(){
    int i;
    printf("Sl No.      Name        Roll        Marks1  Marks2  Marks3      Avg\n");
    for(i=0;i<n;i++){
        printf("%d              %s      %d      %d      %d      %d          %d\n",i+1,rec[i].name,rec[i].roll,rec[i].mark[0],rec[i].mark[1],rec[i].mark[2],rec[i].avg);
    }
}


void sort(){
    int i,j,flag = -1;
    for(i=0;i<n;i++){
        flag = -1;
        for(j=0;j<n-i-1;j++){
            if((strcmp(rec[j].name,rec[j+1].name))>0){
                struct record swap = rec[j];
                rec[j] = rec[j+1];
                rec[j+1] = swap;
                flag = 0;
            }
            
        }
        if(flag == 0)
            continue;
        else 
            break;
    }
    printf("The udated record is.... \n");
    display();   

}


void insert(){
    int i;
    printf("Enter the new record to be filled in\n");
    n=n+1;
            printf("Name ... ");
            
            scanf("%s",rec[n-1].name);
            printf("\n");
            printf("Roll ... ");
            scanf("%d",&rec[n-1].roll);
            printf("\n");
            printf("Marks 1 ...");
            scanf("%d",&rec[n-1].mark[0]);
            printf("\n");
            printf("Marks 2 ...");
            scanf("%d",&rec[n-1].mark[1]);
            printf("\n");
            printf("Marks 3 ...");
            scanf("%d",&rec[n-1].mark[2]);
            printf("\n");
            rec[n-1].avg = (rec[n-1].mark[0]+rec[n-1].mark[1]+rec[n-1].mark[2])/3;
    
    printf("The udated record is.... \n");
    display();   

}



void modify(){
    printf("Enter the index of the record to be modified\n");
    int i;
    scanf("%d",&i);
    printf("Enter the updated record at that place\n");
            printf("Name ... ");
           
            scanf("%s",rec[i-1].name);
            printf("\n");
            printf("Roll ... ");
            scanf("%d",&rec[i-1].roll);
            printf("\n");
            printf("Marks 1 ...");
            scanf("%d",&rec[i-1].mark[0]);
            printf("\n");
            printf("Marks 2 ...");
            scanf("%d",&rec[i-1].mark[1]);
            printf("\n");
            printf("Marks 3 ...");
            scanf("%d",&rec[i-1].mark[2]);
            printf("\n");
            rec[i-1].avg = (rec[i-1].mark[0]+rec[i-1].mark[1]+rec[i-1].mark[2])/3;
   printf("The udated record is.... \n");
    display();   
  
    

}



void delete(){
    int j,i;
    printf("Enter the index of the record to be deleted\n");
    scanf("%d",&i);
    for(j=i-1;j<n-1;j++){
        rec[j] = rec[j+1];
    }
    n=n-1;
    printf("The udated record is.... \n");
    display();   

}


void main(){
       int i,j;
       struct record *ptr = NULL;
       printf("Give the no of records to be entered\n");
       scanf("%d",&n);
       //ptr = (struct record*)malloc(n*sizeof(struct record));
       //root = ptr;
       printf("Enter the records\n");
       for(i=0;i<n;i++){
            printf("Record %d..........\n",i+1);
            printf("Name ... ");
            
           
            scanf("%s",rec[i].name);
            printf("\n");
            printf("Roll ... ");
            scanf("%d",&rec[i].roll);
            printf("\n");
            printf("Marks 1 ...");
            scanf("%d",&rec[i].mark[0]);
            printf("\n");
            printf("Marks 2 ...");
            scanf("%d",&rec[i].mark[1]);
            printf("\n");
            printf("Marks 3 ...");
            scanf("%d",&rec[i].mark[2]);
            printf("\n");
            rec[i].avg = (rec[i].mark[0]+rec[i].mark[1]+rec[i].mark[2])/3;
        }
        next:
        printf("Press....\n1. Sort by name\n2. Insert new record\n3. Modify\n4. Delete\n5. Exit\n");
        scanf("%d",&j);
        switch(j){
            case 1:
                sort();
                break;
            case 2:
                insert();
                break;
            case 3:
                modify();
                break;
            case 4:
                delete();
                break;
            case 5:
                printf("Programme has been terminated\n");
                exit(0);
                break;
            default:
                printf("Worng index... Try again\n");
                goto next;
                break;
        }
        printf("\nDo you want to continue?y\\n\n");
        char a;
        scanf("%d");
        scanf("%c",&a);
        if(a=='y')
            goto next;
        else    
            exit(0);
}
            
             
           
        
        
        
        
        
        
        

