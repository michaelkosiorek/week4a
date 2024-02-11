#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <queue>

#include "queue_1.h"

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


TEST_CASE("Queue tester") {
    
    SUBCASE("make_queue function test") {

        queue<node> queue_made_by_fcn = make_queue(values1, n_values1);

        queue<node> queue_manually_made;

        for (int i=0; i < n_values1; i++) {
            node node_to_add;
            node_to_add.number = values1[i];
            queue_manually_made.push(node_to_add);
        }

        CHECK_EQ(queue_made_by_fcn.size(), queue_manually_made.size());

        for (int j=0; j < n_values1; j++) {
            int function_queue_value = dequeue_node_queue(&queue_made_by_fcn).number;
            int manual_queue_value = dequeue_node_queue(&queue_manually_made).number;

            CHECK_EQ(function_queue_value, manual_queue_value);
        }

    }

    SUBCASE("no exception regular test") {

        queue<node> queue_1 = make_queue(values1, n_values1);
        CHECK_EQ(get_queue_sum(queue_1), values_sum_actual1);

    }

    SUBCASE("no exception edge test") {

        queue<node> queue_2 = make_queue(values2, n_values2);
        CHECK_EQ(get_queue_sum(queue_2), values_sum_actual2);

    }

    SUBCASE("exception test") {

        queue<node> queue_3 = make_queue(values3, n_values3);
        CHECK_THROWS_WITH(get_queue_sum(queue_3), "Negative Queue Sum!");

    }

    SUBCASE("many values test") {

        queue<node> queue_4 = make_queue(values4, n_values4);
        CHECK_EQ(get_queue_sum(queue_4), values_sum_actual4);

    }

};
