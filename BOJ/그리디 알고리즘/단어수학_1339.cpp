#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<char, int> ci;

vector<string> word;
vector<ci> alpha_vec;
map<char, int> alpha;
int N;

void input(){
    cin >> N;
    string wd;
    for(int i = 0; i < N; i++){
        cin >> wd;
        word.push_back(wd);
        for(int k = 0; k < wd.size(); k++){
            alpha[wd[k]] += pow(10, wd.size()-k-1);
        }
    }
    for(auto w : alpha){
//        cout << w.first << " " << w.second << endl;
        alpha_vec.push_back({w.first, w.second});
    }
}

void solve(){
    int result = 0;
    
    sort(alpha_vec.begin(), alpha_vec.end(), [](ci a, ci b) {return a.second > b.second;});
    
//    for(int i = 0; i < alpha_vec.size(); i++){
//        cout << alpha_vec[i].second << endl;
//    }
    
    int j = 0;
    for(int i = 9; i >= 0; i--){
//        cout << result << endl;
        if(j >= alpha_vec.size()) break;
        result += (i*alpha_vec[j].second);
        j++;
    }
    cout << result;
}

int main(){
    input();
    solve();
    
    return 0;
}
