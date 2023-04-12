

[题目详情 - 7-19 简单计算器 (pintia.cn)](https://pintia.cn/problem-sets/1612368002333536256/exam/problems/1612368057576718354)

模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

### 输入格式:

输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

### 输出格式:

在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

### 输入样例:

```in
1+2*10-10/2=
```

### 输出样例:

```out
10
```

这题 

回忆switch 多种情况 多种选择

有规律的字符串 尽量当字符串处理。

比如计算器 前面是整数  符号  整数 一个一个输入即可（优先级相同情况）

~~~
switch(ch) //用ch决定如何
{
	case '+':{
		a += b;
		break;
	}
	case '-'{
		a -= b;
		break;
	}
	case '*':{
		a *= b;	
		break;
	}
	case '/'{
		a /= b;
		break;
	}
	default:{	//非法符号
		
		break;
	}	
}
~~~

~~~~
#include<bits/stdc++.h>

using namespace std;

//格局小了。。。。。
//计算器符号 归符号
//一定是整数类型的 就当作整数输入比如 计算器 ，，
//能不用字符串处理就不要用

//有一定规律的 字符串 可以用整数类型读
int a,b;
char ch;
int ans;
int main()
{
    cin>>a;
    bool si = true;
    while((ch = getchar()) != '=')
    {
        cin>>b;
        switch(ch)
        {
            case '+':
                a +=  b;
                break;
            case '-':
                a = a - b;
                break;
            case '*':
                a = a * b;
                break;
            case '/':
                if(b == 0)
                {
                    
                    printf("ERROR\n");
                    return 0;
                }
                a = a / b;
                break;
            default: 
                printf("ERROR\n");
                return 0;
        }
    }

    printf("%d\n",a);
    return 0;
}
~~~~

