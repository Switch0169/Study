#include<iostream>
#include<string>
using namespace std;
bool equals(string str, int count, int index){
    char front[1001] = {0};
    char back[1001] = {0};
    for(int i = 0; i < count; i++){
        front[i] = str[i];
    }
    for(int i = 0; i < count; i++){
        back[i] = str[index + 1 - count + i];
    }
    int flag = 1;
    for(int i = 0; i < count; i++){
        if(front[i] != back[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}
int get_PMT(string str, int index){
    int value = 0;
    for(int i = 1; i <= index; i++){
        if(equals(str, i, index)){
            value = i;
        }
    }
    return value;
}

class myString
{
private:
    string mainstr;
    int size;

    void GetNext(string p, int next[]){
        int len = p.size();
        next[0] = -1;
        int PMT[1001] = {0};
        for(int i = 0; i < len; i++){
            PMT[i] = get_PMT(p, i);
        }
        for(int i = 1; i < len; i++){
            next[i] = PMT[i-1];
        }
    }
    int KMPFind(string p, int pos, int next[]){
        int len = p.size();
        int i = pos;
        int j = 0;
        while(i < size && j < len){
            if(j == -1 || mainstr[i] == p[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        if(j == len){
            return i-j;
        }
        else{
            return -1;
        }
    }
public:
    myString(){
        size = 0;
        mainstr = "";
    }
    ~myString(){
        size = 0;
        mainstr = "";
    }
    void SetVal(string sp){
        mainstr = "";
        mainstr.assign(sp);
        size = mainstr.length();
    }
    int KMPFindSubstr(string p, int pos){
        int i;
        int L = p.length();
        int *next = new int [L];
        GetNext(p, next);
        // for(int i = 0; i < L; i++){
        //     cout << next[i] << ' ';
        // }
        // cout << endl;
        int v = -1;
        v = KMPFind(p, pos, next);
        delete []next;
        return v;
    }
    void change(string x, int index, int changelen){
        for(int i = 0; i < index; i++){
            cout << mainstr[i];
        }
        cout << x;
        for(int i = index + changelen; i < size; i++){
            cout << mainstr[i];
        }
        cout<<endl;
    }
    void print(){
        cout<<mainstr<<endl;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while(t --){
        string mainstr;
        cin >> mainstr;
        string p;
        cin >> p;
        myString m;
        int changelen = p.size();
        string x;
        cin >> x;
        m.SetVal(mainstr);
        int index = m.KMPFindSubstr(p, 0);
        m.print();
        if(index != -1){
            m.change(x, index, changelen);
        }
        else{
            m.print();
        }
    }
    return 0;
}