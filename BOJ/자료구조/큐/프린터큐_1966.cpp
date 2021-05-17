#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printer_queue(){
    vector<pair<int, int>> doc;
    vector<pair<int, int>> sorted;
    vector<pair<int, int>> temp;

    int N, M, priority, count = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> priority;
        doc.push_back(make_pair(priority, i));
    }
    sorted = doc;
    sort(sorted.begin(), sorted.end(), greater<>());

    while(1){
        for(int i = 0; i != doc.size(); i++){
            if((doc[0].second == M) && (doc[0].first == sorted[count].first)){cout << count+1 << endl; return;}
            else if(sorted[count].first == doc[0].first){
                count++;
                doc.erase(doc.begin());
                break;
            }
            else{
                temp.push_back(doc[0]);
                doc.erase(doc.begin());
                doc.push_back(temp.front());
                temp.clear();
            }
        }
    }
}

int main(){
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) { printer_queue(); }
    return 0;
}
