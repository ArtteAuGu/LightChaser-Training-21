#include <stdio.h>
#include <stdlib.h>

float Average(int *arr, int total){
    float sum = 0;
    for(int i = 0; i < total; i++)
        sum += *(arr+i);
    
    return sum / total;
}

int main()
{
    int n, i;
    printf("How many numbers do you need?");
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int*)malloc(n * sizeof(int));   // 申请 n 个 int 的空间
    if (arr == NULL) {        // 申请失败要处理，不然下面会崩
        printf("Unenough!\n");
        return 1;
    }

    printf("Input them:");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        
    printf("Ave is %0.4f\n", Average(arr, n));

    free(arr);        // ★ 用完后必须释放，不然内存泄漏
    arr = NULL;       // ★ 置空，防止变成野指针
    return 0;
}
