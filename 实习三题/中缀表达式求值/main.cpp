#include "calculator.h"
const int SIZE1=20;
const int SIZE2=20;
int main()
{
    Calculator Cal(SIZE1,SIZE2);
    cout<<"������һ������ʽ(��#��β)��"<<endl;
    Cal.InfixToPost();
    Cal.Run();

}
