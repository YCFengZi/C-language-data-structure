#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef struct SqStack {
    int data[MaxSize];
    int top;
} SqStack;

/*初始化*/
bool InitStack(SqStack *s) {
    s->top = -1;
}


/*判断空栈*/
bool StackEmpty(SqStack *s) {
    if (s->top != -1) {
        return false;
    }
    return true;
}

/*进栈*/
bool Push(SqStack *s, int e) {
    if (s->top == MaxSize - 1) {
        return false;
    } //满栈
    s->data[++s->top] = e;
    return true;
}

/*出栈*/
bool Pop(SqStack *s, int *e) {
    if (StackEmpty(s)) {
        return false;
    }
    *e = s->data[s->top--];
    return true;
}

/*读取*/
bool GetTop(SqStack *s, int *e) {
    if (StackEmpty(s)) { return false; }
    *e = s->data[s->top];
    return true;
}

int main() {
    SqStack s;
    InitStack(&s);
    for (int i = 0;i < 3;i++) {
        Push(&s,i);
    }
    int x,count=s.top;
    for (int i = 0;i <= count;i++) {
        printf("i = %d\n",i);
        GetTop(&s,&x);
        Pop(&s,&x);
        printf("GetTop X = %d\n",x);
    }
    return 0;
}