#include<iostream>
using namespace std;
struct Book
{
    string name;
    string id;
    double price;


};

typedef struct LNode
{
    Book data;
    struct LNode* next;
}LNode, * LinkList;

bool InitList(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    return 0;
};
bool InsertElem_L(LinkList& L, int i, Book& b) {
    LNode* p = L;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next; ++j;
    }
    if (!p || j > i - 1)
        return 0;
    LNode* s = new LNode;
    s->data = b;
    s->next = p->next;
    p->next = s;
    return 0;
};
bool FindElemById_L(LinkList& L, string id) {
    LNode* p = L->next;
    while (p && p->data.id != id)
    {
        p = p->next;


    }
    if(p)
        cout<<"找到了"<<endl;
    else
        cout<<"没找到"<<endl;
    return 1;
};
bool FindElemByName_L(LinkList& L, string name) {
    LNode* p = L->next;
    while (p && p->data.name != name)
    {
        p = p->next;


    }
    if(p)
        cout<<"找到了"<<endl;
    else
        cout<<"没找到"<<endl;
    return 1;
}
bool DeleteElemByName_L(LinkList& L, string name) {
    LNode* p = L;
    while (p->next && p->next->data.name != name)
    {
        p = p->next;


    }
    if(!p->next)
        cout<<"没有这本书"<<"   "<<name<<"无法删除"<<endl;
    else{
    LNode* q = p->next;
    p->next = q->next;
    delete q;
    cout<<name<<"   "<<"删除成功"<<endl;};
    return 1;
};
bool  DeleteElemById_L(LinkList& L, string id) {
    LNode* p = L;
    while (p->next && p->next->data.id != id)
    {
        p = p->next;

    }
    if(!p->next)
        cout<<"没有这本书"<<"   "<<id<<"无法删除"<<endl;
    else{
        LNode* q = p->next;
    p->next = q->next;
    delete q;
    cout<<id<<"   "<<"删除成功"<<endl;}
    return 0;
};
bool UpdataElemById_L(LinkList& L, string id, double newPrice) {
    LNode* p = L->next;
    while (p && p->data.id != id)
    {
        p = p->next;


    }
    p->data.price = newPrice;


    return 1;
};
int CountElem_L(LinkList& L) {
    LNode* p = L->next; int j = 0;

    while (p)
    {
        ++j;
        p = p->next;
    }
    return j;
};
bool DeleteList(LinkList& L) {
    delete  L;
    return 0;
};

void PrintList_L(LinkList& L) {
    LNode* p = L->next; int j = 0;

    while (p)
    {
        ++j;
        cout << j << "    " << p->data.id << "     " << p->data.name << "    " << p->data.price << endl;
        p = p->next;
    }
    cout<<"总数："<<CountElem_L(L)<<endl;

};
void CreateList_H(LinkList& L, int n) {
    InitList(L);
    LinkList p = NULL;
    for (int i = 0; i < n; ++i) {
        p=new LNode;
        p->data.id = "000";
        p->data.name = "000";
        p->data.price = 0;
        p->next = L->next;
        L->next = p;



    }

};
//写一个链表的节点替换功能
void ReplaceNode(LinkList& L, int i, Book b) {
    LNode* p = L->next;
    int j = 0;
    while (p && (j <i -1)) {
        p = p->next; ++j;
        if (!p || j > i - 1)
            return ;

    }
    p->data = b;
    return ;

}

int main() {
    Book a;
    a.id = "001";
    a.name = "数据结构";
    a.price = 20;
    Book b;
    b.id = "002";
    b.name = "计算机系统";
    b.price = 30;
    Book c;
    c.id = "003";
    c.name = "离散数学";
    c.price = 40;
    Book d;
    d.id = "004";
    d.name = "线性代数";
    d.price = 40;
    LinkList L;
    InitList(L);
    //CreateList_H(L, 2);
    cout<<"插入书籍"<<endl;
    InsertElem_L(L, 1, a);
    InsertElem_L(L, 2, b);
    PrintList_L(L);
    cout<<"更新书籍价格"<<endl;
    UpdataElemById_L(L,"002",40);
    PrintList_L(L);
    //cout<<"总数："<<CountElem_L(L)<<endl;
    cout<<"插入书籍"<<endl;
    InsertElem_L(L, 3, c);
    PrintList_L(L);
    cout<<"替换书籍"<<endl;
    ReplaceNode(L,2,d);
    PrintList_L(L);
    //cout<<"总数："<<CountElem_L(L)<<endl;
    cout<<"查找，删除，更新，书籍"<<endl;

    FindElemById_L(L,"003");
    FindElemByName_L(L,"线性代数");
    DeleteElemByName_L(L,"高等数学");
    DeleteElemByName_L(L,"线性代数");
    PrintList_L(L);
    DeleteElemById_L(L,"001");
    PrintList_L(L);
    DeleteList(L);







    system("pause");
    return 0;
}