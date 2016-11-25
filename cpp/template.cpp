/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------

*/

#include <iostream>
#include <string>


using namespace std;



struct InputData
{

};


struct OutputData
{

};


InputData load(string filename)
{
    InputData data;
    
    return data;
}


OutputData solve(InputData input)
{
    OutputData output;
    
    return output;
}


int main(int argc, char* argv[]) 
{
    try
    {
        InputData input = load(filename);
        OutputData output = solve(input);

        printResults(input, output);
    }
    catch (string err)
    {
        cerr << "[ ERROR ] "<< err << endl;    
    }

    return 0;
}




