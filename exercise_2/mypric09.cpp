/**
*����ʽ���ַ���ʽ�Ѵ�������E[n]��
*"#"Ϊ���ʽ�Ľ�����
*������жϱ��ʽ������"("��")"�Ƿ�ƥ����㷨
*/
static bool panduan(char* E)
{
    int i = 0;
    int count01 = 0;
    int count02 = 0;
    char c;
    while((c=E[i++]) != '#')
    {
        if(count01 < count02)
            return false;
        if(c == '(')
            count01++;
        else if(c == ')')
            count02++;
    }
    if(count01 == count02)
        return true;
    return false;
}
