//10158번: 개미

/*

입력
w,h
p,q
t(개미가 움직일 시간)

출력
t시간후에 개미의 좌표 x,y

2<=w,h<=40,000
1<=t<=200,000,000

*/

#include <iostream>
using namespace std;

int w,h,p,q,t;
//시간초과 .. 
//모르겠어서 구글링함.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w>>h;
    cin>>p>>q;
    cin>>t;
   
    p+=t;
    q+=t;

    p%=(2*w);
    q%=(2*h);
    
    if(p>w)
    p=2*w-p;

    if(q>h)
    q=2*h-q;
 

    cout<<p<<" "<<q;
}   