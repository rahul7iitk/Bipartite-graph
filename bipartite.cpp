#include <bits/stdc++.h>

using namespace std;

bool color_it(vector<int> table[], queue<int> que, int color[]);

int main() {
    int t; cin>>t;
    
    for(int j=1;j<=t;j++){
        int vert , rel;    
        cin>>vert>>rel;
        
        vector<int> table[vert];
        int a,b;
        
        while(rel-->0){
            cin>>a>>b;
            a--;b--;
            table[a].push_back(b);
            table[b].push_back(a);
        }

        int color[vert];
        for(int i=0;i<vert;i++)
            color[i]=-1;
        
        bool result = true;
        
        for(int i=0;i<vert;i++){
            if(color[i]==-1){
                queue<int> que;
                que.push(i);
                color[i]=0;
                
                if(!color_it(table,que,color)){
                    result = false;
                    break;
                }
            }
        }
        
    if(result)
        cout<<"Scenario #"<<j<<":"<<endl<<"No suspicious bugs found!"<<endl;
    else
        cout<<"Scenario #"<<j<<":"<<endl<<"Suspicious bugs found!"<<endl;

}
return 0;

}

bool color_it(vector<int> table[], queue<int> que, int color[]){
    bool result = true;
    
    while(!que.empty()){
        int top = que.front();
        que.pop();
        
        for(int i=0; i<table[top].size();i++ ){
            int key = table[top].at(i);
            
            if(color[key]==-1){
                color[key] = 1-color[top];
                que.push(key);
            }
            else if(color[key]==color[top]){
                result = false;
                break;
            }
        }
        if(!result)
            break;
        
    }
    return result;
}















































