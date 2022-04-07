//10866_덱
#include <iostream>
using namespace std;

int n;
int front,back;
int arr[10000];
string s;
int x;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size=0;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push_front"){
            cin>>x;
            arr[front]=x;
            front++;
            size++;
        }else if(s=="push_back"){
            cin>>x;
            arr[back]=x;
            back++;
            size++;

        }else if(s=="pop_front"){
            if(size==0)
            cout<<-1<<"\n";
            else{
                cout<<arr[front]<<"\n";
                arr[front]=0;
                front++;
                size--;
            }
        }else if(s=="pop_back"){
            if(size==0)
            cout<<-1<<"\n";
            else{
                cout<<arr[back]<<"\n";
                arr[back]=0;
                back--;
                size--;
            }
        }else if(s=="size"){
            cout<<size<<"\n";

        }else if(s=="emptty"){
            if(size==0)
            cout<<1<<"\n";
            else
            cout<<0<<"\n";

        }else if(s=="front"){
            if(size==0)
            cout<<-1<<"\n";

            else
            cout<<arr[front]<<"\n";
        }else{ //back인 경우
            if(size==0)
            cout<<-1<<"\n";

            else
            cout<<arr[back]<<"\n";
        }

        for(int i=0;i<size; i++){
            cout<<arr[i]<<" ";
        }
            
    }


}