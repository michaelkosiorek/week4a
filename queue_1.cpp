#include <iostream>
#include <queue>
#include <string>

#include "queue_1.h"

using namespace std;

void push_node_queue(queue<node> *queue, const int x) {

  node new_node;
  new_node.number=x;

  queue->push(new_node);

}

node dequeue_node_queue(queue<node> *queue) {

  node dequeued_node;

  // shouldn't trigger if used properly
  if (queue->empty()) {
    dequeued_node.name="Queue Empty";
    return dequeued_node;
  }

  dequeued_node = queue->front();
  // top does NOT remove node
  queue->pop();
  
  return dequeued_node;

}

int get_queue_sum(queue<node>queue) {

  int queue_sum=0;
  while (!queue.empty()) {
    node dequeued_node = dequeue_node_queue(&queue);
    queue_sum += dequeued_node.number;
  }
  if (queue_sum < 0) throw std::string("Negative Queue Sum!");

  return queue_sum;
}

queue<node> make_queue(const int values[], const int num_values) {

  queue<node> node_queue;
  for (int i=0; i < num_values; i++) {
    node new_node;
    new_node.number=values[i];
    push_node_queue(&node_queue, new_node.number);
  }

  return node_queue;

}