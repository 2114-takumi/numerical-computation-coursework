#include <stdio.h>
#define N 11

int main(void)
{
    int    i, j, k, n;
    double x[N], y[N], dd[N][N], xx, prod, s;

    /* 補間点（演習問題 3.5 の数表） */
    double xt[] = {0.0, 0.4, 2.0, 3.0, 5.0};
    double yt[] = {1.0000, 1.0315, 3.0000, 5.2915, 11.225};
    n = 5;
    for (i = 0; i < n; i++) { x[i] = xt[i]; y[i] = yt[i]; }

    /* 差商表の作成 */
    for (i = 0; i < n; i++) dd[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++)
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i])
    ;

    /* x = 1.0 におけるニュートン補間多項式の評価 */
    xx    = 1.0;
    s     = dd[0][0];
    prod = 1.0;
    for (k = 1; k < n; k++) {
        prod *= (xx - x[k-1]);
        s    += dd[0][k] * prod;
    }

    printf("f(%.1f) = %.4f\n", xx, s);    /* f(1.0) = 1.4616 */
    return 0;
}
