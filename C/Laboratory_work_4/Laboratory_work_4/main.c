//
//  main.c
//  Laboratory_work_4
//
//  Created by Данила Ушаков on 18.09.2023.
//

#include <stdio.h>
#include <locale.h>
int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "Rus");
    
    int count, n = 1, s = 0;
    printf("Введите количество чисел: ");
    scanf("%d", &count);
    for(int i = 1; i <= count; i++)
    {
        if(n % 2 != 0)
        {
            s += n;
        }
        n++;
    }
    printf("s = %d\n", s);
    return 0;
}
