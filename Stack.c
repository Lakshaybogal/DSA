#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int arr[];
};
void create (struct stack *s)
{
    s->top=-1;
}
int isFull(struct stack *s1){
    if(s1->top==s1->size-1){
        return 1;
     }
     return 0;
 }
 
int isEmpty(struct stack *s1){
    if(s1->top==-1){
        return 1;
    }
    return 0;
}


int push(struct stack *s,int ele){
    if(isFull(s)){
        printf("%d cannot be added, Stack OverFlow\n",ele);
    }
    else{
        s->top++;
        s->arr[s->top]=ele;
    }
    return 0;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack UnderFlow \n");
    }
    else{
        s->top-=1;
    }
    return 0;
}

int getinput(){
    int num;
    scanf("%d",&num);
    return num;
}

int peek(struct stack *s){
    int p;
    p=s->arr[s->top];
    return p;
}

void display(struct stack *s){
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int main(){
    struct stack *s;
    printf("Enter Size of Stack: ");
    scanf("%d",&s->size);

    // s->top=-1;
    // s->arr=(int *)malloc(s->size*sizeof(int));
    create(s);
    int n;
    printf("Enter no. of elements to push: ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter elements to push: \n");
    for(int j=0;j<n;j++){
        int f;
        f=getinput();
        push(s,f);
    }
    printf("\n");
    printf("Stack is as follow.....\n");
    display(s);
    printf("\n");
    int r;
    printf("Enter number of elements to be popped: ");
    scanf("%d",&r);
    for(int i=0;i<r;i++){
        pop(s);
    }
    printf("\n");
    printf("Updated array....\n");
    display(s);
    printf("\n");
    int top = peek(s);
    printf("The peek element is %d\n",top);
    return 0;    
}
