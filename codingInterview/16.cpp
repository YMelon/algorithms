
bool g_InvalidInput = false;

double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base, 0.0) && exponent < 0) {
	g_InvalidInput = true;
	return 0.0;
    }

    unsigned int absExponent = (unsigned int)exponent;
    if(exponent < 0)
	absExponent = (unsigned int)(-exponent);

    double result = PowerWithUsignedExponent(base, absExponent);
    if(exponent < 0)
	result = 1.0 / result;
    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    double result = 1.0;
    for(int i = 1; i <= exponent; ++i)
	result *= base;

    return result;
}


//faster version
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0)
	return 1;
    ir(exponent == 1)
	return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1)  //exponent % 2 == 1
	result *= base;

    return result;
}
