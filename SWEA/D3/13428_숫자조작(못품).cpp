//13428번: 숫자 조작
#include <iostream>
using namespace std;


int n;

//최솟값을 구하는 방법은 가장 작은 숫자와 첫번째 자리 숫자를 바꾸면 된다.
//만약 가장작은 숫자가 첫번째 자리면 그다음 작은것을 고려해야 하는데 ,,,,,모르겠다.
//이때 가장작은숫자가 0이면 그 다음으로 작은 숫자와 첫번째 자리 수를 바꿔주어야 한다.
string min_num(string s){
    char min=s[0];
    int min_idx=0;
    int location=0;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='0') 
            continue;

        if(min>s[i]){
            min_idx=i;


            min=s[i];

        }
        
    }
    
    char temp=s[0];
    s[0]=min;
    s[min_idx]=temp;

    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int t=1; t<=n; t++){
        cout<<"#"<<t<<" ";

        string s;
        cin>>s;
        cout<<min_num(s)<<"\n";
    }

}