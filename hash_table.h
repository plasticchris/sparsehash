//space and speed optimal hash implementations
#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hash_functions.h"
#include "serialization_macros.h"
#define HASH_MIN_BUCKETS 32

typedef void* sparsekey_t;
typedef void* sparseval_t;

typedef struct {
  sparsekey_t key;
  sparseval_t value;
} hash_bucket;

#include "sparse_multi_table.h"

typedef boolean (*eq_func_type)(sparsekey_t,sparseval_t);
typedef unsigned int (*hash_func_type)(sparsekey_t);

typedef struct {
  sparse_multi_table sparse_table;
  unsigned int bucket_size; /*must stay a power of 2*/
  unsigned int filled_buckets;
  eq_func_type eq_func;
  hash_func_type hash_func;
} hash_table;

void hash_init(hash_table* table, hash_func_type hash_func, eq_func_type eq_func );
void hash_dispose(hash_table* table);
unsigned int hash_memory_used(hash_table * table);
unsigned char * hash_dump(hash_table* table, unsigned char * memptr);
unsigned char * hash_lift(hash_table* table, unsigned char * memptr, hash_func_type hash_func, eq_func_type eq_func);
void hash_add(hash_table* table, sparsekey_t key, sparseval_t value);
void hash_resize(hash_table* table, unsigned int size);
boolean hash_remove(hash_table* table, sparsekey_t key);
boolean hash_lookup(hash_table* table, sparsekey_t key, sparseval_t value);
void hash_apply(hash_table* table, boolean(*fp)(const hash_bucket *, void * ), void * data );

#ifdef __cplusplus
}
#endif 

#endif
