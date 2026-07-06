```
arr = ['a', 'b', 'c']
```

# enumerate 返回的是 (索引, 值) 的元组
```
for item in enumerate(arr, 1):
    print(item, type(item))
```
# 输出:
# (1, 'a') <class 'tuple'>
# (2, 'b') <class 'tuple'>
# (3, 'c') <class 'tuple'>