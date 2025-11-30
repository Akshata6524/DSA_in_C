#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5
int stack[max],top=-1,val;
int isfull(){
    if(top==max-1)
    return 1;
    else
    return 0;
}
int isempty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int val){
    if(isfull()){
        printf("Stack overflow\n");
    }
    else{
        stack[++top]=val;
        
    }
}
void pop(){
    if(isempty()){
        printf("Stack underflow\n");
    }
    else{
        stack[top--]=val;
       
    }
     
}
void display(){
    if(isempty()){
        printf("Stack underflow\n");
    }
    else{
    printf("**Stack elements**\n");
    for(int i=top;i>=0;i--)
    printf("%d\n",stack[i]);
    }
}
void pal(){
    int num=0,revnum=0,k=0;
    if(isempty()){
        printf("Stack is empty\n");
    }
    else{
        while(top!=-1){
            pop();
            num = num*10+val;
            revnum = val*pow(10,k)+revnum;
            k++;
        }
        if(num==revnum)
        printf("Stack has palindrom elements\n");
        else
        printf("Stack not have palindrom elements\n");
    }
}
int main(){
    int ch;
    do{
        printf("\n1.push\n2.pop\n3.display\n4.check palindrom\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to insert:");
            scanf("%d",&val);
            push(val);
            printf("%d is pushed into stack",val);
            break;
            case 2:if(isempty()){
                printf("Stack underflow\n");
                
            }
            else{
                pop();
                printf("%d",val);
                
            }
            break;
            case 3:display();
            break;
            case 4:pal();
            break;
            case 5:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
            
        }
    }while(ch!=5);
}
