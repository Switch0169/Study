#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main()
{
    stack<int> s;
    stack<pair<int,int> > s1;
    char m;
    int count = 0;
    int ans = 0;
    int tempcount = 0;
    while(cin>>m){
        int temp = 0;
        if(m=='\\'){
            s.push(count);
        }
        else if(m=='/'){
            if(s.empty()!=true){
                temp = s.top();
                s.pop();
                int a = count - temp;
                ans += count - temp;
                while(s1.empty()!=true&&s1.top().first>temp){
                    a += s1.top().second;
                    s1.pop();
                }
                s1.push(make_pair(temp,a));
            }
        }
        count++;
    }
    printf("%d\n",ans);
    tempcount=s1.size();
    printf("%d",tempcount);
    int area[20000]={0};
    for(int i=tempcount-1; i>=0; i--){
        area[i]=s1.top().second;
        s1.pop();
    }
    for(int i=0; i<tempcount; i++){
        printf(" %d",area[i]);
    }
    printf("\n");
    return 0;
}