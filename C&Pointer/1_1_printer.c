//
// Created by wangl on 2025/1/2.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 100

int read_column_numbers(int columns[], int max);
void rearrange(char *ouput, char const *input, int n_colums, int const columns[]);

int main(void){
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns,MAX_COLS);

    while (gets(input) != NULL) {
        printf("Original input: %s \n", input);
        rearrange(output,input,n_columns,columns);
        printf("Rearrange line: %s \n",output);
    }
    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[],int max) {
    int num = 0;
    int ch;

    // 每次成功读取一个正整数时，num 增加1，直到满足任意一个退出条件（达到最大容量、读取失败或读取非正数）
    while(num<max && scanf("%d", &columns[num]) == 1 && columns[num] >0 ) num +=1;
    printf("num: %d ",num);

    if (num % 2 != 0) {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    // 这段代码用于清除输入缓冲区中剩余的字符，直到遇到文件结束符（EOF）或换行符（\n）
    while ( (ch=getchar()) != EOF && ch != '\n');
    return  num;
}


void rearrange(char *output, char const *input, int n_colums, int const columns[]) {
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for (col =0; col <n_colums; col +=2) {
        int nchars = columns[col+1] - columns[col] + 1;
        if (columns[col] >= len || output_col == MAX_INPUT-1) break;
        // output + output_col：表示从 output 缓冲区的第 output_col 个位置开始写入。
        // input + columns[col]：表示从 input 字符串的第 columns[col] 个位置开始读取。
        strncpy(output+output_col,input+columns[col],nchars);
        output_col += nchars;
    }
    //  确保输出字符串以空字符结尾
    output[output_col] = '\0';
}
