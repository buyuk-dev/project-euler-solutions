/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    names scores from file
*/

#include <locale>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


string strip(const string& str)
{
    if (str.size() > 2)
    {
        return str.substr(1, str.size() - 2);
    }

    return "";
}


string loadNext(ifstream& file)
{
    char namebuf[128];
    
    if (file)
    {
        file.getline(namebuf, 128, ',');
    }
    
    return strip(namebuf);
}


vector<string> load(const string& filename)
{
    ifstream file(filename.c_str());
    vector<string> names;
    
    while (file)
    {
        string name = loadNext(file);
        if (name.size() > 0)
        {
            names.push_back(name);
        }
    }
    
    return names;
}


int alphaval(const string& name)
{
    int counter = 0;
    for (int i=0; i<name.size(); ++i)
    {
        counter += name[i] - 'A' + 1;
    }
    return counter;
}


int score(const string& name, int pos)
{
    return alphaval(name) * pos;
}


int main()
{
    const string filename = "data/problem022.dat";
    vector<string> names = load(filename);
    
    sort(names.begin(), names.end());
    
    int total = 0;
    for (int id = 0; id <= names.size(); ++id)
    {
        total += score(names[id], id + 1);
    }

    printf("Total score of all names is %d\n", total);
    return 0;
}
