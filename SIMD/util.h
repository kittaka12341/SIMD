#pragma once

#include <stdio.h>
using namespace std;

void printClock(clock_t elapsedTime)
{
    cout << "elapsed time is " << elapsedTime << endl;
}

void printValue(uint16_t a[], uint16_t b[], uint16_t c[], size_t size)
{
    cout << "a[0]=" << a[0] << "  a[size - 1]=" << a[size - 1] << endl;
    cout << "b[0]=" << b[0] << "  b[size - 1]=" << b[size - 1] << endl;
    cout << "c[0]=" << c[0] << "  c[size - 1]=" << c[size - 1] << endl;
}
