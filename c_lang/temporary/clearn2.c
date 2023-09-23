#include<stdio.h>

void println(const char *str) {
    printf("%s\n", str);
}

int main(){
    printf("%ls\n",L"s");
    println("s凯撒都能从宋朝你的随从");
    return 0;
}