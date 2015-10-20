//
//  hash_bucket.h
//  sparsehash-test
//
//  Created by Chris Johnson on 10/19/15.
//  Copyright © 2015 Chris Johnson. All rights reserved.
//

#ifndef hash_bucket_h
#define hash_bucket_h

typedef void* sparsekey_t;
typedef void* sparseval_t;

typedef struct {
  sparsekey_t key;
  sparseval_t value;
} hash_bucket;

#endif /* hash_bucket_h */
