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

string d2b(int di)
{
    string m = "";
    if(di < 0)
    {
        return m;
    }
    if(!di)
    {
        m.append("0");
        return m;
    }
    while (di > 0)
    {
        if(di%2)
        {
            m = "1" + m;
        }
        else
        {
            m = "0" + m;
        }
        di /= 2;
    }
    return m;
}

string nts(int i)
{
    string m;
    if(i<10)
    {
        m = to_string(i);
    }
    else
    {
        switch (i)
        {
        case 10:
            m = "A";
            break;
        case 11:
            m = "B";
            break;
        case 12:
            m = "C";
            break;
        case 13:
            m = "D";
            break;
        case 14:
            m = "E";
            break;
        case 15:
            m = "F";
            break;  
        default:
            break;
        }
    }
    return m;
}

int cifang(int i,int j)
{
    int p = 1;
    if(!j)
    {
        return 1;
    }
    for(; j>0;j--)
    {
        p *= i; 
    }
    return p;
}
string bto(string bstr)
{
    Abstack stack(4);
    string ostr;
    bool test = true;
    int length = bstr.length();
    int nowpos =  length - 1;
    while (test)
    {
        for(int i = 0; i<4 && nowpos >= 0 ;i++)
        {
            stack.push(bstr[nowpos--]);
            if(nowpos < 0)
                test = false;
        }

        if(stack.height == 4)
        {    
            ListNode* p = stack.pop();
            int i = 0;
            int beilv = 8;
            while (p)
            {
                if(p->data == '0')
                {
                    beilv  /= 2;
                }
                else
                {
                    i += beilv;
                    beilv /= 2;
                }
                delete p;
                p = stack.pop();
            }
            ostr = nts(i) + ostr; 
        }
        else
        {
            ListNode* p = stack.pop();
            int i = 0;
            int beilv = cifang(2,stack.height);
            while (p)
            {
                if(p->data == '0')
                {
                    beilv  /= 2;
                }
                else
                {
                    i += beilv;
                    beilv /= 2;
                }
                p = stack.pop();
            }
            ostr = nts(i) + ostr; 
        }

    }
    return ostr;
}
int main()
{
    int a;
    cin >> a;
    string bstr = d2b(a);
    string ostr = bto(bstr);
    cout << ostr << endl;
    return 0;
}