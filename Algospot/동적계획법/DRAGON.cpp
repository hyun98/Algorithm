#include <iostream>

using namespace std;

const int INF = 1000000009;
class Dragon{
    int n, p, l, geneNum[52];
    string result = "";
    string Seed[2] = {"X+YF", "FX-Y"};
    
public:
    Dragon(){
        cin >> n >> p >> l;
        geneNum[0] = 1;
        for(int i = 1; i < 51; i++){
            geneNum[i] = min(geneNum[i-1]*2 + 2, INF);
        }
        
        for(int i = 0; i < l; i++){
            cout << find_curve("FX", n, p+i-1);
        }
        cout << endl;
    }
    
    char find_curve(const string &dragonc, int gene, int print_idx){
        if(gene == 0){
            return dragonc[print_idx];
        }
        
        for(int i = 0; i < dragonc.size(); i++){
            if(dragonc[i] == 'X' || dragonc[i] == 'Y'){
                if(print_idx >= geneNum[gene]){
                    print_idx -= geneNum[gene];
                }
                else if(dragonc[i] == 'X'){
                    return find_curve(Seed[0], gene-1, print_idx);
                }
                else{
                    return find_curve(Seed[1], gene-1, print_idx);
                }
            }
            else if(print_idx > 0){
                print_idx--;
            }
            else{
                return dragonc[i];
            }
        }
        return '#';
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        Dragon D1;
    }
    return 0;
}
