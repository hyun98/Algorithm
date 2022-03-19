#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string &input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) result.push_back(temp);
 
    return result;
}

int main(){
    string str = "Hello beautiful world in the universe ! ! ";
    vector <string> result = split(str, ' ');
    for(auto &r : result) cout << r << ' ';
}