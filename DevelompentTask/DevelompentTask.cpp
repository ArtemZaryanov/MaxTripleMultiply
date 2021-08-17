// DevelompentTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>
long long TripleMaxMultiplyBrute(std::vector<short> stream)
{
    long long answ_brute = 0;
    long long max_brute = INT64_MIN;
    // O(n^3)
    size_t length = stream.size();
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            for (size_t k = j + 1; k < length; k++)
            {
                answ_brute = (long long)stream[i] * stream[j] * stream[k];
                if (answ_brute > max_brute)
                {
                    max_brute = answ_brute;
                }

            }

        }
    }
    return max_brute;
}
long long TripleMaxMultiply(std::vector<short> stream)
{
    if (stream.size() == 3)
    {
        return (long long)stream[0] * stream[1] * stream[2];
    }
    std::vector<short> p_stream;
    std::vector<short> n_stream;
    // O(n)
    for (short s : stream)
    {
        if (s > 0)
        {
            p_stream.push_back(s);
        }
        else
        {
            n_stream.push_back(s);
        }
    }
    // O(mlog(m) + p*log(p))
    std::sort(p_stream.begin(), p_stream.end(), std::greater<short>());
    std::sort(n_stream.begin(), n_stream.end(), std::less<short>());
    if (p_stream.size() == 0)
    {
        return (long long)n_stream[stream.size() -1] * n_stream[stream.size() - 2] * n_stream[stream.size() - 3];
    }
    long d_n_max = 0;
    if (n_stream.size() >= 2)
    {
        d_n_max = n_stream[0] * n_stream[1];
    }
    long long  answ_1 = 0;
    long long  answ_2 = 0;
    if (d_n_max != 0)
    {
        answ_1 = (long long)p_stream.front() * d_n_max;
    }
    if (p_stream.size() >= 3)
    {
        answ_2 = (long long)p_stream[0] * p_stream[1] * p_stream[2];
    }
    return answ_1 <= answ_2 ? answ_2 : answ_1;
}
//Test
std::vector<short> genRandomStream(size_t size)
{
    std::vector<short> randomStream;
    short b = 0;
    short sign = 1;
    for (int i = 0; i < size; i++) {
        b = sign*rand();
        sign = rand() % 3 - 1;
        randomStream.push_back(b);
    }
    return randomStream;
}
int test(size_t count, size_t maxSize)
{
    int pN = 0;
    long long answ_brute = 0;
    long long answ = 0;
    for (size_t i = 0; i < count; i++)
    {

        std::vector<short> randomStream = genRandomStream(rand()%(maxSize -3) + 3);
        answ = TripleMaxMultiply(randomStream);
        answ_brute = TripleMaxMultiplyBrute(randomStream);
        if (answ != answ_brute)
        {
            pN++;
            for (size_t i = 0; i < randomStream.size(); i++)
            {
                std::cout << randomStream[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "answ_brute =" << answ_brute << " " << "answ=" << answ << std::endl;
        }
    }
    return pN;
}
int main()
{
    std::vector<short> stream{ 2,4,5,6,7 };
    std::cout << TripleMaxMultiply(stream) << std::endl;
    //std::cout << test(2000,1000) << std::endl;
}