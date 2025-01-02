//
// Created by wangl on 2025/1/2.
//

#include <stdio.h>
void main(void) {
    int num=0;
    int columns[4]={0,0,0,0};

    // scanf 当你输入4 -1 时会默认赋值2次。
    while (num<4 && (scanf("%d",&columns[num]))==1 && columns[num] >0) num++;
    printf("num is : %d \n",num);  // 有趣的是此时num才有1。
    for (int i=0; i<4; i++) {
        printf("column: %d \n",columns[i]);
    }
}