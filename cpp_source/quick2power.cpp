
long pow_2(int b)
{
    long x = 2;
    long result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result *= x;
        }
        b >>= 1;
        x = x * x;
    }
    return result;
}