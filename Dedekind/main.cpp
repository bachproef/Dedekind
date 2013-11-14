//
//  main.cpp
//  Dedekind
//
//  Created by Max Dekoninck on 12/11/13.
//  Copyright (c) 2013 Daan en Max. All rights reserved.
//

#include <iostream>
#include <math.h>


long long faculty(long long n)
{
    if (n == 1 or n == 0 ) {
        return 1;
    }
    else {
        return faculty(n-1) * n;
    }
}


long long combinatie(int n, int k)
{
    return faculty(n)/(faculty(k)*faculty((n-k)));
}

long long upperbound()
{
    return 4;
}

long long upperbound(int dedekindnumber)
{
    return pow(2, combinatie(dedekindnumber,floor(dedekindnumber/2)+2) );
}

long long lowerbound(int dedekindnumber)
{
    return pow(2, combinatie(dedekindnumber,floor(dedekindnumber/2)));
}

int main(int argc, const char * argv[])
{
    
    // insert code here..
    std::cout << "lowerbound is: " << lowerbound(4) << "\n";
//    std::cout << "upperbound is:" << upperbound(0) << "\n";
    return 0;
}

