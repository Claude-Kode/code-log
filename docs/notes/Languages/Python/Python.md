# 常用输入
```int``` 不再是一个标准类型 而是一个转换函数(py 里面所有的输入本质上都是字符串)

```n = int(input())```
```input()```函数是自动读取整行 而不是像 cin 一样自动跳过空白字符 , 而且 ```input()``` 函数会自动去掉 ```'\n'```

```n, k = map(int, input().split())```
map(func, OP) , 接受一个可迭代对象都通过 func转化后传递出去

```p = list(map(int, input().split()))```读取一个列表

python 没有 unordered_map
但是有 ```dict``` , ```dict``` 不能直接通过key查询value 会报错
要 ```d[k] = d.get(k, 0) + 1``` 然后这样去更改
原因是 dict 访问的时候 key 不存在不会主动初始化

print(i, end = ' ') 