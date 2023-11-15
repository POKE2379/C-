#include<iostream>
using namespace std;
typedef struct BiNode{
    int data;
    BiNode *lchild,*rchild;
    }BiNode,*BiTree;

    void CreateBitree1(BiTree &T){
        int ch;
        cin>>ch;
        if(ch==-1) T=NULL;
        else{
            T=new BiNode;
            T->data=ch;
            CreateBitree1(T->lchild);
            CreateBitree1(T->rchild);
        }
    }//先序创建二叉树
    void CreateBitree2(BiTree &T){
        int ch;
        cin>>ch;
        if(ch==-1) T=NULL;
        else{
            T=new BiNode;
            CreateBitree2(T->lchild);
             T->data=ch;
            CreateBitree2(T->rchild);
        }
    }//中序创建二叉树
    void CreateBitree3(BiTree &T){
        int ch;
        cin>>ch;
        if(ch==-1) T=NULL;
        else{
            T=new BiNode;
            CreateBitree3(T->lchild);
            CreateBitree3(T->rchild);
            T->data=ch;
        }
    }//后序创建二叉树

    void PreOrderTraveRse1(BiTree &T){
        if(T){
            cout<<T->data;
            PreOrderTraveRse1(T->lchild);
            PreOrderTraveRse1(T->rchild);
        }
    }//先序遍历二叉树
    void PreOrderTraveRse2(BiTree &T){
        if(T){
            PreOrderTraveRse2(T->lchild);
            cout<<T->data;
            PreOrderTraveRse2(T->rchild);
        }
    }//中序遍历二叉树
    void PreOrderTraveRse3(BiTree &T){
        if(T){
            PreOrderTraveRse3(T->lchild);
            PreOrderTraveRse3(T->rchild);
            cout<<T->data;
        }
    }//后序遍历二叉树
    int NodeCount(BiTree &T){
        if(T==NULL) return 0;
        else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
    }//求二叉树的结点个数
    int LeafCount(BiTree &T){
        if(T==NULL) return 0;
        else if(T->lchild==NULL&&T->rchild==NULL) return 1;
        else return LeafCount(T->lchild)+LeafCount(T->rchild);
    }//求二叉树的叶子结点个数
    int Depth(BiTree &T){
        if(T==NULL) return 0;
        else{
            int m=Depth(T->lchild);
            int n=Depth(T->rchild);
            if(m>n)
                return (m+1);
            else return (n+1);
        }
    }//求二叉树的深度
    void Destroy(BiTree &T){
        if(T){
            Destroy(T->lchild);
            Destroy(T->rchild);
            delete T;
        }
    }//销毁二叉树
    
    
int main(){
    BiTree T;
    CreateBitree1(T);
    PreOrderTraveRse1(T);
    cout<<endl;
    cout<<"节点数:"<<NodeCount(T)<<endl;
    cout<<"叶子节点数:"<<LeafCount(T)<<endl;
    cout<<"深度:"<<Depth(T)<<endl;
    Destroy(T);
    return 0;
}