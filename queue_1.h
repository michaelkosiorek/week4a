#ifndef __QUEUE_1_H
#define __QUEUE_1_H

#include "stack_1.h" // includes node struct

void push_node_queue(queue<node> *queue, const int x);
node dequeue_node_queue(queue<node> *queue);

int get_queue_sum(queue<node>queue);

queue<node> make_queue(const int values[], const int num_values);

#endif