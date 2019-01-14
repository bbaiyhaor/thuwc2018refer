#include "testlib.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cerr << "usage: " << argv[0] << " n m [seed]" << endl;
        return 1;
    }
    registerGen(argc, argv, 1);

    const int n = atoi(argv[1]);
    const int m = atoi(argv[2]);

    vector<vector<int> > L, R;
    L.assign(n, vector<int>(m));
    R.assign(n, vector<int>(m));

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            L[i][j] = rnd.next(0, n-1);
            R[i][j] = rnd.next(0, n-1);
            if (L[i][j] > R[i][j]) swap(L[i][j], R[i][j]);
        }
    
    cout << n << " " << m << endl;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if (j) cout << " ";
            cout << L[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if (j) cout << " ";
            cout << R[i][j];
        }
        cout << endl;
    }

    return 0;
}