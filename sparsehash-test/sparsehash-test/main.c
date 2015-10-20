//
//  main.c
//  sparsehash-test
//
//  Created by Chris Johnson on 10/16/15.
//  Copyright © 2015 Chris Johnson. All rights reserved.
//

// Demo application
// input: # of words
// input: words (each less than 10 characters)
// output: a histogram of word frequency

#include "boolean.h"
#include "hash_table.h"
#include "hash_functions.h"

#include <stdio.h>

boolean print_histogram(hash_bucket const* entry, void * data ) {
    printf( "%s %d\n", entry->key, *(unsigned int*)entry->value );
    free( entry->key );
    free( entry->value );
    return TRUE;
}

int main(int argc, const char * argv[]) {
    hash_table t;
    int words;

    hash_init( &t, str_hash_func, str_eq_func );
    
    scanf("%d", &words);
    
    while(words--) {
        char * word = malloc(10);
        unsigned int * count;
        
        scanf("%s",word);
        
        if( !hash_lookup(&t, word, &count) ) {
            count = malloc(sizeof(unsigned int));
            *count = 1;
            hash_add( &t, word, count);
        } else {
            ++*count;
            hash_add( &t, word, count);
        }
    }
    hash_apply(&t, print_histogram, NULL);
    hash_dispose(&t);
    return 0;
}
