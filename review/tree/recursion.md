## 递归的基本思想
### 找到一般性的规律
```c
BiTree CS2Bi(CSTree rootCS) {
    if (rootCS == NULL) return NULL;
    
    BiTree rootBi = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
    rootBi->data = rootCS->data;
    
    //TODO
    rootBi->LChild = CS2Bi(rootCS->FirstChild);
    rootBi->RChild = CS2Bi(rootCS->NextSibling);

    return rootBi;
}
```
- 此函数的规律是“右兄弟变儿子”，依此规律可实现对整棵树的遍历
### 递归的条件
- 子结构，子问题
### 递归的返回值
1. void
2. 特定值，出现`T node=func()`的形式