## 容器
-----

### 顺序容器
  
所有顺序容器都提供了快速访问元素的能力，但在两个方面存在取舍：向容器给忠添加或者删除元素的代价和非顺序访问容器中的元素的代价

- **几种顺序容器类型**
  ```cpp
  vector   //可变大小的数组，
  deque    //双端队列，头尾插入/删除很快
  list     //双向链表，支持双向顺序访问。任何位置插入删除都很快
  forward_list  //单项链表，只支持单向顺序访问
  array    //数组。支持快速随机访问，不能添加或删除元素
  string   //与vector类似。但只用于保存字符，随机访问快，尾部插入/删除快
  ``` 
  
- **容器类型上的操作形成层次** 
  - 某些操作是所有容器类型都提供的
  - 一些操作仅针对顺序容器，关联容器和无序容器
  - 还有一些操作只适用于小部分容器

- **容器操作**

  ```cpp
  //类型别名：
  iterator          //迭代器类型
  const_iterator    //只读不能修改元素的迭代器
  size_type         //无符号整型，足够保存该容器类型最大可能容器的大小

  value_type        //元素类型

  //大小
  c.size()          //c中元素的数目(不支持forward_list)
  c.max_size()      //c中可保存的最大元素数目
  c.empty()         //是否为空
  
  //添加/删除元素
  c.insert(args)    //将args中的元素拷贝进c
  c.emplace(inits)  //使用inits构造c中的一个元素
  c.erase(args)     //删除args指定的元素
  c.clear()         //删除c中所有元素

  //获取迭代器
  c.begin(),c.end()
  c.cbegin(),c.cend()
  ```
- **迭代器**  
  迭代器提供了对对象的间接访问，其对象是容器中的元素。使用迭代器可以访问某个元素，移动迭代器。
  有效的迭代器指向容器中某一元素，或者指向容器中尾元素的下一位置，其他情况属于无效迭代器。

  - 迭代器操作
  ```cpp
  iter         //iter为迭代器类型
  *iter        //返回迭代器iter所指元素的引用
  iter->mem    //解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem  
  ++iter       //移动迭代器到下一位置
  --iter       //移动迭代器到前一位置
  iter1 == iter2
  iter1 != iter2  //判断两个迭代器是否指向同一位置
  ```
  对迭代器进行解引用操作获取迭代器所指向的元素  
- **vector**  
  常用操作
  ```cpp
  vector<int>  v    //定义一个元素类型为int的vector
  vector<char> v    //
  vector<stu>  v    //
  
  v[i]/v.at(i)    //通过下标访问v中的元素
  v.front()       //获取并返回首元素
  v.back()        //获取并返回尾元素
  v.push_back(x)  //向v的尾部插入元素x
  v.size()        //获取并返回v的长度
  v.empty()       //判断v是否为空。空则返回true，非空返回false
  v.pop_back()    //删除v的尾元素
  v.begin()       //返回指向v首元素的迭代器
  v.end()         //返回指向v尾元素后一位置的迭代器
  v.clear()       //清除v中的所有元素
  ``` 

- **容器适配器**  
  标准库定义了三个顺序容器适配器：`stack`、`queue`、`priority_queue`  
  所有容器适配器都支持的操作和类型
  ```cpp
  size_type   //保存当前类型最大对象的大小
  value_type  //容器保存元素的类型
  container_type //实现适配器的底层容器类型

  a.empty()     //是否为空
  a.size()      //返回a中元素的个数
  ```
  - 栈适配器  

  ```cpp
    //stack类型定义在stack头文件中
    stack<int> intstack;  //定义一个空栈
    
    s.pop();       //删除栈顶元素，但不返回。
    s.push(item);  //创建新元素入栈。     
    s.top();       //返回栈顶元素，但不出栈。
  ```

  - 队列适配器  
  两个队列适配器`queue`和`priority_queue`定义在`queue`头文件中。
  
  ```cpp
  q.pop();       //队首元素出队但不返回
  q.push(item);  //向queue的队尾插入元素
  q.front();     //返回队首元素
  q.back();      //返回队尾元素
  ```
  


### 关联容器  

&emsp;&emsp;关联容器支持高效的**关键字查找**。两个主要的关联容器是`map`和`set`。`map`的元素是关键字-值对，关键字用于索引，值则表示与索引相关的数据。`set`只包含一个关键字，支持高效的关键字查询工作——检查给定的关键字是否在`set`中。  
- 标准库中提供8个关联容器

  ```cpp
  //按关键字有序保存元素   定义在头文件<map>、<set>中
  map          //关联数组;保存键值对
  set          //只有关键字元素
  multimap     //关键字可重复出现的map
  multiset     //关键字可重复出现的set

  //无序  定义在头文件<unordered_map>、<unordered_set>中
  unordered_map         //用哈希函数组织的map
  unordered_set         //用哈希函数组织的set
  unordered_multimap    //哈希函数组织的map；关键字可重复
  unordered_multiset    //哈希函数组织的set；关键字可重复
  ```

  关联容器额外的类型别名
  ```cpp
  key_type      //容器关键字类型
  mapped_type   //map中关键字关联的类型
  value_type    //对于set 与key_type
                //对于map 是 pair<key_type, mapped_type>
  ```

- **关联容器操作**  
  - 使用关联容器的`instert`成员来向关联容器中添加元素。
    ```cpp
    c.inster(v)      //v是value_type类型的对象，对于map和set，由于关键字不可重复，只有当元素的关键字不在c中时才可插入。
    ```
    `insert`的返回值依赖于容器的类型和参数。对于不包含重复关键字的容器，`insert`和`emplace`返回一个`pair`。`pair`的`first`成员是一个迭代器指向具有给定关键字的元素;`second`成员是一个`bool`类型的值，指出元素是插入成功还是已经存在容器中。如果已经存在则，则什么也不做且`pair`的`second`成员为`false`，关键字不存在则元素被插入，该`bool`值为`true`。

  - 使用`erase`成员删除元素
    ```cpp
    c.erase(k)    //删除关键字为k的元素
    c.erase(p)    //删除迭代器p指定的元素
    c.erase(b,e)  //删除迭代器b和e之间的元素
    ```
  - 访问元素  
    使用`find`查找特定元素是否已在容器中，对与关键字可重复的容器，还可以使用`count`，如果存在还会计数。
    ```cpp
    c.find(k)  //返回一个迭代器，指向第一个关键字为k的元素，若k不在容器中则返回尾后迭代器
    ```
    对于`map`和`unordered_map`提供了下标运算和对应的`at()`函数。map的下标运算接收一个关键字（索引），获取与该关键字相关联的值。**如果该关键字不在该`map`中，会创建一个元素并插入到map中。**

- **无序容器**   
  &emsp;&emsp;标准库定义了四个**无序的关联容器**，无序容器不使用比较运算符来组织容器而是使用哈希函数和元素的`==`运算符来组织元素。

