#include<cstdio>
#include<algorithm>
using namespace std;
const double ebs=1e-9;
struct glass{
    int cap;
    double con;
};
bool cmp(glass a,glass b){
    if(a.cap==b.cap){
        return a.con>b.con;
    }
    return a.cap>b.cap;
}
bool cmp2(glass a,glass b){
    if(abs(a.con-b.con)<ebs){
        return a.cap>b.cap;
    }
    return a.con>b.con;
}
int main(){

}