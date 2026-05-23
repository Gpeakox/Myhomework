#include<iostream>

using namespace std;

class ListNode
{
public:
    int data;

    ListNode* next;
    
};

class Ablist
{
public:
    ListNode* head;

    Ablist()
    {
        head = nullptr;
    }
    ~Ablist()
    {
        deletelist();
    }
    ListNode* findx(int x);
    ListNode* findnextp(ListNode* p);
    void insert(int x,int y);
    void deletex(int x);
    void deletelist();
    void print();
};

ListNode *Ablist::findx(int x)
{
    ListNode* p = head;
    while(p != nullptr)
    {
        if(p->data == x)
        return p;
        p = p->next;
    }
    return nullptr;
}

ListNode *Ablist::findnextp(ListNode *p)
{
    ListNode* q = head;
    if(q == p)
    {
        return nullptr;
    }
    while (q->next != p)
    {
        q = q->next;
    }
    return q;
}

void Ablist::insert(int x, int y)
{
    ListNode* p = findx(x);
    if(p)
    {
        ListNode* q = findnextp(p);
        if(q)
        {
            ListNode* m = new ListNode;
            q->next = m;
            m->next = p;
            m->data = y;
        }
        else
        {
            ListNode* m = new ListNode;
            m->next = head;
            m->data = y;
        }
    }
    else
    {
        p = head;
        if(p)
        {    
            while(p->next != nullptr)
            {
                p = p->next;
            }
            ListNode* q = new ListNode;
            q->next = p->next;
            p->next = q;
            q->data = y;
        }
        else
        {
            head = new ListNode;
            head->data = y;
            head->next = nullptr;
        }
    }
}

void Ablist::deletex(int x)
{
    ListNode*p = findx(x);
    if(p)
    {
        ListNode *q = findnextp(p);
        if(q)
        {
            q->next = p->next;
            delete p;
        }
        else
        {
            q = head->next;
            delete head;
            head = q;
        }
    }
}

void Ablist::print()
{
    ListNode *p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    if(p == head)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << endl;
    }
    
}

void Ablist::deletelist()
{
    ListNode* p = head;
    if(head != nullptr)
    {
        while(head->next != nullptr)
        {
            while(p->next->next != nullptr)
            {
                p = p->next;
            }
            ListNode* q = p->next;
            delete q;
            p->next = nullptr;
            p = head;
        }
        delete p;
        head = nullptr;
    }
}

int main()
{
    Ablist a;
    int time , b , c;
    string l;
    cin >> time;
    for(int i = 0; i < time ; i++)
    {
        cin >>l;
        if(l == "delete")
        {
            cin >> b;
            a.deletex(b);
        }
        else if(l == "insert")
        {
            cin >> b >> c;
            a.insert(b,c);
        }
        else
        {
            cout << l << endl;
        }
    }
    a.print();
    return 0;
}