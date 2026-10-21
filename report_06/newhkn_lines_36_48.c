    while( 1 ) {
        printf("指定する点は？ X= ");
        scanf("%lf%c",&x,&zz);
        s = a[0][1];
        t = 1;
        /***   差商公式による計算   ***/
        for(j=2; j<=n; j++) {
            t *= (x - a[j-2][0]);
            s += a[0][j] * t;
        }
        /***   答の表示   ***/
        printf("\n f( %10.6lf )= %10.6lf\n",x,s);
    }
