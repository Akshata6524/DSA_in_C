#include<stdio.h>
#include<ctype.h>
#define size 100

char arr[size];
int top=-1;

void push(char elem){
    arr[++top]=elem;
}

char pop(){
    return arr[top--];
}

int precedence(char elem){
    switch(elem){
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 3;
        case '^':
        case '$':return 4;
    }
    return elem;
}

int main(){
    char infix[size],postfix[size];
    int i=0,j=0;
    char ch ,elem;
    
    push('#');
    
    printf("Enter the infix expression:");
    scanf("%s",infix);
    while((ch=infix[i++]) != '\0'){
        
        if(isalnum(ch)){
        postfix[j++]=ch;
        }
        
        else if(ch=='('){
        push(ch);
        }
        
        else if(ch==')'){
            while(arr[top]!='\0')
            postfix[j++]=pop();
            pop();
        }
        
        else {
            while(precedence(arr[top])>=precedence(ch))
            postfix[j++]=pop();
            push(ch);
        }
    }
    
    while(arr[top]!='#')
        postfix[j++]=pop();
        
    postfix[j]='\0';
    
    printf("postfix expression:%s",postfix);
}
