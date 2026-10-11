#include <stdio.h>

int main()
{
    float a, b, c;
    int err = 0;
    char d;
    printf("Input two numbers:\n");
    scanf("%f %f", &a, &b);

    printf("Input + or - or * or /:\n");
    getchar();
    scanf("%c", &d);
    
    if(d == '+') c = a + b;
    else if(d == '-') c = a - b;
    else if(d == '*') c = a * b;
    else if(d == '/')
        if(b == 0) err = 1;
        else c = a / b;
    else err = 2;
    
    if(!err) printf("Answer is %.2f", c);
    else if(err == 1) printf("Illegal zero in the second number!");
    else if(err == 2) printf("Illegal symbol!");

    return 0;           // 告诉系统"正常结束"
}
