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
    if(n<0)
    {
        return(-1);
    }
    for(int i = 0; i<n; i++)
    {
        if(a[i]==a[i+1]){
            moveToEnd(a, n, i+1);
            n--;
            i--;
        }
    }
    for(int j=0; j<n+1;j++)
    {
        cerr<<"here is cerr: "<<a[j]<<endl;
    }
    return(n+1);
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
    
    for(int f=0; f<20;f++)
    {
        cerr<<f<< " is : "<<result[f]<< endl;
    }
    return(counter);
    
}

int divide(string a[], int n, string divider){
    string temp;
    string temp2;
    int index2=n-1;
    int index=0;
    int counter =0;
    for(int i = 0; i<n; i++){
            if(a[i]<divider)
            {
                temp=a[index];
                a[index]=a[i];
                a[i]=temp;
                index++;
                counter++;
            }
            else if(a[i]==divider)
            {
                a[i]=divider;
            }
            else{
                temp=a[index2];
                a[index2]=a[i];
                a[i]=temp;
                index2--;
            }
        }
    return(counter+1);
}

int main() {
    string g[4] = { "samwell", "margaery", "tyrion", "jon" };
    int s = divide(g, 4, "margaery");
    cerr<<"s is here: "<<s<<endl;
}
