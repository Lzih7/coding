#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    HASH_OK,
    HASH_ERROR,
    HASH_ADDED,
    HASH_REPLACED_VALUE,
    HASH_ALREADY_ADDED,
    HASH_DELETED,
    HASH_NOT_FOUND,
} HASH_RESULT;

typedef struct __HashEntry HashEntry;
struct __HashEntry
{
    union
    {
        char *str_value;
        double dbl_value;
        int int_value;
    } key;
    union
    {
        char *str_value;
        double dbl_value;
        int int_value;
        long long_value;
        void *ptr_value;
    } value;
    HashEntry *next;
};

struct __HashTable
{
    HashEntry **bucket;
    int size;
    HASH_RESULT last_error;
};
typedef struct __HashTable HashTable;

// 向哈希表中添加元素，其中键类型为char*， 元素类型为int。
HASH_RESULT hash_add_int(HashTable *table, const char *key, int value)
{
    long hash_val = hash_string(key);
    int index = hash_val % table->size;
    HashEntry *entry = table->bucket[index];
    while (entry)
    {
        if (strcmp(entry->key.str_value, key) == 0)
        {
            if (entry->value.int_value == value)
            {
                return HASH_ALREADY_ADDED;
            }
            else
            {
                entry->value.int_value = value;
                return HASH_REPLACED_VALUE;
            }
        }
        entry = entry->next;
    }

    HashEntry *new_entry = (HashEntry *)malloc(sizeof(HashEntry));
    if (!new_entry)
    {
        free(new_entry);
        return HASH_ERROR;
    }
    new_entry->key.str_value = (char *)malloc(sizeof(char) * (strlen(key) + 1));
    if (!new_entry->key.str_value)
    {
        free(new_entry);
        return HASH_ERROR;
    }
    strcpy(new_entry->key.str_value, key); // 对字符串的赋值需使用strcpy函数，而不是=
    new_entry->value.int_value = value;

    new_entry->next = table->bucket[index];
    table->bucket[index] = new_entry;

    return HASH_ADDED;
}