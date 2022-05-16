// https://www.youtube.com/watch?v=JbRsM2X2_pg&ab_channel=Pepcoding
// l = left, r=right
// T = True, F=False
// op = operator
// Exp = l op r
// op       toatal Trues,               Total False
// &            lT*rT              lT*rF + lF*rT + lF*rF
// |    lT*rF + lF*rT + lT*rT           lF*rF
// ^    lT*rF + lF*rT               lF*rF + lT*rT
// e.g T|T&F^T
// Without mod
// if (op == '&') {
//     Tdp[i][j] += lTcount * rTcount;
//     Fdp[i][j] += lTcount * rFcount + lFcount * rTcount + lFcount * rFcount;
// } else if (op == '|') {
//     Tdp[i][j] += lTcount * rTcount + lTcount * rFcount + lFcount * rTcount;
//     Fdp[i][j] += lFcount * rFcount;
// } else if (op == '^') {
//     Tdp[i][j] += lTcount * rFcount + lFcount * rTcount;
//     Fdp[i][j] += lTcount * rTcount + lFcount * rFcount;
// }

int _add(int a, int b, int mod) {
    return (a + b) % mod;
}
int _mul(int a, int b, int mod) {
    return (a * b) % mod;
}
int countWays(int n, string s) {
    int mod = 1003;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '&' or s[i] == '|' or s[i] == '^')
            s2.push_back(s[i]);
        else
            s1.push_back(s[i]);
    }
    n = s1.size();
    vector<vector<int>> Tdp(n, vector<int>(n, 0)), Fdp(n, vector<int>(n, 0));
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 0) {
                Tdp[i][j] = (s1[i] == 'T');
                Fdp[i][j] = !Tdp[i][j];
            } else {
                for (int k = i; k < j; k++) {
                    char op = s2[k];
                    int lTcount = Tdp[i][k];
                    int rTcount = Tdp[k + 1][j];
                    int lFcount = Fdp[i][k];
                    int rFcount = Fdp[k + 1][j];
                    if (op == '&') {
                        Tdp[i][j] = _add(Tdp[i][j], _mul(lTcount, rTcount, mod), mod);
                        Fdp[i][j] = _add(Fdp[i][j], _add(_mul(lTcount, rFcount, mod), _add(_mul(lFcount, rTcount, mod), _mul(lFcount, rFcount, mod), mod), mod), mod);
                    } else if (op == '|') {
                        Tdp[i][j] = _add(Tdp[i][j], _add(_mul(lTcount, rTcount, mod), _add(_mul(lTcount, rFcount, mod), _mul(lFcount, rTcount, mod), mod), mod), mod);
                        Fdp[i][j] = _add(Fdp[i][j], _mul(lFcount, rFcount, mod), mod);
                    } else if (op == '^') {
                        Tdp[i][j] = _add(Tdp[i][j], _add(_mul(lTcount, rFcount, mod), _mul(lFcount, rTcount, mod), mod), mod);
                        Fdp[i][j] = _add(Fdp[i][j], _add(_mul(lTcount, rTcount, mod), _mul(lFcount, rFcount, mod), mod), mod);
                    }
                }
            }
        }
    }
    return Tdp[0][n - 1];
}