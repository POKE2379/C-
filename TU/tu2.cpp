#include<iostream>
using namespace std;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode;
typedef struct VNode{
    char data;
    ArcNode* firstarc;
}VNode,AdjList[100];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
    }ALGraph;
 int LocateVex(ALGraph G,char v){
        int i;
        for(i=0;i<G.vexnum;i++)
            if(G.vertices[i].data==v)
                return i;
        return -1;
    }
void CreateUDG(ALGraph &G){
    int i,j,k,m;
    char v1,v2;
    ArcNode *p;
    cout<<"请输入顶点数和边数：";
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点信息：";
    for(i=0;i<G.vexnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"请输入边的信息：";
    for(k=0;k<G.arcnum;k++){
        cin>>v1>>v2>>m;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        p=new ArcNode;
        p->info=m;
        p->adjvex=j;
        p->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p;
    //有向图

    }
}
bool visited[100];
void DFS(ALGraph &G,int v){
    ArcNode *p;
    cout<<G.vertices[v].data;
    visited[v]=1;
    p=G.vertices[v].firstarc;
    while(p!=NULL){
        if(!visited[p->adjvex])
            DFS(G,p->adjvex);
        p=p->nextarc;
    }
}
void BFS(ALGraph &G,int v){
    int i;
    ArcNode *p;
    int que[100],front=0,rear=0;
    cout<<G.vertices[v].data;
    visited[v]=1;
    que[rear++]=v;
    while(front!=rear){
        i=que[front++];
        p=G.vertices[i].firstarc;
        while(p!=NULL){
            if(!visited[p->adjvex]){
                cout<<G.vertices[p->adjvex].data;
                visited[p->adjvex]=1;
                que[rear++]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
}





int main (){
    ALGraph G;
    CreateUDG(G);
    DFS(G,0);
   // BFS(G,0);


return 0;
}