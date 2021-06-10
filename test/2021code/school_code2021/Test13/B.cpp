#include<iostream>
#include<list>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        list<int> x;
        list<int> Table[12][12];
        for(int i = 0; i < n; i++){
            int data;
            cin >> data;
            int hash = data % 11;
            Table[hash]->insert(Table[hash]->begin(), data);
        }
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            int data;
            cin >> data;
            int hash = data % 11;
            bool flag = 0;
            int count = 0;
            for(auto it = Table[hash]->begin(); it != Table[hash]->end(); it++){
                count++;
                if(data == *it){
                    flag = 1;
                    break;
                }
            }
            if(flag) cout << hash << " " << count <<endl;
            else{
                Table[hash]->insert(Table[hash]->end(), data);
                cout << "error" << endl;
            }
        }
    }
    return 0;
}