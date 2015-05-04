//
//  array.cpp
//  4
//
//  Created by Aaron Yih on 5/4/15.
//  Copyright (c) 2015 aaronyih. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int enumerate(const string a[], int n, string target){
    int counter=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==target)
        {
            counter++;
        }
    }
    return(counter);
}



int main() {
    string people[8]={"samwell", "jon", "margaery", "daenerys", "tyrion", "tyrion", "tyrion"};
    cerr<< enumerate(people,8,"tyrion")<< endl;
}