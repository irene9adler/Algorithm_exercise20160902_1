#include <stdio.h>
#define M 15
#define N 4
//int arr[M][M];
//int b [N][N];
int loc[N];
int main()
{
    int i,j,m,n,l,T;
   /* for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
            scanf("%d",arr[i][j]);
    }

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            scanf("%d",b[i][j]);
    }
    scanf("%d",T);*/
 int   arr[M][M] = {
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,1,0,0,0,
1,1,1,0,0,0,1,1,1,1,
0,0,0,0,1,0,0,0,0,0};
  int  b[N][N] = {
0,0,0,0,
0,1,1,1,
0,0,0,1,
0,0,0,0
    };
    T = 3;
    int min_loc_a[N] = {0};
    int min_loc[N] = {0};
    int min_loc_index = 0;
    int min_loc_res;
    //用15矩阵的4列和b的四列逐列比对，得到停下的位置
    for(l = 0; l <4; l++){
    for(n=0;n<4;n++)//第n列
    {
        for(m = 14;m>=0;m--)
            if(arr[m][n+T] == 1)
               break;//此时的m是大矩阵第n列最下面的1
    }
    printf("m= %d\n",m);
    min_loc_a[l] = m;
    for(j=0;j<N;j++)//第j列
    {
        for(i=3;i>=0;i--)
            if(b[i][j] == 1)
                break;//此时的i是小矩阵最下面的1
    }
    printf("i= %d\n",i);

        min_loc[l] = m-i;
        printf("min_loc : %d\n",min_loc);

    }
    for(i=0;i<3;i++)
    {
        if(min_loc[i+1] < min_loc[i])
            min_loc_index = i+1;
    }
    printf("min_loc_index : %d\n",min_loc_index);
    min_loc_res = min_loc_a[min_loc_index];

    for(n = T;n<T+4;n++)
    {
        for(m = min_loc_res;m > (min_loc_res-4); m--)
            if(b[n-T][m] == 1)
              arr[n][m] = b[n-T][m];
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<M;j++)
            printf("%d ",arr[i][j]);

        printf("\n");
    }
    return 0;
}
