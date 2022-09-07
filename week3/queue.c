#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int queue_init(queue_t *q)
{
  q->size = 0; // arrow notation bc q is a pointer to a struct
  q->head = q->tail = NULL;
}

int queue_deinit(queue_t *q)
{
  return 0;
}

int queue_enqueue(queue_t *q, int data)
{
  if (q->size) // queue is not empty, add to tail
  {
    if (!(q->tail->next = malloc(sizeof(*q->tail->next))))
    { /* if this condition fails */
      return 1;
    }
  }
  else // queue is empty, add first node
  {
    /*
      `sizeof` is a compile-time operator returning size (in bytes) of the expression that follows
      new in Java == malloc() in C
    */
    if (!(q->head = q->tail = malloc(sizeof(*q->tail))))
    {
      return 1;
    }
    q->tail->next = NULL;
    /* front and back are same instance, so front->next is also NULL */
  }
  q->size += 1;
  q->tail = data;
  return 0;
}

int queue_dequeue(queue_t *q, int *data) {}
int queue_head(queue_t *q) {}
int queue_size(queue_t *q) {}
int queue_isEmpty(queue_t *q) {}
int main(int argc, char *argv[])
{
}