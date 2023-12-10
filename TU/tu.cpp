#include<iostream>
using namespace std;
typedef struct{
    char vexs[100];
    int arcs[100][100];
    int vexnum,arcnum;
}AMGraph;
int LocateVex(AMGraph &G,char x){
    int i;
    for(i=0;i<G.vexnum;i++)
        if(G.vexs[i]==x) return i;
    return -1;
}
void CreateUDN(AMGraph &G){
    int i,j,k,w;
    char v1,v2;
    cout<<"请输入顶点数和边数：";
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点信息：";
    for(i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    for(i=0;i<G.vexnum;i++)
        for(j=0;j<G.vexnum;j++)
            G.arcs[i][j]=0;
    
    for(k=0;k<G.arcnum;k++){
        cout<<"请输入边的信息：";
        cin>>v1>>v2>>w;
        G.arcs[LocateVex(G,v1)][LocateVex(G,v2)]=w;
        G.arcs[LocateVex(G,v2)][LocateVex(G,v1)]=w;
    }
}
bool visited[100];
void DFS(AMGraph &G,int v){
    int i;
    cout<<G.vexs[v];
    visited[v]=1;
    for(i=0;i<G.vexnum;i++)
        if(G.arcs[v][i]!=0 && !visited[i])
            DFS(G,i);
}
void BFS(AMGraph &G,int v){
    bool visited[100]={0};
    int i,j;
    int que[100],front=0,rear=0;
    cout<<G.vexs[v];
    visited[v]=1;
    que[rear++]=v;
    while(front!=rear){
        i=que[front++];
        for(j=0;j<G.vexnum;j++)
            if(G.arcs[i][j]!=0 && !visited[j]){
                cout<<G.vexs[j];
                visited[j]=1;
                que[rear++]=j;
            }
    }
}







int main(){
    AMGraph G;
    CreateUDN(G);
    cout<<"深度优先遍历结果："<<endl;
    DFS(G,0);
    cout<<"\n广度优先遍历结果："<<endl;
    BFS(G,0);
    



    return 0;
}