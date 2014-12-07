/**
 * Copyright 2014, Rishin Goswami
 *
 * This file is part of myJunk.
 * 
 * myJunk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * myJunk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with myJunk.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 * @brief A set of synchronisation problems to test `synchronized` idiom.
 */

#include "misc/sync.h"
#include <pthread.h>


struct Incdec {
    pthread_mutex_t mutex;
    int* variable;
    int inc_iterations;
    int dec_iterations;
};
    

static void* sync_incdec_increment(struct Incdec* incdec) {
    int i = 0;
    for (i = 0; i < incdec->inc_iterations; i++) {
        synchronized(&(incdec->mutex)) {
            *(incdec->variable) += 1;
        }
    }
    
    return NULL;
}

static void* sync_incdec_decrement(struct Incdec* incdec) {
    int i = 0;
    for (i = 0; i < incdec->dec_iterations; i++) {
        synchronized(&(incdec->mutex)) {
            *(incdec->variable) -= 1;
        }
    }
    
    return NULL;
}


extern int sync_incdec(int* variable, int inc_iterations, int dec_iterations) {
    
    struct Incdec incdec;
    pthread_t inc_thread;
    pthread_t dec_thread;
    int status = -1;
    
    incdec.variable = variable;
    incdec.inc_iterations = inc_iterations;
    incdec.dec_iterations = dec_iterations;
    status = pthread_mutex_init(&(incdec.mutex), NULL);
    if (status != 0) {
        return status;
    }

    status = pthread_create(&inc_thread, NULL, (void * (*)(void *))sync_incdec_increment, (void*)&incdec);
    if (status != 0) {
        return status;
    }
    
    status = pthread_create(&dec_thread, NULL, (void * (*)(void *))sync_incdec_decrement, (void*)&incdec);
    if (status != 0) {
        return status;
    }
    
    status = pthread_join(inc_thread, NULL);
    if (status != 0) {
        return status;
    }
    
    status = pthread_join(dec_thread, NULL);
    if (status != 0) {
        return status;
    }
    
    return 0;
}
