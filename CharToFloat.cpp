float CharToFloat(unsigned char * str)
{
    float float_v = 1.0; //最终值
    //得到int值
    int int_v = 0;
    int_v |= (str[0] << 24);
    int_v |= (str[1] << 16);
    int_v |= (str[2] << 8);
    int_v |= (str[3] << 0);
    //获取二进制表示
    char *binary_v = new char[32];
    for( int i = 31; i>=0; i--)
    {
        if(int_v % 2 == 1)
        {
            binary_v[i] = '1';
        }
        else
        {
            binary_v[i] = '0';
        }
        int_v /= 2;
    }
    //获取尾数
    double m = 1.0; //尾数值
    double bitn = 1.0;  //尾数部分每一位的值
    for(int i = 9; i <= 31; ++i)
    {
        bitn /= 2.0;
        if(binary_v[i] == '1')
        {
            m += bitn;
        }
    }
    //获取指数
    int e = -127;
    int bite = 1;
    for(int i = 8; i >= 1; --i)
    {
        if(binary_v[i] == '1')
        {
            e += bite;
        }
        bite *= 2;
    }
    int value_e = 1;
    while(e--)
    {
        value_e *= 2;
    }
    //得到无符号的float_v，尾数部分*指数部分
    float_v = value_e * m;
    //获取符号位
    if(binary_v[0] == '1')
        float_v *= -1;
    
    delete [] binary_v;
    return float_v;
}
