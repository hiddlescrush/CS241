/**
 * Savvy Scheduler
 * CS 241 - Spring 2019
 */
/**
* Savvy_scheduler Lab
* CS 241 - Fall 2018
*/

#pragma once

typedef int (*comparer_t)(const void *, const void *);
typedef struct _entry {
    void *value;
    struct _entry *next;
} entry;

/**
  Priqueue Data Structure
*/
typedef struct _priqueue_t {
    comparer_t comparer;
    int size;
    entry *head;
} priqueue_t;

/**
  Initializes the priqueue_t data structure.
  With the comparer function (taking arguments a and b):
    - a will come before b if a negative value is returned
    - b will before a if the a positive value is returned
    - elements will be kept in the order they are added if zero is returned.

  Assumtions
    - You may assume this function will only be called once per instance of
  priqueue_t
    - You may assume this function will be the first function called using an
  instance of priqueue_t.
  @param q a pointer to an instance of the priqueue_t data structure
  @param comparer a function pointer that compares two elements.
  See also @ref comparer-page
 */
void priqueue_init(priqueue_t *q, comparer_t comparer);

/**
  Inserts the specified element into this priority queue.

  @param q a pointer to an instance of the priqueue_t data structure
  @param ptr a pointer to the data to be inserted into the priority queue
  @return The zero-based index where ptr is stored in the priority queue, where
  0 indicates that ptr was stored at the front of the priority queue.
 */
int priqueue_offer(priqueue_t *q, void *ptr);

/**
  Retrieves, but does not remove, the head of this queue, returning NULL if
  this queue is empty.

  @param q a pointer to an instance of the priqueue_t data structure
  @return pointer to element at the head of the queue
  @return NULL if the queue is empty
 */
void *priqueue_peek(priqueue_t *q);

/**
  Retrieves and removes the head of this queue, or NULL if this queue
  is empty.

  @param q a pointer to an instance of the priqueue_t data structure
  @return the head of this queue
  @return NULL if this queue is empty
 */
void *priqueue_poll(priqueue_t *q);

/**
  Returns the number of elements in the queue.

  @param q a pointer to an instance of the priqueue_t data structure
  @return the number of elements in the queue
 */
int priqueue_size(priqueue_t *q);

/**
  Destroys and frees all the memory associated with q.

  @param q a pointer to an instance of the priqueue_t data structure
 */
void priqueue_destroy(priqueue_t *q);
