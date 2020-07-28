#include "polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;

Polynomial::Polynomial() : MAX_TERMS(100)
{
    terms = new Term[MAX_TERMS];
    totalTerms = 0;
}

Polynomial::~Polynomial() {}

void Polynomial::create()
{
    cout << "Enter No of terms in polynomial : ";
    cin >> totalTerms;
    cout << "Enter Terms : ";
    for (int i = 0; i < totalTerms; i++)
    {
        cin >> terms[i].coefficient;
        cin >> terms[i].exponent;
    }
}

void Polynomial::display()
{
    if (totalTerms > 0)
    {
        for (int i = 0; i < totalTerms; i++)
        {
            if (terms[i].coefficient != 1)
                cout << terms[i].coefficient;
            if (terms[i].exponent == 1)
                cout << "x";
            else if (terms[i].exponent != 0)
                cout << "x^" << terms[i].exponent;
            if (i != totalTerms - 1)
                cout << " + ";
        }
        cout << endl;
    }
    else
    {
        cout << "Please read polynomial first!" << endl;
    }
}

double Polynomial::evaluate(double x)
{
    double result = 0.0;
    for (int i = 0; i < totalTerms; i++)
    {
        result += terms[i].coefficient * pow(x, terms[i].exponent);
    }
    return result;
}

Polynomial Polynomial::add(Polynomial b)
{
    Polynomial c;
    int i = 0, j = 0, k = 0;
    while (i < totalTerms && j < b.totalTerms)
    {
        if (terms[i].exponent == b.terms[j].exponent)
        {
            c.terms[k].coefficient = terms[i].coefficient + b.terms[j].coefficient;
            c.terms[k].exponent = terms[i].exponent;
            i++;
            j++;
            k++;
        }
        else if (terms[i].exponent > b.terms[j].exponent)
        {
            c.terms[k].coefficient = terms[i].coefficient;
            c.terms[k].exponent = terms[i].exponent;
            i++;
            k++;
        }
        else
        {
            c.terms[k].coefficient = b.terms[j].coefficient;
            c.terms[k].exponent = b.terms[j].exponent;
            j++;
            k++;
        }
    }

    while (i < totalTerms)
    {
        c.terms[k].coefficient = terms[i].coefficient;
        c.terms[k].exponent = terms[i].exponent;
        i++;
        k++;
    }

    while (j < b.totalTerms)
    {
        c.terms[k].coefficient = b.terms[j].coefficient;
        c.terms[k].exponent = b.terms[j].exponent;
        j++;
        k++;
    }
    c.totalTerms = k;
    return c;
}

Polynomial Polynomial::subtract(Polynomial b) {
    for (int i = 0; i < b.totalTerms; i++) {
        b.terms[i].coefficient = -b.terms[i].coefficient;
    }
    return add(b);
}

Polynomial Polynomial::multiply(Polynomial b) {
    Polynomial c;
    int k = 0;

    for (int i = 0; i < totalTerms; i++) {
        for (int j = 0; j < b.totalTerms; j++) {
            int newCoefficient = terms[i].coefficient * b.terms[j].coefficient;
            int newExponent = terms[i].exponent + b.terms[j].exponent;
            bool flag = false;
            int tempIndex = 0;
            while (tempIndex < k) {
                if (c.terms[tempIndex].exponent == newExponent) {
                    flag = true;
                    break;
                }
                else if (c.terms[tempIndex].exponent < newExponent)
                    break;
                tempIndex++;
            }

            if (flag) {
                c.terms[tempIndex].coefficient = c.terms[tempIndex].coefficient + newCoefficient;
            }
            else {
                if (tempIndex == k) {
                    c.terms[tempIndex].exponent = newExponent;
                    c.terms[tempIndex].coefficient = newCoefficient;
                    k++;
                }
                else {
                    for (int p = k; p > tempIndex; p--) {
                        c.terms[p].coefficient = c.terms[p - 1].coefficient;
                        c.terms[p].exponent = c.terms[p - 1].exponent;
                    }
                    c.terms[tempIndex].exponent = newExponent;
                    c.terms[tempIndex].coefficient = newCoefficient;
                    k++;
                }
            }
        }
    }
    c.totalTerms = k;
    return c;

}