#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void GetRandom(vector<int> &Data,int n);
void Output(vector<int> Data);
inline void ChangeValue(vector<int> &Data,int i,int j);
inline void QuickSort(vector<int> &Data,int left,int right);
inline void Progress();
vector<string> sTarget;

int main()
{
  srand(1000);
  vector<int> Data;
  stringstream s;

  GetRandom(Data,100000);

  //s << "(" << 0 << "," << Data.size()-1 << ")";
  //sTarget.push_back(s.str());
  QuickSort(Data,0,Data.size()-1);

  Output(Data);

  return(0);
}

void GetRandom(vector<int> &Data,int n)
{
  for(int i=0;i<n;i++)
  {
    Data.push_back(rand()%1000);
  }
}

void Output(vector<int> Data)
{
  for(int i=0;i<Data.size();i++)
  {
        cout << Data.at(i) << ",";
  }
  cout << endl;
}

void QuickSort(vector<int> &Data,int left,int right)
{
  //Progress();
  //sTarget.erase(sTarget.begin()+0);

  if( right <= left || left==right)
    return;

  if( (right-left)==1 )
  {
    if( Data.at(left) > Data.at(right) )
    {
        ChangeValue(Data,left,right);
    }

    return;
  }

  int iPivot=Data.at(left);
  int iTemp;
  int iLeft=left+1,iRight=right;
  stringstream s1,s2;

  while ( iLeft<iRight )
  {
    //Output(Data);

    if( Data.at(iLeft) > iPivot && Data.at(iRight) > iPivot )
    {
      iRight--;
    }
    else if(Data.at(iLeft) > iPivot && Data.at(iRight) <= iPivot)
    {
      ChangeValue(Data,iLeft,iRight);
      iLeft++;
      iRight--;
    }
    else if(Data.at(iLeft)<iPivot && Data.at(iRight) > iPivot )
    {
      iLeft++;
      iRight--;
    }
    else
    {
      iLeft++;
    }

  }


  if( iPivot > Data.at(iRight) )
  {
    ChangeValue(Data,left,iRight);
    /*cout << "Left:" << left << ", Right:" << right << endl;
    Output(Data);
    //cout << "Next:(" << left << "," << iRight-1 << "),(" << iRight+1 << "," << right << ")" << endl;
    s1 << "(" << left << "," << iRight-1 << ")";
    s2 << "(" << iRight+1 << "," << right << ")";
    sTarget.insert(sTarget.begin(),s2.str());
    sTarget.insert(sTarget.begin(),s1.str());*/
    QuickSort(Data,left,iRight-1);
    QuickSort(Data,iRight+1,right);
  }
  else
  {
    ChangeValue(Data,left,iRight-1);
    /*cout << "Left:" << left << ", Right:" << right << endl;
    Output(Data);
    //cout << "Next:(" << left << "," << iRight-2 << "),(" << iRight << "," << right << ")" << endl;
    s1 << "(" << left << "," << iRight-1 << ")";
    s2 << "(" << iRight+1 << "," << right << ")";
    sTarget.insert(sTarget.begin(),s2.str());
    sTarget.insert(sTarget.begin(),s1.str());*/
    QuickSort(Data,left,iRight-2);
    QuickSort(Data,iRight,right);
  }



}

void ChangeValue(vector<int> &Data,int i,int j)
{
  int temp;

  temp = Data.at(i);
  Data.at(i) = Data.at(j);
  Data.at(j) = temp;
}

void Progress()
{
  for(int i=0;i<sTarget.size();i++)
  {
    cout << sTarget.at(i) << "->";
  }
  cout << endl;
}
