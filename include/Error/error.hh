#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

#include "globals.hh"

class Evaluation_exception : public std::runtime_error
{
    private:
        Object obj;
        Env env;
        std::string message;

    public:
        Evaluation_exception();
        Evaluation_exception(Object _obj, Env _env, std::string _message);
};
void error(Object obj, Env env, std::string s);
void error(std::string s);

class Zipping_exception : public std::runtime_error
{
    private:
        std::string message;
        Object lobjs;

    public:
        Zipping_exception(Object _lobjs, std::string _message);
};

class Quit_exception : public std::exception
{
    public:
        Quit_exception(){};
};
void quit();

class No_binding_exception : public std::runtime_error
{
    private:
        std::string name;

    public:
        No_binding_exception(std::string _name);
};

class Number_param_exception : public std::runtime_error {
    private:
        std::string name; //nb = 0 if there are too many param and 1 if there are too many variables
    public:
        Number_param_exception(std::string _name);
};
