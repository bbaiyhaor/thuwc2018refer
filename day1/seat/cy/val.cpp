#include "testlib.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cerr << "usage : " << argv[0] << " maxn maxm" << endl;
        return 1;
    }
    registerValidation(argc, argv);

    const int maxn = atoi(argv[1]);
    const int maxm = atoi(argv[2]);

    int n = inf.readInt(1, maxn, "n"); inf.readSpace();
    int m = inf.readInt(1, maxm, "m"); inf.readEoln();
    ensure(1 <= n && n <= 300);
    ensure(1 <= m && m <= 10);
    vector<vector<int> > L, R;
    L.assign(n, vector<int>(m));
    R.assign(n, vector<int>(m));

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if (j) inf.readSpace();
            L[i][j] = inf.readInt(0, n-1, "Lij");
        }
        inf.readEoln();
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if (j) inf.readSpace();
            R[i][j] = inf.readInt(0, n-1, "Rij");
        }
        inf.readEoln();
    }

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            ensure(L[i][j] <= R[i][j]);
        }
    }

    inf.readEof();

    return 0;
}