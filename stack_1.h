#ifndef __STACK_1_H
#define __STACK_1_H

#include <stack>

using namespace std;

struct node {
  string name;
  int number;
};


stack<int> get_stack(const int n);
stack<node> get_stack_node(const int n);

void push_node_stack(stack<node> *stack, const int x);
node pop_node_stack(stack<node> *stack);

int get_stack_sum(stack<node>stack);

stack<node> make_stack(const int values[], const int num_values);


#endif
