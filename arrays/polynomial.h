#ifndef __POLYNOMIAL__
#define __POLYNOMIAL__
#include "term.h"

class Polynomial
{
private:
    const int MAX_TERMS;
    int totalTerms;
    Term *terms;

public:
    Polynomial();
    ~Polynomial();
    void create();
    void display();
    double evaluate(double x);
    Polynomial add(Polynomial b);
    Polynomial subtract(Polynomial b);
    Polynomial multiply(Polynomial b);
};

#endif