#include<stdio.h>

int a[20];
int size = 0;

void swap(int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sink(int i)
{
    if(i >= size)
    {
        return;
    }
    int max = i;
    int L = i*2;
    int R = i*2+1;
    if(L < size && a[L] > a[max])
    {
        max = L;
    }
    if(R < size && a[R] > a[max])
    {
        max = R;
    }
    if(i != max)
    {
        swap(i, max);
        sink(max);
    }
}

void swim(int i)
{
    if(i == 0)
    {
        return;
    }
    int p = i/2;
    if(a[p] < a[i])
    {
        swap(p,i);
        swim(p);
    }
}

void insert(int k)
{
    a[size++] = k;
    swim(size-1);
}

int get_max()
{
    return a[0];
}

int del_max()
{
    int k = get_max();
    swap(0, size-1);
    size--;
    sink(0);
    return k;
}

int main()
{
    insert(9);
    insert(3);
    insert(8);
    insert(1);
    insert(2);
    insert(7);
    insert(5); 
    insert(-1);
    insert(0);
    printf("%d\n", get_max());
    printf("%d\n", del_max());
    printf("%d", get_max());
}
