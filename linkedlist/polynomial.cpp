#include "polynomial.h"
#include <iostream>

PolyNode::PolyNode()
{
    coefficient = exponent = 0;
    next = nullptr;
}

PolyNode::PolyNode(int coefficient, int exponent)
{
    this->coefficient = coefficient;
    this->exponent = exponent;
    next = nullptr;
}

PolyNode::~PolyNode() {}

Polynomial::Polynomial()
{
    head = tail = nullptr;
}

Polynomial::~Polynomial()
{
    PolyNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void Polynomial::append(PolyNode *node)
{
    if (head == nullptr)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

void Polynomial::display()
{
    if (head != nullptr)
    {
        PolyNode *temp = head;
        while (temp != nullptr)
        {
            if (temp->coefficient != 1)
                std::cout << temp->coefficient;
            if (temp->exponent == 1)
                std::cout << "x";
            else if (temp->exponent != 0)
                std::cout << "x^" << temp->exponent;
            if (temp->next != nullptr)
                std::cout << " + ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Polynomial has no terms" << std::endl;
    }
}

void Polynomial::create()
{
    int totalTerms;
    std::cout << "Enter No of Terms in Polynomial : ";
    std::cin >> totalTerms;
    std::cout << "Enter Polynomail Terms : ";
    for (int i = 0; i < totalTerms; i++)
    {
        int coeff, expo;
        std::cin >> coeff;
        std::cin >> expo;
        PolyNode *node = new PolyNode(coeff, expo);
        append(node);
    }
}

Polynomial Polynomial::add(Polynomial b)
{
    Polynomial c;
    PolyNode *first = head, *second = b.head;
    int expo = 0, coeff = 0;

    while (first != nullptr && second != nullptr)
    {
        if (first->exponent == second->exponent)
        {
            coeff = first->coefficient + second->coefficient;
            expo = first->exponent;

            first = first->next;
            second = second->next;
        }
        else if (first->exponent > second->exponent)
        {
            coeff = first->coefficient;
            expo = first->exponent;
            first = first->next;
        }
        else
        {
            coeff = second->coefficient;
            expo = second->exponent;
            second = second->next;
        }
        PolyNode *newTermNode = new PolyNode(coeff, expo);
        c.append(newTermNode);
    }

    while (first != nullptr)
    {
        coeff = first->coefficient;
        expo = first->exponent;
        first = first->next;
        PolyNode *newTermNode = new PolyNode(coeff, expo);
        c.append(newTermNode);
    }

    while (second != nullptr)
    {
        coeff = second->coefficient;
        expo = second->exponent;
        second = second->next;
        PolyNode *newTermNode = new PolyNode(coeff, expo);
        c.append(newTermNode);
    }

    return c;
}