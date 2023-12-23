#include <stdio.h>
#include <stdlib.h>

// 定义单链表的节点结构体
struct Node {
    int data;           // 存储的数据
    struct Node* next;  // 指向下一个节点的指针
};

// 定义单链表的头节点指针类型
typedef struct Node* LinkedList;

// 创建一个新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// 在链表末尾插入节点
void insertNode(LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }

    if (*list == NULL) {
        *list = newNode;
    } else {
        struct Node* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 打印链表中的数据
void printList(LinkedList list) {
    struct Node* current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 销毁链表，释放内存
void destroyList(LinkedList* list) {
    struct Node* current = *list;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}