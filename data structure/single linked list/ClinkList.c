#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTwo {
    int data; //数据域
    struct NodeTwo *next; //指针域
} NodeTwo, *PNodeTwo;

typedef struct CLinkList {
    PNodeTwo head; //指向头节点
    PNodeTwo tail; //指向尾节点
    int length; //记录长度
} CLinkList;

/*初始化*/
bool CLinkListInit(CLinkList *L) {
    PNodeTwo HeadNode = (PNodeTwo) malloc(sizeof(NodeTwo)); //开辟一块头节点空间
    if (HeadNode == NULL) {
        return 0;
    }
    L->head = L->tail = HeadNode;
    L->length = 0;
    HeadNode->data = 0; // 初始化头节点的 data 字段
    HeadNode->next = L->head;
    return true;
}

/*创建新节点*/
PNodeTwo CreatnewNode(int e) {
    PNodeTwo newNode = (PNodeTwo) malloc(sizeof(NodeTwo));
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

/*节点插入*/
bool CLinkListHeadInsert(CLinkList *L, int e) {
    PNodeTwo newNode = CreatnewNode(e);
    newNode->next = L->head->next;
    L->head->next = newNode;
    if (L->head == L->tail) {
        L->tail = newNode;
    } //特殊情况：空链表时，操作尾指针
    L->length++;
    return true;
} //头插法

bool CLinkListTailInsert(CLinkList *L, int e) {
    PNodeTwo newNode = CreatnewNode(e);
    if (newNode == NULL) {
        return 0;
    }
    PNodeTwo p = L->tail;
    newNode->next = p->next;
    p->next = newNode;
    L->tail = newNode;
    L->length++;
    return true;
} //尾插法

/*查询*/
int PrintList(CLinkList *L) {
    if (L->head->next == L->head) {
        return 0;
    }
    PNodeTwo p = L->head->next;
    for (int i = 1; i <= L->length; i++) {
        printf("%d==>", p->data);
        p = p->next;
    }
    printf("Headnode\n");
    return 0;
}

/*定位函数*/
PNodeTwo GetElemTwo(CLinkList *L, int i) {
    if (i == 0) {
        return L->head;
    }
    if (i < 1 || i > L->length) {
        return NULL;
    }
    PNodeTwo p = L->head->next;
    while (i > 1) {
        p = p->next;
        i--;
    }
    return p;
} //按位查找

PNodeTwo LocateElemTwo(CLinkList *L, int e) {
    if (L->length == 0) {
        return NULL;
    }
    PNodeTwo p = L->head->next;
    for (int i = 1; i < L->length; i++) {
        if (p->data == e) {
            return p;
        }
        p = p->next;
    }
    return NULL;
} //按值查找

/*按位插入*/
bool CLinkListLocalInsert(CLinkList *L, int i, int e) {
    if (i < 1 || i > L->length + 1) {
        return 0;
    }
    PNodeTwo p = GetElemTwo(L, i - 1); //定位
    PNodeTwo newNode = CreatnewNode(e);
    newNode->next = p->next;
    p->next = newNode;
    L->length++;
    return true;
}

/*删除*/
bool DeleteNodeTwo(CLinkList *L, int i) {
    if (i < 1 || i > L->length) {
        return false;
    }
    PNodeTwo p = GetElemTwo(L, i - 1);
    PNodeTwo q = p->next;
    p->next = q->next;
    free(q);
    L->length--;
    return true;
}

bool DestoryList(CLinkList *L) {
    if (L->head->next == L->head) {
        return false;
    }
    PNodeTwo p = L->head->next;
    for (int i = 0; i <= L->length; i++) {
        p = L->head->next;
        L->head->next = L->head->next->next;
        free(p);
    }
    return true;
}

//int main() {
//    CLinkList L;
//    CLinkListInit(&L);
//    PrintList(&L);
//    for (int i = 1; i <= 5; i++) {
//        CLinkListHeadInsert(&L, i);
//    }
//    PrintList(&L);
//    for (int i = 6; i <= 10; i++) {
//        CLinkListTailInsert(&L, i);
//    }
//    PrintList(&L);
////    printf("%d\n", GetElemTwo(&L, 4)->data);
////    printf("%d\n", LocateElemTwo(&L, 8)->data);
//    CLinkListLocalInsert(&L, 5, 5);
//    DeleteNodeTwo(&L, 5);
//    DestoryList(&L);
//    PrintList(&L);
//    return 0;
//}