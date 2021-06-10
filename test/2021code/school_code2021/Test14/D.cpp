#include<iostream>
#include<string>
using namespace std;
int main()
{
    string mainstr;
    string gstr;
    while(cin >> mainstr){
        cin >> gstr;
        int mainlen = mainstr.length();
        int glen = gstr.length();
        int xcount = 0;
        for(int i = 0; i + glen <= mainlen; i += 2){
            string submain = mainstr.substr(i, glen);
            if(submain == gstr){
                xcount++;
            }
        }
        cout << xcount << endl;
    }

    return 0;
}