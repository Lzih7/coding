#include <stdio.h>
#include "stdlib.h"
#include "hash.h"
#include <string.h>

HASH_RESULT hash_add_int(HashTable *table, const char *key, int value ){
    long hash_val=hash_string(key);
    int index=hash_val%table->size;
    HashEntry* entry=table->bucket[index];
    while(entry){
        if(strcmp(entry->key.str_value,key)==0){
            if(entry->value.int_value==value){
                return HASH_ALREADY_ADDED;
            }else{
                entry->value.int_value=value;
                return HASH_REPLACED_VALUE;
            }
        }
        entry=entry->next;
    }
    
    HashEntry* new_entry=(HashEntry*)malloc(sizeof(HashEntry));
    if(!new_entry){
        free(new_entry);
        return HASH_ERROR;
    }
    new_entry->key.str_value=(char*)malloc(sizeof(char)*(strlen(key)+1));
    if(!new_entry->key.str_value){
        free(new_entry);
        return HASH_ERROR;
    }
    strcpy(new_entry->key.str_value,key);
    new_entry->value.int_value=value;
    
    new_entry->next=table->bucket[index];
    table->bucket[index]=new_entry;
    
    return HASH_ADDED;
}