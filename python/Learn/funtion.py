#递归函数
#强转换 函数调用  输入 输出

# def obs(n):
# {
#     if n == 1:
#         return 1
#      return n * obs(n - 1)
# }

def fact(n):
    if n == 1:
        return 1
    return n * fact(n - 1)

suma = int(input())
#print(suma,type(suma))#先输出内容，然后type()函数看类型。
print(fact(suma))
# def my_abs(x):
#     if x >= 0:
#         return x
#     else:
#         return -x


# def sum(sum1,sum2):
#     print(sum1 + sum2)




