#include <iostream>
#include <stack>
#include <string>

#include "stack_1.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

stack<node> get_stack_node(const int n) {
  stack<node> s;

  for (int i=0; i < n; i++) {
    if (i >= sizeof(names)) {
      node my_node;
      my_node.name = "Plato";
      my_node.number = i;
      
      s.push(my_node);
    } else {
      node my_node;
      my_node.name = names[i];
      my_node.number = i;
      
      s.push(my_node);
    }
  }

  return s;
}

stack<int> get_stack(const int n) {

  stack<int> s;

  for (int i=0; i < n; i++) {
    s.push(i);
  }

  return s;
}

void push_node_stack(stack<node> *stack, const int x) {

  node new_node;
  new_node.number=x;

  stack->push(new_node);
}

node pop_node_stack(stack<node> *stack) {

  node popped_node;

  // shouldn't trigger if used properly
  if (stack->empty()) {
    popped_node.name="Stack Empty";
    return popped_node;
  }

  popped_node = stack->top();
  // top does NOT remove node
  stack->pop();
  
  return popped_node;
}

int get_stack_sum(stack<node>stack) {

  int stack_sum=0;
  while (!stack.empty()) {
    node popped_node= pop_node_stack(&stack);
    stack_sum += popped_node.number;
    // cout << "Added: " << popped_node.number << endl;
  }
  if (stack_sum < 0) throw std::string("Negative Stack Sum!");

  return stack_sum;
}

stack<node> make_stack(const int values[], const int num_values) {

  stack<node> node_stack;
  for (int i=0; i < num_values; i++) {
    node new_node;
    new_node.number=values[i];
    push_node_stack(&node_stack, new_node.number);
  }

  return node_stack;

}