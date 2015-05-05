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
    if(n<0)
    {
        return(-1);
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]==target)
        {
            counter++;
        }
    }
    return(counter);
}

int locate(const string a[], int n, string target){
    if(n<0)
    {
        return(-1);
    }
    for(int i=0; i<n; i++)
    {
        if(a[i] == target){
            return(i);
        }
    }
    return(-1);
}

bool locateSequence(const string a[], int n, string target, int& begin, int& end){
    int counter=0;
    if(n<0)
    {
        return(false);
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]==target)
        {
            begin=i;
            while(a[i]==target){
                counter++;
                i++;
            }
            end=begin+counter-1;
            return(true);
        }
    }
    return(false);
}

int locationOfMin(const string a[], int n){
    string min=a[0];
    int position=0;
    for(int i=1; i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            position=i;
        }
    }
    return(position);
}

int moveToEnd(string a[], int n, int pos){
    string temp = a[pos];
    for(int i=pos; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;
    for(int j=0; j<n; j++){
        cerr<<a[j]<<endl;
    }
    return(pos);
    
}


int main() {
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    int j = moveToEnd(people, 5, 1);
    cerr<<j<<endl;
}
