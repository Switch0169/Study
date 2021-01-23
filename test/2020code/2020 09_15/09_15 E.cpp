#include <iostream>
using namespace std;
int main ()
{
    int t,i,j;
    cin>>t;
    char *p = (char *)malloc(sizeof(char)*100);
    char *q = (char *)malloc(sizeof(char)*100);
    char *s = (char *)malloc(sizeof(char)*100);
    while(t--)
    {
        cin>>p>>q;
        i=0;
        j=0;
        while(1){
            if(*(p+i)==0){
                break;
            }
            for(j=0;;j++){
                if(*(q+j)==0){
                    break;
                }
                if(*(p+i+j)==0){
                    break;
                }
                if(*(p+i+j)+*(q+j)-'0'>'Z'&&*(p+i+j)+*(q+j)-'0'<'a'){
                    *(s+i+j)=*(p+i+j)+*(q+j)-'0'-'Z'+'A'-1;
                }
                else if(*(p+i+j)+*(q+j)-'0'>'z'){
                    *(s+i+j)=*(p+i+j)+*(q+j)-'0'-'z'+'a'-1;
                }
                else{
                    *(s+i+j)=*(p+i+j)+*(q+j)-'0';
                }
                cout<<*(s+i+j);    
            }
            i=i+j;
        }
        cout<<endl;
    }
}   