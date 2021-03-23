#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

queue<char> A;
queue<char> B;
stack<char> table;
stack<char> temp;

int flag = 1;
char AtoT() {
    char ss = '?';
    if (A.empty() != true) {
        ss = A.front();
        A.pop();
        table.push(ss);
        flag = 0;
    }
    return ss;
}
char BtoT() {
    char ss = '?';
    if (B.empty() != true) {
        ss = B.front();
        B.pop();
        table.push(ss);
        flag = 1;
    }
     return ss;
}
bool tablecheck(char ss) {
    temp = table;
    char c;
    bool check = 0;
    temp.pop();
    while (temp.empty() != true) {
        c = temp.top();
        temp.pop();
        if (c == ss) {
            check = 1;
        }
        else {
            check = check * 1;
        }
    }
    return check;
}
void win(int a) {
    flag = a;
}
/*void letme_seesee_Whatyouhave() {
    char pp[1000] = { 0 };
    temp = table;
    for (int i = 0; table.empty() != true; i++) {
        pp[i] = temp.top();
        temp.pop();
    }
}*/
void change(char ss) {
    char c;
    c = table.top();
    table.pop();
    if (flag == 1) {
        A.push(c);
        while (table.empty() != true) {
            c = table.top();
            table.pop();
            A.push(c);
            if (c == ss) {
                break;
            }
        }
        flag = 1;
    }
    if (flag == 0) {
        B.push(c);
        while (table.empty() != true) {
            c = table.top();
            table.pop();
            B.push(c);
            if (c == ss) {
                break;
            }
        }
        flag = 0;
    }
}
int main()
{

    char str[100] = { 0 };

    while (scanf("%s", str) != EOF) {
        while (A.empty() != true) {
            A.pop();
        }
        while (B.empty() != true) {
            B.pop();
        }
        while (table.empty() != true) {
            table.pop();
        }
        int findit = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            A.push(str[i]);
        }
        scanf("%s", str);
        for (int i = 0; str[i] != '\0'; i++) {
            B.push(str[i]);
        }
        int max = 0;
        int maxn = 10000;
        flag = 1;
        while (A.empty() != true && B.empty() != true) {
            char xx;
            if (flag == 1) {
                xx = AtoT();
                if (tablecheck(xx) && xx != '?') {
                    win(1);
                    change(xx);
                }
            }
            else if (flag == 0) {
                xx = BtoT();
                if (tablecheck(xx) && xx != '?') {
                    win(0);
                    change(xx);
                }
            }
            max++;
            if (max >= maxn) {
                cout << "-1" << endl;
                findit = 0;
                break;
            }
        }
        if (A.empty()) {
            char finalc;
            while (B.empty() != true) {
                finalc = B.front();
                B.pop();
                cout << finalc;
            }
        }
        else if(B.empty()) {
            char finalc;
            while (A.empty() != true) {
                finalc = A.front();
                A.pop();
                cout << finalc;
            }
        }
        cout << endl;
    }

    //K8XKA2A95A       27K5J5Q6K4
    return 0;
}