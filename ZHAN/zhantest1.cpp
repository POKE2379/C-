#include<iostream>
using namespace std;
typedef struct
{
    int* basic;
    int* top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S)
{
    S.basic = new int[100];
    if(!S.basic) exit(1);
    S.top = S.basic;
    S.stacksize = 100;
}
void Push(SqStack &S, int e)
{
    if(S.top - S.basic == S.stacksize) exit(1);
    *S.top++ = e;
        cout<<"入栈成功"<<endl;
}
void Pop(SqStack &S)
{
    if(S.top == S.basic) exit(1);

        cout<<"已出栈"<<endl;
        --S.top;
    
}
int GetTop(SqStack S)
{
    if(S.top != S.basic)
    return *(S.top - 1);
}
bool StackTraverse(SqStack S)
{
    if(S.top == S.basic) return false;
    int* p = S.basic;
    while(p != S.top)
    {
        cout<<*p<<endl;
        p++;
    }
    return true;
}
int StackLength(SqStack S)
{
    return S.top - S.basic;
}
bool StackState(SqStack S)
{
    if(S.top == S.basic) 
    cout<<"栈空"<<endl;
    else if(S.top-S.basic == S.stacksize)
    cout<<"栈满"<<endl;
    else if(S.top-S.basic < S.stacksize)
    cout<<"栈未满"<<endl;
    return 1;
}
bool DestoryStack(SqStack &S)
{
   delete[] S.basic;
   S.basic=NULL;
    S.top=NULL;
    S.stacksize=0;
    cout<<"栈已销毁"<<endl;
}
int main()
{
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    Push(S, 6);
    StackTraverse(S);
    StackState(S);
    cout<<"栈目前长度为"<<StackLength(S)<<endl;
   
    Pop(S);
    StackTraverse(S);
    StackState(S);
    cout<<"栈目前长度为"<<StackLength(S)<<endl;
    DestoryStack(S);
    StackState(S);
    cout<<"栈目前长度为"<<StackLength(S)<<endl;
    system("pause");
    return 0;
}