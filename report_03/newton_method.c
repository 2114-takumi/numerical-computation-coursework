#include <stdio.h>
#include <math.h>

/*** 関数f(x)とf'(x)の定義 ***/
#define  FNF(x)    (cos(x) - x)
#define  FNG(x)    (-sin(x) - 1)

int main(void)
{
    /** x第次近似値:1, xn漸化式による計算値: **/
    double  x, xn;
    int      k;
    char     z, zz;
    printf("関数FNF(x) = cos(x) - x\n");
    printf("の根をニュートン法で求めます.\n\n");
    printf("第近似値を入力してください1  ");
    scanf("%lf%c", &x, &zz);
    k = 1;
    printf("回数 近似値前の近似値との差       \n");
    printf("     1 %10.6lf\n", x);
    while( 1 ) {
        k = k + 1;
        /*** 漸化式による計算 ***/
        xn = x - FNF(x) / FNG(x);
        printf("%4d %10.6lf     %10.6lf\n", k, xn , xn - x);
        if(fabs(xn - x) < 0.000001)    break;
        x = xn;
        if(k % 10 != 0)    continue;
        printf("\計算過程を表示していますn. \n");
        printf("\表示を継続しますかn?  (y/n): ");
        scanf("%c%c", &z, &zz);
        if(z == 'n') {
            printf("\表示を終わりますn. \n");  break;
        } else if(z == 'y')
            printf("回数 近似値前の近似値との差       \n");
        else { z = 'n';  break; }
    }
    if(z != 'n') {
        printf("\n %3d 回目で収束しました. \n", k);
        printf("\収束値n= %10.6lf\n", xn);
    }
    return 0;
}
