#include <stdio.h>
#include <malloc.h>

typedef struct {
    int *data;  // 指向数据存储的指针
    int length;  // 当前线性表的长度
    int capacity;  // 当前分配的内存空间容量
} DynamicList;

// 初始化线性表
static void initList(DynamicList *list) {
    list->data = NULL;  // 初始时指针为空
    list->length = 0;
    list->capacity = 0;
}

// 插入元素到线性表的指定位置
static int insert(DynamicList *list, int pos, int value) {
    if (pos < 1 || pos > list->length + 1) {
        return 0;  // 插入位置不合法，插入失败
    }

    // 如果当前分配的内存空间不足以容纳新元素，进行动态内存增长
    if (list->length == list->capacity) {
        int newCapacity = (list->capacity == 0) ? 1 : list->capacity * 2;  // 新分配的内存空间容量

        // 使用realloc函数调整内存空间的大小
        int *newData = (int*)realloc(list->data, newCapacity * sizeof(int));
        if (newData == NULL) {
            return 0;  // 动态内存增长失败，插入失败
        }

        list->data = newData;  // 更新指针指向新的内存空间
        list->capacity = newCapacity;  // 更新分配的内存空间容量
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
static int delete(DynamicList *list, int pos) {
    if (pos < 1 || pos > list->length) {
        return 0;  // 删除位置不合法，删除失败
    }

    // 将删除位置后的元素前移一位
    for (int i = pos; i < list->length; i++) {
        list->data[i-1] = list->data[i];
    }

    list->length--;  // 更新线性表长度

    // 如果删除元素后，线性表的长度小于当前分配的内存空间的一半，进行动态内存缩减
    if (list->length < list->capacity / 2) {
        int newCapacity = list->capacity / 2;  // 新分配的内存空间容量

        // 使用realloc函数调整内存空间的大小
        int *newData = (int*)realloc(list->data, newCapacity * sizeof(int));
        if (newData != NULL) {
            list->data = newData;  // 更新指针指向新的内存空间
            list->capacity = newCapacity;  // 更新分配的内存空间容量
        }
    }

    return 1;  // 删除成功
}

// 修改线性表中指定位置的元素值
static int update(DynamicList *list, int pos, int value) {
    if (pos < 1 || pos > list->length) {
        return 0;  // 修改位置不合法，修改失败
    }

    list->data[pos-1] = value;  // 修改指定位置的元素值
    return 1;  // 修改成功
}

// 获取线性表中指定位置的元素值
int get(DynamicList *list, int pos) {
    if (pos < 1 || pos > list->length) {
        return -1;  // 获取位置不合法，返回-1表示错误
    }

    return list->data[pos-1];  // 返回指定位置的元素值
}
//int main() {
//    printf("Hello, World!\n");
//    return 0;
//}