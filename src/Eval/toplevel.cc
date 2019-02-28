#include "toplevel.hh"
#include "read.hh"
#include "eval.hh"
#include "library.hh"
#include <iostream>

Toplevel::Toplevel()
{
    global_env = *(new Env());
}

void Toplevel::go(bool use_prompt)
{

    while(true)
    {
        std::cout << "C++Lisp: ";
        Object curr_obj = read_object();
        curr_obj = eval(curr_obj,global_env);
        std::cout << curr_obj << std::endl;
        print_type(std::cout,curr_obj);
        std::cout << std::endl;
    }
}
