#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next; //写全
} LNode, *LinkList; //LNode普通变量，*LinkList头指针

/*头节点的初始化1*/
bool InitLinkList(LinkList L) {
    L->data = 0; //头节点的data域用来存储表长
    L->next = NULL; //头节点的next域用来只想链表的第一个节点
}

/*头节点的初始化2*/
LNode *InitLinkList_1() {
    LNode *L = (LNode *) malloc(sizeof(LNode));
    L->data = 0; //头节点的data域用来存储表长
    L->next = NULL; //头节点的next域用来指向链表的第一个节点
    return L;
}

/*打印*/
bool PrintLinkList(LinkList L) {
    LNode *p;
    p = L;
    while (p->next) {
        p = p->next;
        printf("%d-->", p->data);
    }
    printf("NULL\n");
    return true;
}

/*头插法*/
bool HeadInsertLinkList(LinkList L) {
    LNode *NewNode; //新节点
    int NewNode_data; //新节点的数据域值
    scanf("%d", &NewNode_data);
    while (NewNode_data != 999) {
        // 插入操作
        NewNode = (LNode *) malloc(sizeof(LNode));
        NewNode->data = NewNode_data;
        NewNode->next = L->next;
        L->next = NewNode;
        L->data++; //增加表长
        scanf("%d", &NewNode_data);
    }
}

/*尾插法*/
bool TailInsertLinkList(LinkList L) {
    LNode *NewNode; //新节点
    LNode *TailNode = L; //尾节点
    int NewNode_data; //新节点的data域
    while (TailNode->next != NULL) {
        TailNode = TailNode->next;
    } //移动到最后一个节点
    scanf("%d", &NewNode_data);
    while (NewNode_data != 999) {
        NewNode = (LNode *) malloc(sizeof(LNode));
        NewNode->data = NewNode_data;
        NewNode->next = NULL;
        TailNode->next = NewNode;
        TailNode = NewNode; //每次插入都更新一次尾节点
        L->data++;
        scanf("%d", &NewNode_data);
    }
}

/*按位查找*/
LNode *GetElem(LinkList L, int i) {
    if (i == 0) {
        return L;
    }
    if (i < 1 || i > L->data) {
        return NULL;
    } //L->data：头节点的data保存长度
    // 查找
    LNode *p = L;
    for (int j = 0; j < i; j++) {
        p = p->next;
    }
    return p;
}

/*按值查找*/
LNode *LocateElem(LinkList L, int e) {
    if (!L->next) {
        return L;
    }
    LNode *p = L;
    while (p->next) {
        p = p->next;
        if (p->data == e) {
            return p;
        }
    }
    return NULL;
}

/*按位插入*/
bool LocalInsertLinkList(LinkList L, int i, int e) {
    if (i < 1 || i > (L->data + 1)) {
        return false;
    }
    LNode *p = GetElem(L, i - 1);
    LNode *NewNode = (LNode *) malloc(sizeof(LNode));
    NewNode->data = e;
    NewNode->next = p->next;
    p->next = NewNode;
    L->data++;
    return true;
}

/*按位删除*/
bool LocalDeleteElem(LinkList L, int i) {
    if (i < 1 || i > L->data || !L->next) {
        return false;
    }
    LNode *p = GetElem(L, i - 1); //待删除元素的前驱节点
    LNode *q = p->next; //待删除元素
    p->next = q->next;
    free(q);
    L->data--; //长度
    return true;
}

/*销毁单链表*/
bool DestoryLinkList(LinkList L) {
    while (L->data) {
        LocalDeleteElem(L,1);
    }
    free(L);
}

//int main() {
//    LinkList L; //生成头指针
//    L = (LNode *) malloc(sizeof(LNode));
//    InitLinkList(L); //初始化①
////    HeadInsertLinkList(L); //头插法插入
//    TailInsertLinkList(L); //尾插法插入
////    printf("L[%d] = %d", 4, GetElem(L, 4)->data); //按位查找
////    printf("L[%d] = %d", 4, LocateElem(L, 4)->data); //按值查找
////    LocalInsertLinkList(L,1,123); //按位插入
//    LocalDeleteElem(L, 3); //按位删除
//    int e;
//    printf("e = %d\n", e);
//    PrintLinkList(L); //打印
//    //    L = InitLinkList_1(); //初始化②
//    return 0;
//}