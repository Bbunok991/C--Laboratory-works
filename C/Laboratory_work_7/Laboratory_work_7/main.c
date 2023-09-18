#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    int Mark;
    // Ввод оценки в виде целого числа
    printf("Программа оценивания по шкале вуза\n Введите целое число- >");
    scanf("%d",&Mark);
    // Вывод оценки в строковой форме
    switch (Mark)
    {
        case 2:printf("неуд\n");break;
        case 3:printf("удовл\n");break;
        case 4:printf("хорошо\n");break;
        case 5:printf("отлично\n");break;
        default:printf("Нет такой оценки!\n");
    }
    return 0;
}
