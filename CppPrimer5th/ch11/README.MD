## ch11 关联容器
### 关联容器类型
|类别|能力|
|----|----|
|`map`|关联数组：保存关键字-值对|
|`set`|关键字即值，即只保存关键字的容器|
|`multimap`|关键字可重复出现的 `map`|
|`multiset`|关键字可重复出现的 `set`|
|`unordered_map`|用哈希函数组织的 `map`|
|`unordered_set`|用哈希函数组织的 `set`|
|`unordered_multimap`|哈希组织的 `map`；关键字可以重复出现|
|`unordered_multiset`|哈希组织的 `set`；关键字可以重复出现|



---


## ch11 练习题
### ex11.1
描述 `map` 和 `vector` 的不同？
> `map` 是 `key-value` 的形式，`vector` 是单值形式

### ex11.2
分别给出最合适使用 `list`、`vector`、`deque`、`map` 以及 `set` 的例子
- `list` 双端链表
- `vector` 连续内存的单项队列
- `deque` 双端队列
- `map` `key-value` 键值形式存储
- `set` 存储关键字的容器

### ex11.3
编写你自己的单词奇数程序。
