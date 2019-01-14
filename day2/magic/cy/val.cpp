#include "testlib.h"

#include <iostream>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "usage : " << argv[0] << " type[1~8]" << endl;
        return 1;
    }
    registerValidation(argc, argv);

    const int type = atoi(argv[1]);

    int n = inf.readInt(1, int(2.5*1e5), "n"); inf.readEoln();

    for(int i = 1; i <= n; i ++)
    {
        inf.readInt(0, 998244353 - 1); inf.readSpace();
        inf.readInt(0, 998244353 - 1); inf.readSpace();
        inf.readInt(0, 998244353 - 1); inf.readEoln();
    }

    int m = inf.readInt(1, int(2.5*1e5), "n"); inf.readEoln();
    bool asked = false;
    for(int i = 1; i <= m; i ++)
    {
        int opt = inf.readInt(1, 7); inf.readSpace();
        int l = inf.readInt(1, n); inf.readSpace();
        int r= inf.readInt(1, n);
        if (opt == 4 || opt == 5 || opt == 6) {
            inf.readSpace();
            inf.readInt(0, 998244353 - 1);
        }
        inf.readEoln();
        asked |= opt == 7;

        ensure(l <= r);
        if (type == 2) {
            ensure(l == 1 && r == n);
        }
        if (type == 3) {
            if (opt != 7) {
                ensure(l == 1 && r == n);
            }
            if (asked) {
                ensure(opt == 7);
            }
        }
        if (type == 4) {
            ensure(opt == 4 || opt == 5 || opt == 6 || opt == 7);
        }
        if (type == 5) {
            ensure(opt == 1 || opt == 2 || opt == 7);
        }
        if (type == 6) {
            ensure(opt == 1 || opt == 2 || opt == 3 || opt == 5 || opt == 7);
        }
    }

    if (type == 1) {
        ensure(LL(n)*LL(m) <= LL(1e7));
    }
    if (type == 7) {
        ensure(n <= int(1e5) && m <= int(1e5));
    }

    inf.readEof();

    return 0;
}