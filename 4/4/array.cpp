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
    if(n<0)
    {
        return(false);
    }
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
    if(n<0)
    {
        return(false);
    }
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
int moveToBeginning(string a[], int n, int pos){
    string temp = a[pos];
    if(n<0)
    {
        return(false);
    }
    for(int i=pos; i>0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=temp;
    for(int j=0; j<n; j++){
        cerr<<a[j]<<endl;
    }
    return(pos);
    
}
int locateDifference(const string a1[], int n1, const string a2[], int n2){
    if((n1<0)||(n2<0))
    {
        return(-1);
    }
    if(n1<=n2){
        for(int i = 0; i<n1; i++)
        {
            if(a1[i]!=a2[i])
            {
                return(i);
            }
        }
        return(n1);
    }
    else{
        for(int j=0; j<n2;j++){
            if(a1[j]!=a2[j])
            {
                return(j);
            }
        }
        return(n2);
    }
}

int eliminateDups(string a[], int n){
    int count = -1;
    if(n<0)
    {
        return(false);
    }
    for(int i = 0; i<n; i++)
    {
        if(a[i]==a[i+1])
        {
            for(int j = i+1; a[j]==a[i]; j++)
            {
                count++;
                i++;
            }
            while(count > 0){
                
            }
        }
    }
}
int main() {
    string cast[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string roles[4] = { "samwell", "jon", "sansa", "jaime" };
    int k = locateDifference(cast, 5, roles, 4);  //  returns 2
    int m = locateDifference(cast, 2, roles, 1);
    cerr<< "k is : " << k <<endl;
    cerr<<"m is : " << m <<endl;
}
