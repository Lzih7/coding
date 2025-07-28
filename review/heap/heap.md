# 二叉堆
## 结构体定义
```c
typedef struct _otherInfo
{
    int i;
    int j;
}OtherInfo;

typedef struct _minHeapNode
{
    int value;
    OtherInfo otherInfo;
}MinHeapNode, *PMinHeapNode;

typedef struct _minPQ {
    PMinHeapNode heap_array; // 指向堆元素数组
    int heap_size; // 当前堆中的元素个数
    int capacity;  //堆数组的大小
}MinHeap, *PMinHeap;
```
## 辅助函数
- 二叉堆一般用数组表示，即根节点下标为0
- **看作从1开始**， 然后-1
```c
int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void swap_node(MinHeapNode *x, MinHeapNode *y){
    MinHeapNode temp=*x;
    *x=*y;
    *y=temp;
}
```
- swap函数交换了指针指向的对象，而不是指针本身
## 插入元素
```c
bool heap_insert_value(PMinHeap pq, int value){
    int pos=pq->heap_size-1;
    if(pos==pq->capacity-1) return false; // 已满
    pq->heap_array[pos+1].value=value; // 先放在尾
    pq->heap_size++;
    int cur=pos+1;
    while(cur>0 && pq->heap_array[cur].value<pq->heap_array[parent(cur)].value){
        swap_node(&pq->heap_array[cur],&pq->heap_array[parent(cur)]);
        cur=parent(cur);
    }
    return true;
}
```
- 插入后逐次**与父节点比较**
## 堆化
- 该函数假设元素i对应的**子树都已经是最小堆**（符合最小堆的要求），但**元素i为根**的子树并不是最小堆
```c
void min_heapify(PMinHeap pq, int i){
    int smallest=i;
    while(true){
        int l=left(i);
        int r=right(i);
        if(l<pq->heap_size && pq->heap_array[l].value<pq->heap_array[smallest].value){
            smallest=l;
        }
        if(r<pq->heap_size && pq->heap_array[r].value<pq->heap_array[smallest].value){
            smallest=r;
        }
        if(smallest!=i){
            swap_node(&pq->heap_array[i],&pq->heap_array[smallest]);
            i=smallest;
        }else{
            break;
        }
    }
}
```
- 每轮均会交换，直至不能交换为止