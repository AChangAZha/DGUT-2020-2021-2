/* 打印任务管理器 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintTaskManager.h"
void main()
{
    char ch = '0';
    int tid = 0;
    char *text = "TEST";
    Queue taskmanager;
    InitaskManager(&taskmanager);
    while (ch != 'q')
    {
        printf("1 加入");
        printf("\t2 完成");
        printf("\t3 输出");
        printf("\t4 清空");
        printf("\tq 退出");
        printf("\nPlease enter:");
        ch = getchar();
        getchar();
        switch (ch)
        {
        case '1':
            tid = tid + 1;
            AppendPrintTask(&taskmanager, tid, text);
            break;
        case '2':
            PrintFirstTask(&taskmanager);
            break;
        case '3':
            PrintAllTask(&taskmanager);
            break;
        case '4':
            ClearPrintTask(taskmanager);
            break;
        case 'q':
            return;
        }
    }
}