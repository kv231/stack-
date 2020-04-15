#include<bits/stdc++.h>
using namespace std;
class Kstacks {
    int *arr;
    int *next;
    int *top;
    int size;
    int k;
    int free;
    public:
    Kstacks(int k,int size) {
        this->k=k;
        this->size=size;
        arr=new int[size];
        next=new int[size];
        top=new int[k];
        free=0;
        for(int i=0;i<size;i++) {
            next[i]=i+1;
        }
        next[size-1]=-1;
        for(int i=0;i<k;i++) {
            top[i]=-1;
        }
    }
    void push(int element,int n) {
        if(free==-1) {
            cout<<"overflow";
            for(int i=0;i<size;i++)
                cout<<next[i]<<" ";
            return ;
        }
        int i=free;
        free=next[free];
        next[i]=top[n];
        top[n]=i;
        arr[i]=element;
    }
    int pop(int n) {
        if(top[n]==-1) {
            cout<<"underflow";
            return -1;
        }
        int ans=arr[top[n]];
        int i=top[n];
        top[n]=next[top[n]];
        next[top[n]]=free;
        free=i;
        return ans;
    }
    void print() {
        for(int i=0;i<k;i++) {
            if(top[i]==-1) {
                cout<<i<<": stack is empty";
            }
            else {
                cout<<i<<": ";
                int j=top[i];
                while(j!=-1) {
                cout<<arr[j]<<",";
                j=next[j];
                }
            }
            cout<<"\n";
        }
    }

};
int main() {
    int n,k,val;
    cin>>n>>k;
    Kstacks s(k,n);
    int c=1;
    while(c) {
        cout<<"enter your choice\n";
        cin>>c;
        switch(c) {
            case 1:
            cin>>val>>n;
            s.push(val,n);
            break;
            case 2:
            cin>>n;
            cout<<s.pop(n);
            break;
            case 3:
            s.print();
            break;
            default:
            exit(0);
        }
    }
}
