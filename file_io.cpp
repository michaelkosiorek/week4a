#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

#include "stack_1.h"
#include "queue_1.h"

using namespace std;

int main() {

  ifstream input_file;
  input_file.open("input.txt");

  stack<node> values_stack;
  queue<node> values_queue;

  while (!input_file.eof()) {
    string in_str;
    input_file >> in_str;
    int x;
    x = stoi(in_str);
    push_node_stack(&values_stack, x);
    push_node_queue(&values_queue, x);
    cout << x << endl;
  }

  // attempt to get stack sum, catch error if negative
  try {
    int stack_sum=get_stack_sum(values_stack);
    cout << "Stack sum is: " << stack_sum << endl;
  } catch(string error) {
    cout << "Stack Sum Error: " << error << endl;
    return 1;
  }
  
  // attempt to get queue sum, catch error if negative
  try {
    int queue_sum=get_queue_sum(values_queue);
    cout << "Queue sum is: " << queue_sum << endl;
  } catch(string error) {
    cout << "Queue Sum Error: " << error << endl;
    return 1;
  }

  input_file.close();   
}
