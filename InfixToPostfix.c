# include <stdio.h>
# include <stdlib.h>

struct stack{
    int size;
    int top ;
    int *arr ;
};
void create(struct stack *s1){
    s1->size = 5;
    s1->arr = (int*)malloc(s1->size*sizeof(int));
    if(s1->arr == NULL)
    printf("Stack not created!!");
    else
    s1->top = -1;
}
int isFull(struct stack *s1){
    if(s1->top == s1->size-1){
        printf("\nSize FULL!!!\n");
        printf("Reallocating memory!!\n");
        s1->arr = realloc(s1->arr,s1->size*sizeof(int));
        s1->size = (s1->size)*2;
        return 1; 
    }
    else
    return 0;
}
void push(struct stack *s1, int key){
    if(isFull(s1)){
        push(s1,key);
    }
    else{
        s1->top++;
        s1->arr[s1->top]=key;
        
    }
}
void display(struct stack *s1){
    printf("\nStack is :\n");
    for(int i=s1->top;i>=0;i--)
    printf("%d ",s1->arr[i]);
}
void main(){
    struct stack s1;
    create(&s1);
    push(&s1,5);
    push(&s1,4);
    push(&s1,3);
    push(&s1,2);
    push(&s1,1);
    display(&s1);
    push(&s1,2);
    push(&s1,3);
    push(&s1,4);
   
  display(&s1);
}
