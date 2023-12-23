#include <stdio.h>

#define MAX_SIZE 100  // 定义线性表的最大长度

typedef struct {
    int data[MAX_SIZE];  // 数据存储数组
    int length;  // 当前线性表的长度
} StaticList;

// 初始化线性表
static void initList(StaticList *list) {
    list->length = 0;
}

// 插入元素到线性表的指定位置
static int insert(StaticList *list, int pos, int value) {
    if (pos < 1 || pos > list->length + 1 || list->length >= MAX_SIZE) {
        return 0;  // 插入位置不合法或线性表已满，插入失败
    }

    // 将插入位置后的元素后移一位
    for (int i = list->length; i >= pos; i--) {
        list->data[i] = list->data[i-1];
    }

    list->data[pos-1] = value;  // 在插入位置插入新元素
    list->length++;  // 更新线性表长度
    return 1;  // 插入成功
}

// 删除线性表中指定位置的元素
static int delete(StaticList *list, int pos) {
    if (pos < 1 || pos > list->length) {
        return 0;  // 删除位置不合法，删除失败
    }

    // 将删除位置后的元素前移一位
    for (int i = pos; i < list->length; i++) {
        list->data[i-1] = list->data[i];
    }

    list->length--;  // 更新线性表长度
    return 1;  // 删除成功
}

// 修改线性表中指定位置的元素值
static int update(StaticList *list, int pos, int value) {
    if (pos < 1 || pos > list->length) {
        return 0;  // 修改位置不合法，修改失败
    }

    list->data[pos-1] = value;  // 修改指定位置的元素值
    return 1;  // 修改成功
}

// 获取线性表中指定位置的元素值
static int get(StaticList *list, int pos) {
    if (pos < 1 || pos > list->length) {
        return -1;  // 获取位置不合法，返回-1表示错误
    }

    return list->data[pos-1];  // 返回指定位置的元素值
}

//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}