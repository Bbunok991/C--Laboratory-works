//
//  main.c
//  Laboratory_work_3
//
//  Created by Данила Ушаков on 18.09.2023.
//

#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "Rus");
    float x, y, z, f;
    float xn, xk, sh;
    
    printf("Программа табулирования функции                                             f(x, y, z) = 1 / (sqrt(sin(x))) + cos(y) / log(z)\n");
    
    printf("Введите y > "); scanf("%f", &y);
    printf("Введите z > "); scanf("%f", &z);
    
    // Сначала проверяем, что z > 0, чтобы можно было проверять log(z)!
    if(z <= 0)
    {
        printf("Значение не входит в ОДЗ!\n");
        return -2;
    }
    
    if(log(z) == 0)
    {
        printf("Значение z не входит в ОДЗ!\n");
        return -3;
    }
    
    printf("Введите начальное значение х >"); scanf("%f", &xn);
    printf("x>"); scanf("%f", &xk);
    printf("x>"); scanf("%f", &sh);
    
    //
    printf("+-----------+-----------+\n");
    printf("!     x     !f(x, y, z) !\n");
    printf("+-----------+-----------+\n");
    
    for (x = xn; x <= xk; x += sh)
    {
        printf("!%5.2f!", x);
        
        if(sin(x) > 0)
        {
            f = 1 / (sqrt(sin(x))) + cos(y) / log(z);
            printf("%8.2f!\n", f);
        }
        else printf("не опр.!\n");
    }
    printf("+-----------+\n");
    return 0;
}
