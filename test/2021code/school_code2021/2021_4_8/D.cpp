#include<iostream>
#include<queue>
using namespace std;
class Customer{
public:
    int arrtime;
    int usetime;
    Customer(int a, int u){
        arrtime = a;
        usetime = u;
    }
};
int maxwait = 0;
double totalwait = 0;
void getmax(int t)
{
    if(t > maxwait){
        maxwait = t;
    }
}
int main()
{
    queue<Customer> Q;
    int N;
    cin>>N;
    for(int i = 0; i < N; i ++){
        int a, u;
        cin>>a>>u;
        Customer c(a, u);
        Q.push(c);
    }
    double K;
    cin>>K;
    queue<Customer> Q1[10];
    double timeofnow = 0;
    while(1){
        int flag = 0;
        for(int i = 0; i < K; i ++){
            if(Q1[i].empty() && !Q.empty()){
                if(Q.front().arrtime <= timeofnow){
                    Q1[i].push(Q.front());
                    int wait = timeofnow - Q.front().arrtime;
                    totalwait += wait;
                    getmax(wait);
                    Q.pop();
                }
            }
        }
        for(int i = 0; i < K; i ++){
            if(!Q1[i].empty()){
                if(timeofnow >= Q1[i].front().arrtime){
                    Q1[i].front().usetime --;
                }
                if(Q1[i].front().usetime <= 0){
                    Q1[i].pop();
                }
            }
        }
        timeofnow++;
        for(int i = 0; i < K; i ++){
            if(Q1[i].empty()){
                flag++;
            }
        }
        if(flag == K && Q.empty()){
            break;
        }
    }
    printf("%.1f %d %.0f", totalwait / N, maxwait, timeofnow);
    return 0;
}