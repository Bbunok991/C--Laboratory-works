//
//  main.c
//  Laboratory_work_5
//
//  Created by Данила Ушаков on 18.09.2023.
//

#include <stdio.h>
#include <math.h>

int print_Mat(float x[5] [5])
{
    int i, j;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%7.2f", x[i] [j]);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    int i,j,jj;
    float z,MaxSum,Sum,a[5][5]= { {1, 2, 3, 4, 0.5},
                       {2, 5, -1, -7, 100},
                       {5, 4, 3, 2, 1},
                       {-100, 11, 23.81, -5,1},
                       {1, 2, 3, 4, 5} }; //z -буфер
    printf ("Программа сортировки столбцов матрицы 5×5 по убыванию максимумов\n");
    // Печатаем матрицу до обработки
    printf("Исходная матрица:\n");
    print_Mat(a); // Передаем матрицу в функцию print_Mat для печати

    // Начало алгоритма сортировки перестановками
    for (j = 0; j < 4; j++) // Цикл с первого столбца до предпоследнего
    {
        MaxSum=0;
        for (i = 0; i < 5; i++) MaxSum += a[i] [j]; // Находим сумму элементов текущего столбца-максимума
        for (jj = j+1; jj < 5; jj++)
        {
            Sum=0;
            for (i = 0; i < 5; i++) Sum += a[i] [jj]; // Сумма столбца-кандидата
            if (MaxSum<Sum)
            {
                MaxSum=Sum; // Новый максимум суммы
                for(i=0;i<5;i++) // Переставляем местами столбцы
                {
                    z=a[i][j];
                    a[i][j]=a[i][jj];
                    a[i][jj]=z;
                }
            }
        }
    }
    
    // Печать матрицы после сортировки
    printf("Результирующая матрица:\n");
    print_Mat(a);
    return 0;
}
