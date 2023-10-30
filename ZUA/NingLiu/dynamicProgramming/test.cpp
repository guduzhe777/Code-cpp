#include <iostream>
#include <cstdio>
#include<bits/stdc++.h>
int main()
{
    int num;
    std::ios::sync_with_stdio(false);

    // 使用 C++ 输入输出流
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "You entered: " << num << std::endl;

    // 使用 C 语言标准库的输入输出函数
    printf("Enter another number: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);

    return 0;
}