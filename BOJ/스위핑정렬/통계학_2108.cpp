#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> counting, numlist;
int N, sum = 0;

int Rounding( double x, int digit )
{
    return ( floor( (x) * pow( float(10), digit ) + 0.5f ) / pow( float(10), digit ) );
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    int x;
    cin >> N, x;
    counting.resize(8001, 0);
    numlist.reserve(N+1);
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x <= 0){
            counting[abs(x)]++;
        }
        else{
            counting[x+4000]++;
        }

        sum += x;
        numlist.push_back(x);
    }
    sort(numlist.begin(), numlist.end());
    cout << Rounding(double(sum)/N, 0) << "\n";


    cout << *(numlist.begin()+N/2) << "\n";

    vector<int> Bv;
    int bignum = 0;
    for(int i = 0; i < 8001; i++){
        if(bignum < counting[i]){
            bignum = counting[i];
        }
    }
    for(int i = 0; i < 8001; i++){
        if(counting[i] == bignum){
            if(i <= 4000){
                Bv.push_back(-i);
            }
            else{
                Bv.push_back(i-4000);
            }
        }
    }

    if(Bv.size() < 2){
        cout << Bv.front() << "\n";
    }
    else{
        sort(Bv.begin(), Bv.end());
        cout << *(Bv.begin()+1) << "\n";
    }

    cout << numlist.back() - numlist.front();


    return 0;
}
