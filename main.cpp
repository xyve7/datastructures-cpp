#include <format>
#include <iostream>
#include "my_vector.h"
#include "my_stack.h"

int main() {
    my_vector<int> val;
    val.add(10);
    val.add(11);
    val.add(12);
    val.add(13);
    val[0] = 100;
    my_vector<int> val2 = val;

    std::cout << val << "\n" << val2 << "\n" << std::boolalpha << (val == val2) << "\n";

    my_stack<int> stk;
    stk.push(10);
    stk.push(11);
    stk.push(12);
    stk.push(13);

    my_stack<int> stk2 = stk;

    std::cout << stk << "\n" << stk2 << "\n" << std::boolalpha << (stk == stk2) << "\n";
    return 0;
}
