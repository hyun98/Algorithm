#include <iostream>
#include <string>
using namespace std;

class Zip{
public:
    string reverse_img(string::iterator &it){
        char head = *it;
        it++;
        if(head != 'x'){
            string ret;
            ret += head;
            return ret;
        }
        string rimg[4];
        rimg[0] = reverse_img(it);
        rimg[1] = reverse_img(it);
        rimg[2] = reverse_img(it);
        rimg[3] = reverse_img(it);

        return "x" + rimg[2] + rimg[3] + rimg[0] + rimg[1];
    }
};


int main(){
    int test;
    string img;
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> img;
        Zip IMG;
        string::iterator it = img.begin();
        cout << IMG.reverse_img(it) << "\n";
    }
    return 0;
}
//1
//xbwxwbbwb
