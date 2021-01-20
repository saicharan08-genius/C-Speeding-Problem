//Question Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=568
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ifstream fin("speeding.in");
  ofstream fout("speeding.out");
  int N , M;
  fin >> N >> M;
  int road_length[N];
  int speed_limit[N];
  int bessie_length[M];
  int bessie_speed[M];
  for(int i = 0 ; i < N ; i++)
  {
    fin >> road_length[i] >> speed_limit[i];
  }
  for(int i = 0 ; i < M ; i++)
  {
    fin >> bessie_length[i] >> bessie_speed[i];
  }
  vector<int> speed_limit_rate;
  vector<int> bessie_speed_rate;
  for(int i = 0 ; i < N ; i++)
  {
    for(int j = 0 ; j < road_length[i] ; j++)
    {
      speed_limit_rate.push_back(speed_limit[i]);
    }
  }
  for(int i = 0 ; i < M ; i++)
  {
    for(int j = 0 ; j < bessie_length[i] ; j++)
    {
      bessie_speed_rate.push_back(bessie_speed[i]);
    }
  }
  vector<int> vec;
  int difference = 0;
  for(int i = 0 ; i < 100 ; i++)
  {
    difference = bessie_speed_rate[i] - speed_limit_rate[i];
    vec.push_back(difference);
  }
  fout << *max_element(vec.begin() , vec.end());
}
