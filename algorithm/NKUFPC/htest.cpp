#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int a[N];
void qsort(int *a,int left,int right){
    if(left>=right)return;
    int l=left,r=right,mid=(left+right)/2;
    int pivot=a[mid];
    while(l<r){
        while(l<mid&&a[l]<=pivot)++l;
        swap(a[l],a[mid]);mid=l;
        while(mid<r&&a[r]>=pivot)--r;
        swap(a[r],a[mid]);mid=r;
    }
    qsort(a,left,mid-1);
    qsort(a,mid+1,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    qsort(a,0,n-1);
    for(int i=0;i<n;++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}