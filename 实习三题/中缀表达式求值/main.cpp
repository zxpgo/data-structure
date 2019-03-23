#include "calculator.h"
const int SIZE1=20;
const int SIZE2=20;
int main()
{
    Calculator Cal(SIZE1,SIZE2);
    cout<<"请输入一个多项式(以#结尾)："<<endl;
    Cal.InfixToPost();
    Cal.Run();

}
