/**
*设表达式以字符形式已存入数组E[n]中
*"#"为表达式的结束符
*试设计判断表达式中括号"("和")"是否匹配的算法
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
