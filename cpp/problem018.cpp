/*
    Copyright (c) 2016 - buyuk.dev@gmail.com
    ----------------------------------------
    find maximum sum in top-to-bottom paths 
    in number triangle.
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;



int main(int argc, char* argv[]) 
{
   int triSize = 0;
   cin >> triSize;

   vector<vector<int> > tri(triSize);
   int cell = -1;
   
   for (int rowId = 0; rowId < triSize; ++rowId)
   {
      for (int cellId = 0; cellId <= rowId; ++cellId)
      {
         cin >> cell;
         tri[rowId].push_back(cell);
      }
   }
 
   for (int rowId = 0; rowId < triSize - 1; ++rowId)
   {
      vector<int> temp = tri[rowId + 1];
      for (int cellId = 0; cellId < tri[rowId].size(); ++cellId)
      {
         tri[rowId + 1][cellId] = max(tri[rowId + 1][cellId], temp[cellId] + tri[rowId][cellId]);
         tri[rowId + 1][cellId + 1] = max(tri[rowId + 1][cellId + 1], temp[cellId + 1] + tri[rowId][cellId]);
      }
   }

   cout << "Max sum is " << *max_element(tri.back().begin(), tri.back().end()) << endl;
   
   return 0;
}







