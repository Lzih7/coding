#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4  // 可由用户定义的块大小
#define BLS_BLANK '#' // 用于空白处的补齐字符

typedef struct _block
{
    char ch[BLOCK_SIZE]; // 块的数据域
    struct _block *next; // 块的指针域
} Block;

typedef struct
{
    Block *head; // 串的头指针
    Block *tail; // 串的尾指针
    int len;     // 串的当前长度
} BLString;

// 字符串初始化函数：
void blstr_init(BLString *T)
{
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
    // 检查合理性
    if (pos < 0 || len <= 0 || pos > src.len || src.head == NULL)
        return false;
    if (pos + len > src.len)
    {
        len = src.len - pos;
    }

    // 对sub初始化
    sub->head = sub->tail = NULL;
    sub->len = 0;

    int start_block = pos / BLOCK_SIZE; // 从0开始
    int block_offset = pos % BLOCK_SIZE;
    Block *curr = src.head;
    for (int i = 0; i < start_block && curr != NULL /*严谨！*/; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
        return false;

    Block *new_block = NULL;
    int copied = 0;
    int block_pos = 0;
    while (copied < len && curr != NULL)
    {
        if (block_pos == 0)
        {
            new_block = (Block *)malloc(sizeof(Block));
            new_block->next = NULL;
            if (sub->head == NULL)
            {
                sub->head = sub->tail = new_block;
            }
            else
            {
                sub->tail->next = new_block;
                sub->tail = new_block;
            }
        }
        new_block->ch[block_pos] = curr->ch[block_offset];
        copied++;
        block_pos++;
        block_offset++;
        if (block_pos >= BLOCK_SIZE || copied == len)
        {
            while (block_pos < BLOCK_SIZE)
            {
                new_block->ch[block_pos++] = BLS_BLANK;
            }
            block_pos = 0;
        }
        if (block_offset >= BLOCK_SIZE)
        {
            block_offset = 0;
            curr = curr->next;
        }
    }
    sub->len = len;
    return true;
}