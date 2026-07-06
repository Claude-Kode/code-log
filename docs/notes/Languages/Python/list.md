# LIST
```
类似 cpp 中的  静态数组 或者 vector 
cpp : int arr[] - {}
py : list = []
序列都可以进行的操作包括索引，切片，加，乘，检查成员

```
### 索引
就是下标访问
### 切片
语法 : lst[start:end:step]
```
my_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 打印整个列表
print(my_list[:])  # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 从索引2开始，到5结束（不包含5）
print(my_list[2:5])  # [2, 3, 4]

# 从开头到索引5
print(my_list[:5])  # [0, 1, 2, 3, 4]

# 从索引3到末尾
print(my_list[3:])  # [3, 4, 5, 6, 7, 8, 9]

# 步长为2，隔一个取一个
print(my_list[::2])  # [0, 2, 4, 6, 8]

# 反转列表
print(my_list[::-1])  # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

# 从索引8到2，步长为-1（反向切片）
print(my_list[8:2:-1])  # [8, 7, 6, 5, 4]
```
### 加 | 乘
加就是类似字符串拼接 但是扩展到数字
只有相同类型的数据 比如都是 list 才能拼
乘更简单了 就是多个加
```
# 语法：序列1 + 序列2
list1 = [1, 2, 3]
list2 = [4, 5, 6]
print(list1 + list2)  # [1, 2, 3, 4, 5, 6]

str1 = "Hello"
str2 = "World"
print(str1 + " " + str2)  # "Hello World"

# 注意：只能相同类型相加
# [1, 2] + "abc"  # 报错！
# 但可以转换
print([1, 2] + list("abc"))  # [1, 2, 'a', 'b', 'c']
----------------------------------------------------
# 语法：序列 * 整数
print([1, 2] * 3)     # [1, 2, 1, 2, 1, 2]
print("Hi!" * 4)      # "Hi!Hi!Hi!Hi!"
print((3,) * 5)       # (3, 3, 3, 3, 3)  (元组)

# 注意特殊情况
print([[]] * 3)       # [[], [], []]  (但三个是同一个空列表的引用！)
# 正确创建三个独立空列表：
print([[] for _ in range(3)])  # 推荐写法
```
常用开列表
```
n = 5
# 创建 n+1 个 None
my_list = [None] * (n + 1)
print(my_list)  # [None, None, None, None, None, None]
print(len(my_list))  # 6
```
### 检查成员
用 in 关键字 还有 not in
```
fruits = ["apple", "banana", "orange", "grape"]

print("apple" in fruits)      # True
print("watermelon" in fruits) # False
print("kiwi" not in fruits)   # True

text = "Hello World"

print("World" in text)        # True
print("world" in text)        # False（区分大小写）
print("Python" not in text)   # True
```
扩展介绍 in 和 not in
```
字典(map)
in 的默认是检查 key 而非 value

# key
student = {"name": "Alice", "age": 20, "grade": "A"}
print("name" in student)      # True  （检查键）
print("Alice" in student)     # False （不检查值）
print(20 in student)          # False

# value
print("Alice" in student.values())   # True
print(20 in student.values())        # True

# key-value
print(("name", "Alice") in student.items())  # True
print(("age", 25) in student.items())        # False

另外 in 还可以

# 基本语法
for 变量 in 容器:
    循环体

```
### list 的成员函数

