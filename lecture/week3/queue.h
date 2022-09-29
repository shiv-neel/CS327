// header guard, prevents multiple inclusions of the file
#ifndef QUEUE_H
#define QUEUE_H

// typedef <old type name> <new type name>
typedef struct node node_t;

struct node
{
  int data;
  node_t *next;
};

typedef struct queue
{
  struct node *head, *tail;
  int size;
} queue_t;

int queue_init(queue_t *q);              // constructor
int queue_deinit(queue_t *q);            // destructor (bc no garbage collection)
int queue_enqueue(queue_t *q, int data); // not a pointer bc we are passing it in as a value
int queue_dequeue(queue_t *q, int *data);
int queue_head(queue_t *q, int *data);
int queue_size(queue_t *q);
int queue_isEmpty(queue_t *q);

#endif