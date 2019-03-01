#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

#include "globals.hh"



class Custom_exception : public std::runtime_error
{
    private:
        std::string message;
    public:
        Custom_exception(std::string msg);
        std::string what();
};

class Evaluation_exception : public Custom_exception
{

    public:
        Evaluation_exception();
        Evaluation_exception(std::string _message);
};

class Toplevel_exception : public Custom_exception
{
   public:
        Toplevel_exception(std::string _message);
};

class Quit_exception : public std::exception
{
    public:
        Quit_exception(){};
};

void eval_error(std::string s);

void toplevel_error(std::string s);

void quit();
