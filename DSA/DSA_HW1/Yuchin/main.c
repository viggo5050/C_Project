#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000000

typedef struct d_stack{
    int cur_top;
    int max_top;
    double *arr ;
}D_STACK;
void create_D_stack(D_STACK *ptr,int size);
int isEmpty(D_STACK *p);
int isFull(D_STACK*p);
double pop(D_STACK *p);
void push(D_STACK *p,double );
void printARR_D(D_STACK *p);

typedef struct c_stack{
    int cur_top;
    int max_top;
    char *arr ;
}C_STACK;
void create_C_stack(C_STACK *ptr,int size);
int isEmpty_c(C_STACK *p);
int isFull_c(C_STACK*p);
char pop_c(C_STACK *p);
void push_c(C_STACK *p,char);
void printARR(C_STACK *p);
void create_D_stack(D_STACK *ptr,int size){
    ptr->cur_top = -1;
    ptr->max_top = size-1;
    ptr->arr = (double*) malloc(sizeof(double) * size);
}
int isEmpty(D_STACK *p){
    if(p->cur_top == -1){return 1;}
    return -1;
}
int isFull(D_STACK*p){
    if(p->cur_top == p->max_top){return 1;}
    return -1;
}
double pop(D_STACK *p){
    if (isEmpty(p) == -1){return p->arr[p->cur_top--];}

}
void push(D_STACK *p,double i){
    if (isFull(p) == -1) {
        p->cur_top++;
        p->arr[p->cur_top] = i;
    }
}
void printARR_D(D_STACK *p){
    for (int i = 0 ;i < p->cur_top+1;i++){
        printf("%f ",p->arr[i]);
    }
    printf("\n");
}



void create_C_stack(C_STACK *ptr,int size){
    ptr->cur_top = -1;
    ptr->max_top = size-1;
    ptr->arr = (char*) malloc(sizeof(char) * size);
}
int isEmpty_c(C_STACK *p){
    if(p->cur_top == -1){return 1;}
    return -1;
}
int isFull_c(C_STACK*p){
    if(p->cur_top == p->max_top){return 1;}
    return -1;
}
char pop_c(C_STACK *p){
    if (isEmpty_c(p) == -1){return p->arr[p->cur_top--];}
}
void push_c(C_STACK *p,char i){
    if (isFull_c(p) == -1){
        p->cur_top++;
        p->arr[p->cur_top] = i;
    }
}
void printARR(C_STACK *p){
    for (int i = 0 ;i < p->cur_top+1;i++){
        printf("%c ",p->arr[i]);
    }
    printf("\n");
}








double calculate(char op, double left,double right ){
    if (op == '+'){return left+right;}
    else if (op == '-'){return left-right;}
    else if (op == '*'){return left*right;}
    else if(op == '/'){return left/right;}
}
int needCalOrNot(char new_op,char top_op){
    if (new_op == ')')return 1;
    else if (new_op == '('||top_op == '(' ){return 0;}
    else if(new_op == '*' || new_op == '/' ){
        if (top_op == '+' || top_op == '-'){return 0;}
        else return 1;
    }
    return 1;
}

int main() {

    char input[LEN];
    while (scanf("%s", input) != EOF) {
        //D_Stack 紀錄double 的運算結果
        //C_Stack 紀錄operation
        D_STACK arr_D;
        C_STACK arr_C;
        create_D_stack(&(arr_D), LEN / 2);
        create_C_stack(&(arr_C), LEN / 2);

        int counter = 0;
        char operation;
        while (input[counter] != '\0') {
//                處理遇到數字的情況
            if (47 < input[counter] && input[counter] < 58) {
                double num = input[counter] - '0';;
                while (47 < input[counter + 1] && input[counter + 1] < 58) {
                    double t = input[counter + 1] - '0';
                    num = num * 10 + t;
                    counter++;
                }
                push(&(arr_D), num);
            }
//                處理遇到非數字的情況
            else {
                char arr_C_top = (arr_C.cur_top != -1) ? arr_C.arr[arr_C.cur_top] : '(';
                char new_C = input[counter];
                if (needCalOrNot(new_C, arr_C_top) == 0) { push_c(&(arr_C), new_C); }
                else {
                    while (arr_C.cur_top != -1 && needCalOrNot(new_C, arr_C.arr[arr_C.cur_top]) == 1 && arr_C.arr[arr_C.cur_top] != '(') {
                        double right = pop(&(arr_D));
                        double left = pop(&(arr_D));
                        double ans = calculate(pop_c(&(arr_C)), left, right);
                        push(&(arr_D), ans);
                    }
                    if (new_C != ')') { push_c(&(arr_C), new_C); }
                    if (arr_C.arr[arr_C.cur_top] == '(') { pop_c(&(arr_C)); }
                }
            }
//            printf("----------------\n");
//            printARR_D(&(arr_D));
//            printARR(&(arr_C));
            counter++;
        }
        while (arr_D.cur_top != 0) {
            char op = pop_c(&(arr_C));
            double right = pop(&(arr_D));
            double left = pop(&(arr_D));
            push(&(arr_D), calculate(op, left, right));
        }
        printf( "%.15f\n", arr_D.arr[arr_D.cur_top]);
        while(isEmpty_c(&(arr_C)) == -1){
            pop_c(&(arr_C));
        }
        while(isEmpty(&(arr_D)) == -1){
            pop(&(arr_D));
        }
        free(arr_D.arr);
        free(arr_C.arr);
        // memset(input,'\0',LEN);
    }
}


