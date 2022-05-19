//13547번: 팔씨름
#include <iostream>
using namespace std;

int n,cnt;

int main(){

    cin>>n;

    for(int i=1; i<=n; i++){
        cout<<"#"<<i<<" ";
        cnt=0;
        string s;
        cin>>s;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='x')
                cnt++;
        }

        if(cnt>=8)
            cout<<"NO"<<"\n";
        else
            cout<<"YES"<<"\n";
        
    }
}