/**
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
 * @brief A clean idiom for using pthread the library.
 *
 * This file provides an alternative syntax to the pthread_lock/unlock 
 * convention. Essetnially some can use the following syntax - 
 * 
 *     sync (mutex_for_ds) {
 *          ds->field = some_val;
 *     }
 * 
 * @warning The variable `__sync_status__` is introduced into the block prefixed
 * by sync.
 */


#ifndef MYJUNK_MISC_SYNC_H
#define MYJUNK_MISC_SYNC_H

#ifdef  __cplusplus
extern "C" {
#endif


/**
 * Synchronisation type for read read-write locks.
 */
#define SYNC_R rwlock_rd

/**
 * Synchronisation type for write read-write locks.
 */
#define SYNC_W rwlock_wr

/**
 * Synchronisation type for spin locks.
 */
#define SYNC_S spin_

/**
 * Synchronisation type for mutex locks.
 */
#define SYNC_M mutex_
 

// synchronized(mm, SYNC_R)
// ==> __SYNC__(mm, rwlock_rd)
// ==> __SYNCALIAS__(mm, rwlock_rd, __SYNC_X__, __SYNC_M__)(mm, rwlock_rd)
// ==> __SYNC_X__(mm, rwlock_rd)
#define __SYNC_X__(lockObj, lockType) for(int __sync_status__=!pthread_##lockType##lock(lockObj);  __sync_status__ ; pthread_##lockType##unlock(lockObj), __sync_status__=0)

// synchronized(mm)
// ==> __SYNC__(mm)
// ==> __SYNCALIAS__(mm, __SYNC_X__, __SYNC_M__)(mm)
// ==> __SYNC_M__(mm)
#define __SYNC_M__(lockObj) for(int __sync_status__=!pthread_mutex_lock(lockObj);  __sync_status__ ; pthread_mutex_unlock(lockObj), __sync_status__=0)

#define __SYNCALIAS__(_1, _2, NAME, ...) NAME

#define __SYNC__(...) __SYNCALIAS__(__VA_ARGS__, __SYNC_X__, __SYNC_M__)(__VA_ARGS__)

 
#define synchronized(...) __SYNC__(__VA_ARGS__)


/**
 * A classical synchronisation problem where an integer is incremented and 
 * decremented by two parallel threads for a fixed number of iterations. The 
 * resultant value should always be:
 * 
 *     final_val = inital_val + inc_iterations - dec_iterations
 * 
 * @param[in/out] variable The thread common variable
 * @param[in] inc_iterations The number of iterations to run the increment loop
 * @param[in] dec_iterations The number of iterations to run the decrement loop
 * 
 * @return 0 on success. Failure otherwise.
 */
extern int sync_incdec(int* variable, int inc_iterations, int dec_iterations);



#ifdef  __cplusplus
}
#endif

#endif