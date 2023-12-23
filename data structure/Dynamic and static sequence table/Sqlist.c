#include <stdio.h>
#include <stdlib.h>

#define Maxsize 10
#define InitSize 10

/*静态分配*/
typedef struct SqList {
    int data[Maxsize];
    int length;
} SqList;

/*动态分配*/
typedef struct SeqList {
    int *data;
    int length;
    int maxsize;
} SeqList;

/*静态初始化*/
bool InitSqList(SqList *L) {
    L->length = 0;
    for (int i = 0; i < Maxsize; i++) {
        L->data[i] = 0;
    }
    return true;
}

/*动态初始化*/
bool InitSeqList(SeqList *L) {
    L->length = 0;
    L->maxsize = InitSize;
    L->data = (int *) malloc(sizeof(int) * InitSize);
    return true;
}

/*静态插入*/
bool SqListInsert(SqList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length >= Maxsize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

/*动态插入*/
bool SeqListInsert(SeqList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length >= L->maxsize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

/*删除*/
bool SqListElemDelete(SqList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length <= 0) {
        return false;
    }
    e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

/*按位查找*/
int SqListLocElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

/*动态扩容*/
bool IncreaseSize(SeqList *L, int len) {
    int *p = L->data; //生成指向原来顺序表存储空间的指针
    L->data = (int *) malloc(sizeof(int) * (L->maxsize + len)); //开辟一个更大的空间
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i]; //p[i] === *p+i
    } //转移数据
    L->maxsize += len; //修改长度
    free(p); //释放原来空间
    return true;
}

//int main() {
//    SqList L1;
//    SeqList L2;
//    InitSqList(&L1);
//    InitSeqList(&L2);
//    return 0;
//}