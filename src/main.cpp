#include "main.h"
#include <iostream>


interface::~interface () {

}
int interface::public_function() {
    std::cout << "inside public_function" << std::endl;
    if (private_function()) {
        std::cout << "hit this if case" << std::endl;
        return 1;
    } else {
        std::cout << "hit this else case" << std::endl;
    }
    return 0;
}

int interface::private_function() {
    std::cout << "inside private_function" << std::endl;
    return 1;
}

int add_two_ints(int a, int b){
   //std::cout << "Inside Add Two Ints" << std::endl;
   return a + b;
}

int outside_function() {
    if(inside_function())
        return 1;
    else
        return 0;
}

int inside_function() {
    return 1;
}

int_cx* create_cx() {
    int_cx* cx = new int_cx();
    interface* in = new interface();
    cx->in = in;
    return cx;
}

int call_public(int_cx* cx) {
    return cx->in->public_function();
}
