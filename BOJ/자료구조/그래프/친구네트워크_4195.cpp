#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct I{
    string C;
    int cnt;
};

string get_topname(unordered_map<string, I> &net, string name){
    if(net[name].C == name){
        return name;
    }
    return net[name].C = get_topname(net, net[name].C);
}

void union_friend(unordered_map<string, I> &net, string name1, string name2){
    string a, b;
    a = get_topname(net, name1);
    b = get_topname(net, name2);

    if(net[a].cnt < net[b].cnt){
        swap(a, b);
    }
    if(net[a].C == net[b].C){
        cout << net[a].cnt <<"\n";
    }
    else{
        net[a].cnt += net[b].cnt;
        net[b].C = a;
        cout << net[a].cnt <<"\n";
    }
}

void input(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, F;
    cin >> N;
    for(int i = 0; i < N; i++){
        string name1, name2;
        cin >> F;
        unordered_map<string, I> net;
        for(int i = 0; i < F; i++){
            cin >> name1 >> name2;
            if(!net.count(name1)){
                net[name1] = {name1, 1};
            }
            if(!net.count(name2)){
                net[name2] = {name2, 1};
            }
            union_friend(net, name1, name2);
        }
    }
}

int main(){
    input();
    return 0;
}
