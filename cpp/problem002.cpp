/*
    Copyright (c) 2015 - buyuk.dev@gmail.com
    ----------------------------------------
    find the sum of even fibbonacci numbers
    below 1 000 000.
*/

#include <iostream>
#include <fstream>
#include <string>


using namespace std;



struct InputData
{
    int n;
};


struct OutputData
{
    int result;
};


InputData load(string filename)
{
    InputData data;

    ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        throw string("file does not exist");
    }

    inputFile >> data.n;

    return data;
}


int evenFibSum(int n)
{
    int a = 0, b = 2;
    int sum = 0;
    while (b <= n)
    {
        int tmp = a;
        a = b;
        b = 4 * b + tmp;
        sum += a;
    }
    return sum;
}


OutputData solve(InputData input)
{
    OutputData data;
    data.result = evenFibSum(input.n);
    return data;
}



void displayData(InputData input, OutputData output)
{
    cout << "Sum of even Fibonacci numbers lower than "
         << input.n << " equals " << output.result << endl;
}


int main(int argc, char* argv[]) 
{
    try
    {
        InputData input = load("data/problem002.dat");
        OutputData output = solve(input);
        displayData(input, output);
    }
    catch (string err)
    {
        cerr << "[ ERROR ] " << err << endl;
    }
    return 0;
}







