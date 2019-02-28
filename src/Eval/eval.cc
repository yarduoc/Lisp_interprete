#include <string>
#include <iostream>
#include <cassert>
#include "eval.hh"
#include "library.hh"
#include "defs.hh"

Object get_value_env(Object l, Env env)
{
    return l;
}

Object eval (Object l, Env env)
{
    if (null(l) || stringp(l) || numberp(l) || boolp(l))
    {
        return l;
    }
    else if (symbolp(l))
    {
        return get_value_env(l,env);
    }
    else
    {
        assert(listp(l));
        Object func = car(l);
        if (eq(func,lisp_plus))
        {
            return do_plus(cdr(l),env);
        }
        if (eq(func,lisp_minus))
        {
            return do_minus(cdr(l),env);
        }
        if (eq(func,lisp_times))
        {
            return do_times(cdr(l),env);
        }
        if (eq(func,lisp_inf))
        {
            return do_inf(cdr(l),env);
        }
        return (number_to_object(1));
    }
}

/*
Object apply (Object f, Object lvals, Env env)
{
    if(null(f))
    {
        throw new Evaluation_exception(f,env,"Cannot apply nil");
    }
    else if(f == t())
    {
        throw new Evaluation_exception(f,env,"Cannot apply true");
    }
    else if(f == f())
    {
        throw new Evaluation_exception(f,env,"Cannot apply false");
    }
    else if(numberp(f))
    {
        throw new Evaluation_exception(f,env,"Cannot apply a number");
    }
    else if(stringp(f))
    {
        throw new Evaluation_exception(f,env,"Cannot apply a string");
    }
    if (subrp (f))
    {
        return (apply_subr(f,lvals))
    }
    else if(symbolp (f))
    {
        return apply(eval(f,env),lvals,env);
    }
    else
    {
        assert(pairp(f));
        if(car(f)  = lisp_lambda)
        {
            // The body of the lambda-expression *)
            Object body = caddr f;
            // The list of parameters of the lamba-expression *)
            Object lpars = cadr f;
            Env new_env = extend_largs_env lpars lvals env in
            eval body new_env
        }
        else
        {
            throw new Evaluation_exception(f,env,"Cannot apply a list");
            let new_f = eval f env in
            eval (cons new_f lvals) env )
        }
    }
}*/