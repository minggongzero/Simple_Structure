#include "../List/arrList/arrList.h"
#include "../List/arrList/arrList.cpp"
//��ȥ���ͬǰ׺
template <class T>
void interception(arrList<T>& A, arrList<T>& B, T& a_value, T& b_value)
{
    int i;
    int intercount = A.length()>B.length() ? B.length() : A.length();
    for(i=0 ;i<intercount; i++)
    if(A.getValue(0, a_value) && B.getValue(0, b_value))
    {
        if(a_value == b_value)
        {
            A.my_delete(0);
            B.my_delete(0);
        }
        else
            break;
    }
}

//�Ƚ��㷨
template <class T>
const char* Compare(arrList<T> A, arrList<T> B)
{
    T a_value, b_value; //��Ԫ��
    interception(A, B, a_value, b_value);  //��ȡ�ӱ������Ԫ��
    if(!A.isEmpty() && !B.isEmpty())
        return "=";
    else if((!A.isEmpty() && B.isEmpty()) || (A.isEmpty() && B.isEmpty() && a_value<b_value))
        return "<";
    else
        return ">";
}
