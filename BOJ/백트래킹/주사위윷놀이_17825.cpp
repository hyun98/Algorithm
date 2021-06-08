#include <bits/stdc++.h>

using namespace std;

vector<int> input;
vector<int> Map[4];

void init(){
    Map[0] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
    Map[1] = {10,13,16,19,25,30,35,40,0};
    Map[2] = {20,22,24,25,30,35,40,0};
    Map[3] = {30,28,27,26,25,30,35,40,0};
    
    int in;
    for(int i = 0; i < 10; i++){
        cin >> in;
        input.push_back(in);
    }
}

int result = 0;

void solve(int dice_index, int a, int an, int b, int bn, int c, int cn, int d, int dn, int sum){
    if(dice_index == 10) return;
    
    result = max(result, sum);
    cout << "now sumn : " << sum << "\n";
    
    // a 이동
    if(input[dice_index] + a < Map[an].size() && a != -1){
        if(an == 0 && input[dice_index] + a == 5){
            if(!(((1 == bn) && (0 == b)) || ((1 == cn) && (0 == c)) || ((1 == dn) && (0 == d)))){
                solve(dice_index+1, 0, 1, b, bn, c, cn, d, dn, sum + 10);
            }
        }
        else if(an == 0 && input[dice_index] + a == 10){
            if(!(((2 == bn) && (0 == b)) || ((2 == cn) && (0 == c)) || ((2 == dn) && (0 == d)))){
                solve(dice_index+1, 0, 2, b, bn, c, cn, d, dn, sum + 20);
            }
        }
        else if(an == 0 && input[dice_index] + a == 15){
            if(!(((3 == bn) && (0 == b)) || ((3 == cn) && (0 == c)) || ((3 == dn) && (0 == d)))){
                solve(dice_index+1, 0, 3, b, bn, c, cn, d, dn, sum + 30);
            }
        }
        else{
            int next_a = a + input[dice_index];
            if(!(((an == bn) && (next_a == b)) || ((an == cn) && (next_a == c)) || ((an == dn) && (next_a == d)))){
                solve(dice_index+1, next_a, an, b, bn, c, cn, d, dn, sum + Map[an][a+input[dice_index]]);
            }
        }
    }
    else if(input[dice_index] + a >= Map[an].size() && a != -1){   // 도착시킬 때
        solve(dice_index+1, -1, an, b, bn, c, cn, d, dn, sum);
    }
    
    // b 이동
    if(input[dice_index] + b < Map[bn].size() && b != -1){
        if(bn == 0 && input[dice_index] + b == 5){
            if(!(((1 == an) && (0 == a)) || ((1 == cn) && (0 == c)) || ((1 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, 0, 1, c, cn, d, dn, sum + 10);
            }
        }
        else if(bn == 0 && input[dice_index] + b == 10){
            if(!(((2 == an) && (0 == a)) || ((2 == cn) && (0 == c)) || ((2 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, 0, 2, c, cn, d, dn, sum + 20);
            }
        }
        else if(bn == 0 && input[dice_index] + b == 15){
            if(!(((3 == an) && (0 == a)) || ((3 == cn) && (0 == c)) || ((3 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, 0, 3, c, cn, d, dn, sum +30);
            }
        }
        else{
            int next_b = b + input[dice_index];
            if(!(((an == bn) && (a == next_b)) || ((bn == cn) && (next_b == c)) || ((bn == dn) && (next_b == d)))){
                solve(dice_index+1, a, an, next_b, bn, c, cn, d, dn, sum + Map[bn][b+input[dice_index]]);
            }
        }
    }
    else if(input[dice_index] + b >= Map[bn].size() && b != -1){   // 도착시킬 때
        solve(dice_index+1, a, an, -1, bn, c, cn, d, dn, sum);
    }
    
    // c 이동
    if(input[dice_index] + c < Map[cn].size() && c != -1){
        if(cn == 0 && input[dice_index] + c == 5){
            if(!(((1 == an) && (0 == a)) || ((1 == bn) && (0 == b)) || ((1 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, b, bn, 0, 1, d, dn, sum + 10);
            }
        }
        else if(cn == 0 && input[dice_index] + c == 10){
            if(!(((2 == an) && (0 == a)) || ((2 == bn) && (0 == b)) || ((2 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, b, bn, 0, 2, d, dn, sum + 20);
            }
        }
        else if(cn == 0 && input[dice_index] + c == 15){
            if(!(((3 == an) && (0 == a)) || ((3 == bn) && (0 == b)) || ((3 == dn) && (0 == d)))){
                solve(dice_index+1, a, an, b, bn, 0, 3, d, dn, sum +30);
            }
        }
        else{
            int next_c = c + input[dice_index];
            if(!(((an == cn) && (a == next_c)) || ((bn == cn) && (next_c == b)) || ((cn == dn) && (next_c == d)))){
                solve(dice_index+1, a, an, b, bn, next_c, cn, d, dn, sum + Map[cn][c+input[dice_index]]);
            }
        }
    }
    else if(input[dice_index] + c >= Map[cn].size() && c != -1){   // 도착시킬 때
        solve(dice_index+1, a, an, b, bn, -1, cn, d, dn, sum);
    }
    
    // d 이동
    if(input[dice_index] + d < Map[dn].size() && d != -1){
        if(dn == 0 && input[dice_index] + d == 5){
            if(!(((1 == an) && (0 == a)) || ((1 == bn) && (0 == b)) || ((1 == cn) && (0 == c)))){
                solve(dice_index+1, a, an, b, bn, c, cn, 0, 1, sum + 10);
            }
        }
        else if(dn == 0 && input[dice_index] + d == 10){
            if(!(((2 == an) && (0 == a)) || ((2 == bn) && (0 == b)) || ((2 == cn) && (0 == c)))){
                solve(dice_index+1, a, an, b, bn, c, cn, 0, 2, sum + 20);
            }
        }
        else if(dn == 0 && input[dice_index] + d == 15){
            if(!(((3 == an) && (0 == a)) || ((3 == bn) && (0 == b)) || ((3 == cn) && (0 == c)))){
                solve(dice_index+1, a, an, b, bn, c, cn, 0, 3, sum +30);
            }
        }
        else{
            int next_d = d + input[dice_index];
            if(!(((an == dn) && (a == next_d)) || ((dn == cn) && (next_d == c)) || ((bn == dn) && (next_d == b)))){
                solve(dice_index+1, a, an, b, bn, c, cn, next_d, dn, sum + Map[dn][d+input[dice_index]]);
            }
        }
    }
    else if(input[dice_index] + d >= Map[dn].size() && d != -1){   // 도착시킬 때
        solve(dice_index+1, a, an, b, bn, c, cn, -1, dn, sum);
    }
}


int main(){
    init();
    solve(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    
    cout << result;
    return 0;
}
