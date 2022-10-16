# print(r'''hello \n
# ...Tom
# ...michael''')
#禁止转义  r  多行
# print(r'hello \nTommichael')
#禁止转义  r
# print('''hello \n
# ...Tom
# ...michael''')
#多行


# print('ord: ',ord('中'),'chr: ',chr(65))
#ord 中文变成编码  chr 数字变中文

#list


classmates = ['sam','tom','mac']
print(classmates)
classmates.append('王刚')

print(classmates)
classmates.insert(1,'二蛋')
print(classmates)
classmates.pop(0)
print(classmates)
p = ['强子','🐂']
classmates.append(p)
print(p)


L = [
    ['Apple', 'Google', 'Microsoft'],
    ['Java', 'Python', 'Ruby', 'PHP'],
    ['Adam', 'Bart', 'Lisa']
]
# 打印Apple:
print(L[0][0])
# 打印Python:
print(L[1][1])
# 打印Lisa:
print(L[2][2])
#元组不能改变
t = (1,)
#元组
L = ['a','b']
t = (1,L)
print(t)
#链表在改变
L[0] = 'x'
L[1] = 'y'
t = (1,L)
print(t)


#循环
#range(101) 整数序列
#while a > 0:
sum = 0
for x in list(range(101)):
    sum += x


print(sum)
# sum = 0
# for x in range(101):
#     sum = sum + x
# print(sum)
while x > 0:
    x += 2
    print(x)
    if(x>101):
        break

#dic  字典 计算机像字典一样查找
#普通：一个办法是把字典从第一页往后翻，直到找到我们想要的字为止
#dic:字典的索引表里（比如部首表）查这个字对应的页码，然后直接翻到该页，找到这个字。 对于字母有个索引表

d = {'abc':97,'tom':89,'sam':95}
print(d['tom'])

#直接修改 abc的得分
d['abc'] = 98


print(d['abc'])
#第一条就是dict的key必须是不可变对象 --------- 防止被改变
#dict可以用在需要高速查找的很多地方，在Python代码中几乎无处不在，
# 正确使用dict非常重要，需要牢记的
# 第一条就是dict的key必须是不可变对象。
#这是因为dict根据key来计算value的存储位置，如果每次计算相同的key得出的结果不同，那dict内部就完全混乱了。
# 这个通过key计算位置的算法称为哈希算法（Hash）



#set = dic
#set和dict的唯一区别仅在于没有存储对应的value，但是，set的原理和dict一样，所以，同样不可以放入可变对象，因为无法判断两个可变对象是否相等，也就无法保证set内部“不会有重复元素”。试试把list放入set，看看是否会报错。

#再议不可变对象

s = set(list[1,2,3])
#
s.add(4)
s.add(4)
#只有一个元素4  因为不可重复性
