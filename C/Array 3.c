//2D array

#include<stdio.h>
int main()
{
    int raw1,raw2,col1,col2;

    //1st matrix
    printf("Enter the value of raw & column for the first matrix :\n");
    printf("Raw 1 : ");
    scanf("%d",&raw1);
    printf("Column 1 : ");
    scanf("%d",&col1);
    int ar1[raw1][col1];
    //2nd matrix
    printf("Enter the value of raw & column for the second matrix :\n");
    printf("Raw 2 : ");
    scanf("%d",&raw2);
    printf("Column 2 : ");
    scanf("%d",&col2);
    int ar2[raw2][col2];

    //Result Matrix
    int res[raw1][col1];

    //Entering value in matrix 1
    printf("Entering value in matrix 1 : \n");

    for(int i=0;i<raw1;i++)
    {
        for(int j =0;j<col1;j++)
        {
            printf("[%d][%d] = ",i,j);
            scanf("%d",&ar1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //Entering value in matrix 2
    printf("Entering value in matrix 2 : \n");

    for(int i=0;i<raw2;i++)
    {
        for(int j =0;j<col2;j++)
        {
            printf("[%d][%d] = ",i,j);
            scanf("%d",&ar2[i][j]);
        }
        printf("\n");
    }
    /*For Addition raw & column must be same for both matrix.
    So we can use raw1 or raw2 both . It is also same for the col1 & col2 */
    if(raw1==raw2 && col1 == col2)
    {
        for(int i=0;i<raw1;i++)
        {
            for(int j =0;j<col1;j++)\
            {
                res[i][j]=ar1[i][j] + ar2[i][j];
            }
        }
    }
    else
    {
        printf("Addition is not possible.\n");
    }
    printf("Matrix after addition : \n");
    for(int i=0;i<raw2;i++)
    {
        for(int j =0;j<col2;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");

    }
    //For Subtraction
    int result_subtraction[raw1][col1];
    //Beacuse also for subtraction column & raw size must be same
    if(raw1==raw2 && col1==col2)
    {
        for(int i=0;i<raw1;i++)
        {
            for(int j=0;j<col1;j++)
            {
                result_subtraction[i][j]= ar1[i][j] - ar2[i][j];
            }
        }
    }
    printf("Matrix after subtraction (A-B)\n");
    for(int i=0;i<raw1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            printf("%d ",result_subtraction);
        }
        printf("\n");
    }



    return 0;

}
