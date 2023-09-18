/* Низкоуровневые операции языка Си */
#include <stdio.h>
#include <locale.h>
/* Функция выводит аргумент на экран в двоичном виде */
int prn2(int a)
{
    setlocale(LC_ALL, "Rus");
    int i;
  /* поразрядный вывод 0 или 1 */
    for(i = sizeof(int) * 8 - 1; i >= 0; i--) /* перебираем разряды справа налево */
        printf("%d",(a>>i)&1); /* наложение маски &1 оставляет нужный бит */
    return 0;
}
int main()
{
    int n,mask;
    printf("Программа наложения битовой маски на число\n");
    printf("Введите число:");scanf("%d",&n);
    printf("Введите маску:");scanf("%d",&mask);
    printf("В двоичном виде:\n\n");
    printf("Исходное число: "); prn2(n); printf("\n");
    printf("Маска: "); prn2(mask); printf("\n");
    printf("===========================\n");
    printf("Результат: "); prn2(n&mask); printf("\n");
    return 0;
}
