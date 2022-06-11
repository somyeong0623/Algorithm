//18312.시각
#include <iostream>
#include <string>
using namespace std;

int n,k;
int h,m,s;
string temp; 
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>k;

    while(true){

         if(s==60){
            s=0;
            m++;
        }
        if(m==60){
            m=0;
            h++;
        }
        string sh=to_string(h);
        string sm=to_string(m);
        string ss=to_string(s);
        
        if(h<10) // 각 숫자가 한자리숫자면 앞에 0 붙여주어야함.
            sh='0'+sh;
        if(m<10)
            sm='0'+sm;
        if(s<10)
            ss='0'+ss;

        temp=sh+sm+ss;
        // cout<<"temp: "<<temp<<"\n";

        for(int i=0; i<temp.size(); i++){
            if(temp[i]-'0'==k){
                answer++;
                break;
            }
        }
    
        if(h==n && m==59 && s==59)
            break;

         s++;
    }

    cout<<answer<<"\n";


}