//1759번: 암호 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
char arr[16];
char answer[16]; 
bool check[16];
int vowel; //모음갯수
int consonant; //자음갯수



void func(int index,int start, int l, int c){
 
    if(index==l){
        vowel=0;
        consonant=0;

        for(int i=0; i<l; i++){
            if(answer[i]=='a'||answer[i]=='e'||answer[i]=='i'||answer[i]=='o'||answer[i]=='u')
            vowel++;
            else
            consonant++;
        }

        if(vowel>=1 && consonant>=2){
            for(int i=0; i<l; i++){
                cout<<answer[i];
            }
            cout<<"\n";
             return;
        }
        return;
            
        }
       
        //여기서, i=start하면 이전함수에서 i번째 였으니까 1번의 중복이 발생할 수 있지만
        //if(chekc[i])로 중복체크해주니까 상관없다.
        //또는 중복체크 안하고, 재귀함수 호출할때 func(index+1,i+1,l,c)이렇게 start에 i+1를 넣어주어도 된다.


        for(int i=start+1; i<c; i++){
            // if(check[i])
            // continue;

            check[i]=true;
            answer[index]=arr[i];
            func(index+1,i,l,c);
            check[i]=false;
            
        }
    }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   cin>>l>>c;

   for(int i=0; i<c; i++){
       cin>>arr[i];
   }
    sort(arr,arr+c);
    // for(int i=0; i<c; i++){
    //     cout<<arr[i]<< " ";
    // }
    func(0,0,l,c);
}
