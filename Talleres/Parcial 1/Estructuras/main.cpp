#include <iostream>

using namespace std;
struct pack3{
    int a;
};
struct pack2{
    int b;
    pack3 *next;
};
struct pack1{
    int c;
    pack2 *next;
};
int main()
{
    pack1 data1, *data_ptr;
    pack2 data2;
    pack3 data3;

    data1.c = 30;
    data2.b = 20;
    data3.a = 10;

    data_ptr = &data1;
    data1.next = &data2;
    data2.next = &data3;

    cout<<"\ndata_ptr->c "<<data_ptr->c<<endl;
    cout<<"\ndata1.next->b "<<data1.next->b<<endl;
    cout<<"\ndata_ptr->next->b "<<data_ptr->next->b<<endl;
    cout<<"\n(*(data_ptr->next)).b "<<(*(data_ptr->next)).b<<endl;
    cout<<"\ndata1.next->next->a "<<data1.next->next->a<<endl;
    cout<<"\ndata_ptr->next->next->a "<<data_ptr->next->next->a  <<endl;

    return 0;
}
