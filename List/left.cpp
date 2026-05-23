#include<iostream>

using namespace std;

class ver 
{
private:
    int n;
    int zu[100];
public:
    ver(int n1)
    {
        n = n1;
    }
    void print(int m)
    {
        for(int i = 0;i < m-1;i++)
        {
            cout << zu[i] << " ";
        }
        cout << zu[n - 1] << endl;
    }
    void LeftMove(int m,int k)
    {
        int t[100];
        for(int i = 0;i < k;i++)
        {
            t[i] = zu[i];
        }
        for(int i = 0;i < n - k;i++)
        {
            zu[i] = zu[i + k];
        }
        for(int i = 0;i < k;i++)
        {
            zu[n - k + i] = t[i];
        }
    }
    void insert(int m) 
    {
        for(int i = 0; i < m ;i++)
        {
            cin >> zu[i];
        }
    }

};

int main()  
{  
    int n, k;  
    cin >> n;  
    cin >> k;  
    ver a(n);  
    a.insert(n);  
    a.LeftMove(n, k);  
    a.print(n);  
    return 0;  
}  


/*
实现数组的循环左移，要求：构造ver 类，用于存储长度为 n 的整型数组，其中，print() 函数，用于输出数组中的元素； LeftMove() 函数，用于实现数组的循环左移操作。

输入格式:

第一行输入两个整数 n(1<n<100)和k(0≤k≤n)，分别表示顺序表的元素个数和循环左移的位移量。

第二行一共 n 个整数，表示顺序表中元素的值。

输出格式：

输出只有一行，输出 n 个整数，顺序输出循环左移后顺序表中每个元素的值，每个元素之间用一个空格分隔。行末不要有多余空格。

样例输入

8 3

1 2 3 4 5 6 7 8

样例输出

4 5 6 7 8 1 2 3
*/