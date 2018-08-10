// 测试实例
//
// 模拟打印机的作业
// 
#include "LinkedQueue.h"

#include <stdio.h>

int main(const int argc, const char* argv[])
{
    LinkedQueue q;
    DataType e;

    printf("print the files which numbered [5, 3, 7] start...\n");
    printf("initialize printer...\n");
    if(FAILED == queueInitialize(&q))
    {
        printf("printer initialize failed. break!\n");
        return -1;
    }

    printf("initialize printer success, add task numbered 5.\n");
    if(FAILED == enqueue(&q, 5))
    {
        printf("add task numbered 5 failed. break!\n");
        return -1;
    }

    printf("add task numbered 5 success, current working task: %d\n", queueSize(q));
    printf("add task numbered 3.\n");
    if(FAILED == enqueue(&q, 3))
    {
        printf("add task numbered 3 failed, break!\n");
        return -1;
    }

    printf("add task numbered 3 success, current working task: %d\n", queueSize(q));
    printf("remove task numbered 5 because it is completed.\n");
    if(FAILED == dequeue(&q, &e))
    {
        printf("remove task numberd 5 failed. break!\n");
        return -1;
    }

    printf("remove task numbered 5 success, current working task: %d\n", queueSize(q));
    printf("add task numbered 7.\n");
    if(FAILED == enqueue(&q, 7))
    {
        printf("add task numbered 7 failed. break!\n");
        return -1;
    }

    printf("add task numbered 7 success, current working task: %d\n", queueSize(q));
    printf("wait...\n");
    if(FAILED == queueClear(&q))
    {
        printf("printer clear task failed. break!\n");
        return -1;
    }

    printf("current working task: %d, all task has been completed.\n", queueSize(q));
    printf("print numbered files finish.\n");

    if(FAILED == queueDestroy(&q))
    {
        printf("destroy print queue failed.\n");
        return -1;
    }

    return 0;
}