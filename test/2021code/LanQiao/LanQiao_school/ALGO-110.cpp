#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

int p1,p2,p3;
char ss[101];
vector<char> str1;
vector<char> str2;


int main()
{
    
    cin>>p1>>p2>>p3;
    scanf(" %s",ss);
    for(int i=0; i<100; i++){
        str1.push_back(ss[i]);
    }
    for(int i=0; i<str1.size(); i++){
        if(str1[i]=='-'&&i!=0&&i<str1.size()-1){
            if((str1[i-1]<str1[i+1]) && (((str1[i+1]>='a')&&(str1[i-1]>='a')&&str1[i-1]<='z'&&str1[i+1]<='z') ||((str1[i-1]<='9')&&(str1[i+1]<='9')&&str1[i-1]>='0'&&str1[i+1]>='0'))){
                if(p1==1){
                    if(p3==1){
                        for(int j=1; j<(str1[i+1]-str1[i-1]); j++){
                            for(int k=0; k<p2; k++)
                                str2.push_back(str1[i-1]+j);
                        }
                    }
                    else if(p3==2){
                        for(int j=(str1[i+1]-str1[i-1])-1; j>=1; j--){
                            for(int k=0; k<p2; k++)
                                str2.push_back(str1[i-1]+j);
                        }
                    }
                }
                else if(p1==2){
                    if(str1[i-1]<='9'){
                        if(p3==1){
                            for(int j=1; j<(str1[i+1]-str1[i-1]); j++){
                                for(int k=0; k<p2; k++)
                                    str2.push_back(str1[i-1]+j);
                            }
                        }
                        else if(p3==2){
                            for(int j=(str1[i+1]-str1[i-1])-1; j>=1; j--){
                                for(int k=0; k<p2; k++)
                                    str2.push_back(str1[i-1]+j);
                            }
                        }
                    }
                    else{
                        if(p3==1){
                            for(int j=1; j<(str1[i+1]-str1[i-1]); j++){
                                for(int k=0; k<p2; k++)
                                    str2.push_back(str1[i-1]+j-'a'+'A');
                            }
                        }
                        else if(p3==2){
                            for(int j=(str1[i+1]-str1[i-1])-1; j>=1; j--){
                                for(int k=0; k<p2; k++)
                                    str2.push_back(str1[i-1]+j-'a'+'A');
                            }
                        }
                    }
                }
                else if(p1==3){
                    for(int j=1; j<(str1[i+1]-str1[i-1]); j++){
                        for(int k=0; k<p2; k++)
                            str2.push_back('*');
                    }
                }
            }    
            else{
                str2.push_back(str1[i]);
            }
        }
        else{
            str2.push_back(str1[i]);
        }
    }
    for(int i=0; i<str2.size(); i++){
        cout<<str2[i];
    }
    return 0;
}