```
# 创建和初始化
lst = []                    # 空列表
lst = [0] * 10              # 10个0
lst = [i for i in range(5)]  # 列表推导式 [0,1,2,3,4]

# 基本操作
lst.append(5)              # 添加
lst.extend([6, 7])         # 扩展
x = lst.pop()              # 删除并返回最后一个
lst.remove(2)              # 删除第一个2
lst.insert(0, -1)          # 插入
lst.sort()                 # 排序
lst.reverse()              # 反转
idx = lst.index(3)         # 查找索引
cnt = lst.count(3)         # 计数
lst2 = lst.copy()          # 浅拷贝
lst.clear()                # 清空


# ==================== 列表的 sort() 方法完整示例 ====================

# 1. 基本排序
print("1. 基本排序:")
numbers = [3, 1, 4, 1, 5, 9, 2, 6, 5]
numbers.sort()  # 默认升序
print(f"升序: {numbers}")  # [1, 1, 2, 3, 4, 5, 5, 6, 9]

numbers.sort(reverse=True)  # 降序
print(f"降序: {numbers}")  # [9, 6, 5, 5, 4, 3, 2, 1, 1]

# 2. 使用 key 参数排序
print("\n2. 使用 key 参数:")

# 按长度排序字符串
words = ["apple", "banana", "cherry", "date", "fig"]
words.sort(key=len)
print(f"按长度: {words}")  # ['fig', 'date', 'apple', 'banana', 'cherry']

# 忽略大小写排序
mixed = ["Apple", "banana", "Cherry", "date"]
mixed.sort(key=str.lower)
print(f"忽略大小写: {mixed}")  # ['Apple', 'banana', 'Cherry', 'date']

# 按绝对值排序
nums = [3, -1, 4, -1, 5, -9, 2]
nums.sort(key=abs)
print(f"按绝对值: {nums}")  # [-1, -1, 2, 3, 4, 5, -9]

# 3. 复杂排序
print("\n3. 复杂排序:")

# 按元组第二个元素排序
pairs = [(1, 3), (4, 1), (2, 2), (3, 5)]
pairs.sort(key=lambda x: x[1])
print(f"按元组第二项: {pairs}")  # [(4, 1), (2, 2), (1, 3), (3, 5)]

# 多级排序：先按年龄，再按姓名
students = [
    ("Alice", 20, "A"),
    ("Bob", 20, "B"),
    ("Charlie", 19, "A"),
    ("David", 19, "B")
]
students.sort(key=lambda s: (s[1], s[0]))  # 年龄升序，姓名升序
print("多级排序:")
for name, age, grade in students:
    print(f"  {name}: 年龄{age}, 成绩{grade}")

# 混合升序降序：年龄升序，成绩降序
students2 = [
    ("Alice", 20, "B"),
    ("Bob", 20, "A"),
    ("Charlie", 19, "A"),
    ("David", 19, "B")
]
students2.sort(key=lambda s: (-s[1], s[2]), reverse=True)  # 技巧：年龄取负实现降序
print("\n年龄升序，成绩降序:")
for name, age, grade in students2:
    print(f"  {name}: 年龄{age}, 成绩{grade}")

# 4. 实际应用例子
print("\n4. 实际应用:")

# 按学生成绩排序
student_records = [
    {"name": "张三", "score": 85, "age": 20},
    {"name": "李四", "score": 92, "age": 19},
    {"name": "王五", "score": 78, "age": 21}
]
student_records.sort(key=lambda s: s["score"], reverse=True)
print("按成绩降序:")
for s in student_records:
    print(f"  {s['name']}: {s['score']}分")

# 按文件名数字部分排序
files = ["file10.txt", "file2.txt", "file1.txt", "file20.txt"]
files.sort(key=lambda x: int(x[4:-4]))  # 提取数字部分排序
print(f"\n文件名数字排序: {files}")  # ['file1.txt', 'file2.txt', 'file10.txt', 'file20.txt']

# 5. sort() 与 sorted() 的区别
print("\n5. sort() 与 sorted() 的区别:")

original = [3, 1, 4, 2]

# sort() 修改原列表
lst1 = original.copy()
lst1.sort()
print(f"sort() 后原列表: {lst1}")  # [1, 2, 3, 4]

# sorted() 返回新列表
lst2 = original.copy()
sorted_lst = sorted(lst2)
print(f"sorted() 后原列表不变: {lst2}")       # [3, 1, 4, 2]
print(f"sorted() 返回排序后: {sorted_lst}")  # [1, 2, 3, 4]

# 6. 注意事项
print("\n6. 注意事项:")

# sort() 返回 None，不能链式调用
lst = [3, 2, 1]
result = lst.sort()  # sort() 返回 None
print(f"sort() 返回值: {result}")  # None
print(f"但原列表已排序: {lst}")     # [1, 2, 3]

# 字符串没有 sort() 方法
string = "hello"
# string.sort()  # 会报错！
sorted_str = sorted(string)  # 用 sorted() 可以
print(f"字符串用 sorted(): {sorted_str}")  # ['e', 'h', 'l', 'l', 'o']

# 7. 自定义排序函数
print("\n7. 自定义排序函数:")

# 按奇偶排序：奇数在前，偶数在后，分别升序
numbers = [5, 2, 8, 1, 9, 4, 3, 6, 7]

def custom_sort(x):
    return (x % 2, x)  # 元组：(奇偶性, 数值)
    # 奇数: 1, 偶数: 0，所以奇数在前
    # 相同奇偶性时按数值排序

numbers.sort(key=custom_sort)
print(f"奇数在前: {numbers}")  # [1, 3, 5, 7, 9, 2, 4, 6, 8]

# 8. 性能测试
print("\n8. 大型列表排序性能演示:")
import random
big_list = [random.randint(1, 10000) for _ in range(10000)]
big_list.sort()  # 原地排序，速度快
print(f"排序后前10个: {big_list[:10]}")  # 最小的10个数
print(f"排序后后10个: {big_list[-10:]}")  # 最大的10个数
```
