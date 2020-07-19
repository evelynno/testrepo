#ifndef MAIN_H
#define MAIN_H

// # the file read from top down, if you dont define a function you cant use it
// theres a function that exsits that has a name and you can use it later.
// header tells the c ccompliler that the function exsists and should be able to call that

// if you want to use a function in c you need a header file. For python only thing you need is a libaray




class interface {
 public:
    interface(){}
    virtual int public_function();
    virtual ~interface();
private:
    virtual int private_function();
};

struct int_cx {
    interface* in;
};

// Need an extern "C" to be seen by ctypes
extern "C" int_cx* create_cx();

extern "C" int call_public(int_cx* cx);

extern "C" int outside_function();

extern "C" int inside_function();

extern "C" int add_two_ints(int a, int b);

#endif
