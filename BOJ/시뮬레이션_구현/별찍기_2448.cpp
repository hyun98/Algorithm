#include <iostream>
#include <cmath>
using namespace std;

int N;
string blank = " ";
string top = "  *  ", middle = " * * ", bottom = "*****";

void print_top(){
    cout << top;
}
void print_middle(){
    cout << middle;
}
void print_bottom(){
    cout << bottom;
}

void fractal(int R, int n){
    if(R > N) return;
    
    string btop = "";
    for(int i = 0; i < n/R - 1; i++){
        btop += blank;
    }
    for(int k = 0; k < R/3; k++){
        cout << btop;
        print_top();
    }
    cout << "\n";
    
    
    string bmiddle = "";
    for(int i = 0; i < n/R - 1; i++){
        bmiddle += blank;
    }
    for(int k = 0; k < R/3; k++){
        cout << bmiddle;
        print_middle();
    }
    cout << "\n";
    
    
    string bbottom = " ";
    for(int i = 0; i < n/R - 1; i++){
        bbottom += blank;
    }
    for(int k = 0; k < R/3; k++){
        cout << bbottom;
        print_bottom();
    }
    cout << "\n";
    
    fractal(R*2, n);
}

int main(){
    cin >> N;
    fractal(3, N);
    
    return 0;
}