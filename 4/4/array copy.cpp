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
    if(n<=0)
    {
        return(-1);
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
    if(pos>n)
    {
        return(-1);
    }
    string temp = a[pos];
    if(n<=0)
    {
        return(-1);
    }
    for(int i=pos; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;

    return(pos);
    
}
int moveToBeginning(string a[], int n, int pos){
    if(pos>n)
    {
        return(-1);
    }
    string temp = a[pos];
    if(n<=0)
    {
        return(-1);
    }
    for(int i=pos; i>0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=temp;
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
    int end=n;
    if(n<0)
    {
        return(-1);
    }
    for(int i = 0; i<n-1; i++)
    {
        if(a[i]==a[i+1]){
            moveToEnd(a, end, i+1);
            n--;
            i--;
        }
    }
    return(n);
}

bool subsequence(const string a1[], int n1, const string a2[], int n2){
    int j=0;
    int count=0;
    if((n1<0)||(n2<0))
    {
        return(false);
    }
    if(n1>n2)
    {
        for(int i=0; i<n1;i++)
        {
            if(a1[i]==a2[j])
            {
                j++;
                count++;
            }
        }
        if(count==n2)
        {
            return(true);
        }
    }
    else if(n2>n1)
    {
        for(int i=0; i<n2;i++)
        {
            if(a1[i]==a2[j])
            {
                j++;
                count++;
            }
        }
        if(count==n1)
        {
            return(true);
        }
    }
    else
    {
        for(int i=0; i<n2;i++)
        {
            if(a1[i]==a2[j])
            {
                j++;
                count++;
            }
        }
        if(count==n1)
        {
            return(true);
        }
    }
return(false);
}
int makeMerger(const string a1[], int n1, const string a2[], int n2,
               string result[], int max){
    string listLow1;
    string listLow2;
    int i=0;
    int j=0;
    int counter=0;
    string temp;
    int longer=n1;
    for(int i=1; i<n1;i++)
    {
        if((n1+n2)>max)
        {
            return(-1);
        }
        else if(a1[i-1]>a1[i])
        {
            return(-1);
        }
    }
    for(int l = 1; l<n2;l++)
    {
        if(a2[l-1]>a2[l])
        {
            return(-1);
        }
    }
    if((n1<0)||(n2<0))
    {
        return(-1);
    }
    if(n2>n1)
    {
        longer=n2;
    }
    while(counter<n1+n2){
        if(a1[i]>a2[j])
        {
            result[counter]=a2[j];
            j++;
            counter++;
        }
        else{
            result[counter]=a1[i];
            i++;
            counter++;
        }
    }
    return(counter);
    
}


int divide(string a[], int n, string divider){
    string temp;
    string temp2;
    int counter =0;
    if(n<0)
    {
        return(-1);
    }
    for(int i = 0; i<n; i++){
            if(a[i]<divider)
            {
                moveToBeginning(a, n, i);
            }
            else if(a[i]>divider){
                moveToEnd(a, n, i);
            }

        }
    for(int j=0; j<n; j++)
    {
        if(a[j]<divider)
        {
            counter++;
        }
    }
    return(counter);
}

int main() {
    string f[6] = { "cersei", "margaery", "sansa", "daenerys", "jon", "tyrion" };
    int r = divide(f, 6, "samwell");  //  returns 4
    cerr<<"this is r: "<< r<<endl;
    for(int i=0; i<6;i++)
    {
        cerr<< f[i]<<endl;
    }
}
