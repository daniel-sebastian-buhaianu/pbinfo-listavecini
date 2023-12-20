#include <fstream>
using namespace std;
int main()
{
  ifstream f("listavecini.in");
  int n, i, j;
  f >> n;
  int** a = new int*[n];
  for (i = 0; i < n; i++)
  {
    a[i] = new int[n];
    for (j = 0; j < n; j++)
      a[i][j] = 0;
  }
  int* gr = new int[n];
  for (i = 0; i < n; i++)
    gr[i] = 0;
  while (f >> i >> j)
  {
    i--, j--;
    if (!a[i][j])
    {
      gr[i]++, gr[j]++;
      a[i][j] = a[j][i] = 1;
    }
  }
  f.close();
  ofstream g("listavecini.out");
  for (i = 0; i < n; i++)
  {
    g << gr[i] << ' ';
    for (j = 0; j < n; j++)
      if (a[i][j])
        g << j+1 << ' ';
    g << '\n';
  }
  g.close();
  return 0;
}

