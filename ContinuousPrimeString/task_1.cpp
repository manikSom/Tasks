#include <string>
#include <iostream>
#include <sstream>

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

std::string prime_consecutive(int n, int index) {
    std::stringstream ss;
    int i = 0;
    int x = 2;
    int count = 0;
    while (true)
    {
        if (isPrime(x) == true)
        {
            if (i >= index)
            {
                count++;
                if (count <= n)
                {
                    ss << x;
                }
                else {
                    break;
                }
            }
            i = i + log10(x) + 1;
        }
        x++;
    }

    return ss.str().substr(0, n);
}

int main()
{
    std::cout << prime_consecutive(3, 10);
    return 0;
}