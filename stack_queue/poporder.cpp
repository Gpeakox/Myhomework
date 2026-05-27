#include<iostream>
#include<string>

using namespace std;

class ListNode
{
public:
    char data;
    ListNode* next;
};

class Abstack
{
public:
    ListNode* bottom;
    ListNode* top;
    int height;
    int size;

    Abstack();
    Abstack(int high);
    ~Abstack();
    bool push(char m);
    ListNode* pop();
    void clear();
    bool isEmpty();
};

Abstack::Abstack()
{
    bottom = nullptr;
    top = nullptr;
    height = 0;
    size = 10;
}

Abstack::Abstack(int high)
{
    bottom = nullptr;
    top = nullptr;
    height = 0;
    size = high;
}

Abstack::~Abstack()
{
    clear();
}

bool Abstack::push(char m)
{
    if(height == size)
    return false;
    else
    {
        ListNode* p = new ListNode;
        p->data = m;
        p->next = nullptr;
        if(height == 0)
        {
            top = p;
            bottom = p;
            height++;
        }
        else 
        {
            top->next = p;
            top = p;
            height++;
        }
        return true;
    }
}

ListNode* Abstack::pop()
{
    if(!height)
        return nullptr;
    else
    {
        if(height == 1)
        {
            ListNode* p = top;
            top = nullptr;
            bottom = nullptr;
            height--;
            return p;
        }
        else
        {
            ListNode* p = top;
            ListNode* q = bottom;
            while (q->next != top)
            {
                q = q->next;
            }
            top = q;
            q->next = nullptr;
            height--;
            return p;
        } 
    }
}

void Abstack::clear()
{
    ListNode* p = pop();
    while (p)
    {
        delete p;
        p = pop();
    }
}

bool Abstack::isEmpty()
{
    if(!height)
        return true;
    else
        return false;
}

int main()
{
    
    return 0;
}