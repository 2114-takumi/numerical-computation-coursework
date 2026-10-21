#include <stdio.h>
#include <math.h>

#define FNF(x)  (cos(x) - x)

int main(void){
    double a, b, c;
    int k;
    char z, zz;
    while( 1 ){
        printf("f(a)*f(b)となる<0 a , b を");
        printf("入力してください. \n\n");
        printf("第一区間[a, b] のa=");
        scanf("%lf%c", &a, &zz);
        printf("第一区間[a,b] のb=");
        scanf("%lf%c", &b, &zz);
        printf("\正しく入力しましたか？n(y/n)");
        scanf("%c%c", &z, &zz);
        if(z == 'n'){
            continue;
        }
        if((z == 'y') && (a < b) && (FNF(a) * FNF(b) < 0)){
            break;
        }
        else{
            printf("\na >b かf(a)*f(b) >= 0 になります. \n");
            printf("データを入れなおしてください. \n");
            printf("エンターキーを押してください. \n");
            scanf("%c", &z);
            continue;
        }
    }

    k = 0;
    printf("回数 左端     A 右端     B 区間幅 B-A\n");
    /* 収束するまで繰り返す */
    while(b - a > 0.000001){
        k++;
        printf("%4d %8.5lf %8.5lf %8.5lf\n", k, a, b, b - a);
        /* 点a,の中点を求め，ba,の座標を更新するb */
        c = (a + b) / 2.0;
        if(FNF(a) * FNF(c) > 0){
            a = c;
        }
        else b = c;
        if((k % 10) == 0){
            printf("\計算過程を表示していますn.\n");
            printf("表示を継続しますか？(y/n): ");
            scanf("%c%c", &z, &zz);
            if(z == 'n'){
                printf("表示を終わります. \n");
                break;
            }
            else{
                if(z == 'y'){
                    printf("回数 左端     A 右端     B 区間幅 B-A\n");
                }
                else {
                    z = 'n';
                    break;
                }
            }
        }
    }
    if(z != 'n'){
        printf("  %3d 回目で収束しました. \n", k);
        printf("\収束値n = %10.6lf ", (a + b) / 2.0);
    }
    return 0;
}
