# DICT
相当于 map 有 key -> value
直接上成员函数啥的
```

"""
Python 字典(dict)常用方法总结
创建字典
"""
my_dict = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 1. dict.clear() 删除字典内所有元素
my_dict.clear()
print(my_dict)  # {}

my_dict = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 2. dict.copy() 返回一个字典的浅复制
dict_copy = my_dict.copy()
print(dict_copy)  # {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 3. dict.fromkeys(seq[, val]) 以序列seq中元素做字典的键，val为所有键对应的初始值
keys = ['a', 'b', 'c']
new_dict1 = dict.fromkeys(keys)
new_dict2 = dict.fromkeys(keys, 0)
print(new_dict1)  # {'a': None, 'b': None, 'c': None}
print(new_dict2)  # {'a': 0, 'b': 0, 'c': 0}

# 4. dict.get(key, default=None) 返回指定键的值，如果键不存在返回default值
value = my_dict.get('name')
value_none = my_dict.get('gender')
value_default = my_dict.get('gender', 'unknown')
print(value)         # 'Alice'
print(value_none)    # None
print(value_default) # 'unknown'

# 5. Python3 中已移除 dict.has_key(key)，可以使用 key in dict
print('name' in my_dict)  # True
print('gender' in my_dict)  # False

# 6. dict.items() 以列表返回可遍历的(键, 值) 元组数组
items = my_dict.items()
print(items)  # dict_items([('name', 'Alice'), ('age', 25), ('city', 'Beijing')])

# 7. dict.keys() 以列表返回一个字典所有的键
keys = my_dict.keys()
print(keys)  # dict_keys(['name', 'age', 'city'])

# 8. dict.setdefault(key, default=None) 如果键存在则返回值，否则添加键并设为default
value = my_dict.setdefault('name', 'Bob')
new_value = my_dict.setdefault('gender', 'female')
print(value)      # 'Alice'
print(new_value)  # 'female'
print(my_dict)    # {'name': 'Alice', 'age': 25, 'city': 'Beijing', 'gender': 'female'}

# 9. dict.update(dict2) 把字典dict2的键/值对更新到dict里
my_dict.update({'age': 26, 'hobby': 'reading'})
print(my_dict)  # {'name': 'Alice', 'age': 26, 'city': 'Beijing', 'gender': 'female', 'hobby': 'reading'}

# 10. dict.values() 以列表返回字典中的所有值
values = my_dict.values()
print(values)  # dict_values(['Alice', 26, 'Beijing', 'female', 'reading'])

# 11. pop(key[,default]) 删除给定键对应的值，返回被删除的值，否则返回default值
deleted_value = my_dict.pop('city')
# deleted_value = my_dict.pop('city', 'not found')  # 使用默认值
print(deleted_value)  # 'Beijing'
print(my_dict)  # {'name': 'Alice', 'age': 26, 'gender': 'female', 'hobby': 'reading'}

# 12. popitem() 删除并返回字典中的最后一对键和值
last_item = my_dict.popitem()
print(last_item)  # ('hobby', 'reading')
print(my_dict)    # {'name': 'Alice', 'age': 26, 'gender': 'female'} 


```