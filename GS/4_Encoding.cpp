string encode(string src)
{
    // Your code here i
    int c = 1;
    string res = "";
    int i;
    for (i = 1; i < src.length(); i++)
    {
        if (src[i] == src[i - 1])
        {
            c++;
            continue;
        }
        res += src[i - 1];
        res += to_string(c);
        c = 1;
    }
    res += src[i - 1];
    res += to_string(c);
    return res;
}