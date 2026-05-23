#include<iostream>
#include<string>
using namespace std;

class a
{
    public:
    int b;
    a* next;
};

int main()
{
    a* a1 = new a;
    a* c = new a;
    a1->next = c;
    delete c;
    if(a1->next != nullptr)
    {
        cout <<"1";
    }
}