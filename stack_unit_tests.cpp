#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "stack_1.h"

const int values1[] = {10, 100, 10000, -10000, 0, 0, 0, 0, 0, 0, 0, 0};
const int values_sum_actual1 = 110;
const int n_values1=12;

const int values2[] = {};
const int values_sum_actual2 = 0;
const int n_values2=0;

const int values3[] = {10, 100, -111};
const int values_sum_actual3 = -1;
const int n_values3=3;

const int values4[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 99};
const int values_sum_actual4 = 100;
const int n_values4=100;


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        const int my_stack_size_Zero = 0;
        stack<int> s0 = get_stack(my_stack_size_Zero);
        CHECK(s0.size() == my_stack_size_Zero);

        const int my_stack_size = 6;
        stack<int> s1 = get_stack(my_stack_size);
        CHECK(s1.size() == my_stack_size);

        const int my_stack_size_node = 5;
        stack<node> s2 = get_stack_node(my_stack_size_node);
        CHECK(s2.size() == my_stack_size_node);

        node test = s2.top();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);

    };

    SUBCASE("stack copying") {

        const int my_stack_size = 6;
        stack<int> s = get_stack(my_stack_size);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());

        CHECK_FALSE(s == t);

    }

    SUBCASE("no exception regular test") {

        stack<node> stack_1 = make_stack(values1, n_values1);
        CHECK_EQ(get_stack_sum(stack_1), values_sum_actual1);

    }

    SUBCASE("no exception edge test") {

        stack<node> stack_2 = make_stack(values2, n_values2);
        CHECK_EQ(get_stack_sum(stack_2), values_sum_actual2);

    }

    SUBCASE("exception test") {

        stack<node> stack_3 = make_stack(values3, n_values3);
        CHECK_THROWS_WITH(get_stack_sum(stack_3), "Negative Stack Sum!");

    }

    SUBCASE("many values test") {

        stack<node> stack_4 = make_stack(values4, n_values4);
        CHECK_EQ(get_stack_sum(stack_4), values_sum_actual4);

    }

};