#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct V{
    vector<int> edge;
    int indegree = 0;
};

int N;
vector<V> order;

void topologicalSort(){ //indegree�� Ȱ���� ��������
    priority_queue< int, vector<int>, greater<int> > pq;    //�ּ� ��
    for(int i = 1; i <= N; i++){
        if(order[i].indegree == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        cout << now << " ";

        for(int i = 0; i < order[now].edge.size(); i++){
            int next = order[now].edge[i];
            order[next].indegree--;
            if(order[next].indegree == 0){
                pq.push(next);
            }
        }
    }
}

void input(){
    int M, A, B;
    cin >> N >> M;
    V temp;
    order.resize(N+1, temp);

    // Make graph
    while(M--){
        cin >> A >> B; //A�� ������ B�� �������� ���� Ǫ�� ���� ���ٴ� �ǹ�
        order[A].edge.push_back(B);
        order[B].indegree++;
    }

//    for(int i = 1; i <= N; i++){
//        cout << i << " : ";
//        for(int j = 0; j < order[i].edge.size(); j++){
//            cout << order[i].edge[j] << " ";
//        }
//        cout <<"\n" << order[i].indegree <<"\n";
//        cout << "\n";
//    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    topologicalSort();

    return 0;
}
