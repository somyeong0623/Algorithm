    //16194번: 카드 구매하기2
    #include <iostream>
    #include <cmath>
    using namespace std;

    int p[1001];
    int d[1001];

    int main(){
        int n;
        cin>>n;

        for(int i=1; i<=n; i++){
            cin>>p[i];
        }

        d[0]=0;
        d[1]=p[1];

        for(int i=2; i<=n; i++){
            //주의할점: d[i]에 초깃값을 설정해 주어야 한다. 그렇지 않으면 d[i]는 초기에 0인 상태라서 최솟값도 0이 되어버린다.
            //그래서 초깃값으로 d[i]이 될 수 있는 방법중에 하나를 넣어주었다.
            //일단은 제일 간단한 d[i]=p[i]로 하였다. 다른 방법으로 초기화 해도 상관없다.
            d[i]=p[i];
            for(int j=0; j<=i-1; j++){
                int temp=d[j]+p[i-j];
                if(d[i]>temp){
                    d[i]=temp;
                    // cout<<"i: "<<i<<", j: "<<j<<"\n";
                    // cout<<"temp: "<<temp<<"\n";
                }
            }
        }

        cout<<d[n]<<"\n";
    }