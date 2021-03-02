#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

struct Node{
    int data;
    Node *nextbrother;
    Node *firstchild;
    Node *father;

    int depth;
    string nodetype;
    int kidnumber;
};

int main()
{
    int n;
    scanf("%d",&n);
    Node *mynode = new Node [n];
    int data = 0;
    int kidnumber = 0;
    int finaldepth = 0;
    Node *root = new Node;
    int i = 0;
    for(int i=0; i<n; i++){
        mynode[i].depth = 0;
        mynode[i].nodetype = "root";
        mynode[i].father = root;
        root->data = -1;
    }
    for(int k=0; k<n; k++){
        scanf("%d",&i);
        mynode[i].data = i;
        scanf("%d",&kidnumber);
        mynode[i].kidnumber = kidnumber;
        int kidname;
        int brothername;
        int lastkid;
        for(int j=0; j<kidnumber; j++){
            if(j==0){
                scanf("%d",&kidname);
                mynode[i].firstchild = &mynode[kidname];
                mynode[kidname].father=&mynode[i];
            }
            else{
                lastkid = kidname;
                scanf("%d",&kidname);
                mynode[lastkid].nextbrother=&mynode[kidname];
                mynode[kidname].father = &mynode[i];
            }
        }
    }

    for(int i=0; i<n; i++){
        Node *kk = new Node;
        kk = &mynode[i];
        while(kk->father->data!=-1){
            mynode[i].depth++;
            kk = kk->father;
        }
    }
    
    for(int i=0; i<n; i++){
        if(mynode[i].kidnumber!=0&&mynode[i].depth>0){
            mynode[i].nodetype="internal node";
        }
        else if(mynode[i].kidnumber==0&&mynode[i].depth!=0){
            mynode[i].nodetype="leaf";
        }
        cout<<"node "<<mynode[i].data<<": parent = "<<mynode[i].father->data<<", depth = "<<mynode[i].depth<<", "<<mynode[i].nodetype<<", ";
        Node *lastone = mynode[i].firstchild;
        if(mynode[i].kidnumber==0){
            cout<<"[]";
        }
        else{
            for(int j=0; j<mynode[i].kidnumber; j++){
                if(j==0){
                    cout<<"["<<mynode[i].firstchild->data;
                    lastone = mynode[i].firstchild;
                }
                else{
                    cout<<", "<<lastone->data;
                }
                lastone = lastone->nextbrother;
            }
            cout<<"]";
        }
        printf("\n");
    }
    return 0;
}