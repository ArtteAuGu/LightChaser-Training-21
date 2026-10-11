/* 本程序借助 VS Code 的 continue 插件调用 DeepSeek API Key 生成辅助代码 */
#include <stdio.h>
#include <string.h>

#define MAX 100     // 最多支持的学生数量
#define NAMELEN 32  // 姓名字段的最大长度

// 一个学生 = 姓名 + 分数
struct Student {
    char name[NAMELEN];
    int score;
};

// 计算平均分：把总分除以人数
float Average(struct Student *s, int total) {
    int sum = 0;
    for (int i = 0; i < total; i++)
        sum += s[i].score;          // 取结构体里的 score 字段
    return (float)sum / total;      // 转成 float 做小数除法
}

// 找出分数最高的学生，返回他的下标
int FindTop(struct Student *s, int total) {
    int top = 0;
    for (int i = 1; i < total; i++)
        if (s[i].score > s[top].score)
            top = i;
    return top;
}

// 按分数从高到低排序（简单选择排序）
void SortByScore(struct Student *s, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (s[j].score > s[i].score) {
                struct Student temp = s[i];  // 整个结构体一起交换
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    struct Student list[MAX];   // 用数组存整份成绩单

    printf("How many students? ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of students.\n");
        return 1;
    }

    // 逐个输入姓名和分数
    for (int i = 0; i < n; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%31s", list[i].name);   // 限制长度，防止缓冲溢出
        printf("Student %d score: ", i + 1);
        scanf("%d", &list[i].score);
    }

    // 打印平均分
    printf("\nAverage score: %0.2f\n", Average(list, n));

    // 打印第一名
    int top = FindTop(list, n);
    printf("Top student: %s (%d)\n\n", list[top].name, list[top].score);

    // 排序后按名次输出整份成绩单
    SortByScore(list, n);
    printf("Ranked scoreboard:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %-16s %d\n", i + 1, list[i].name, list[i].score);

    return 0;
}
