#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

class PolyNode
{
    public:
        PolyNode();
        PolyNode(int, int);
        ~PolyNode();
        int coefficient;
        int exponent;
        PolyNode *next;
};

class Polynomial {
    private:
        PolyNode *head, *tail;
        int totalTerms;
    public:
        Polynomial();
        ~Polynomial();
        void create();
        void display();
        void append(PolyNode *node);
};

#endif