/* Система управления базой данных о студентах */
#include <stdio.h>
#include <string.h>
// Описание структуры данных "Студент"
struct
{
    char Family[50]; // Фамилия
    char Imy[50];  // Имя
    char Otcestvo[50];  // Отчество
    char NGr[7]; // Номер группы
    int GodR; // Год рождения
    float SrBall; // Средний балл
    float Stip; // Размер стипендии
} Stud;
// Функция добавления в БД записи о студенте

int Dobavl()
{
    FILE *fp;
    // Открываем текстовый файл данных для добавления
    if((fp=fopen("Students.txt","a"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 1;
        
    }
    printf("Введите информацию о добавляемом в БД студенте\n");
    printf("ФИО:");scanf("%s %s %s",Stud.Family,Stud.Imy,Stud.Otcestvo);
    fprintf(fp,"%s %s %s ",Stud.Family,Stud.Imy,Stud.Otcestvo);
    printf("Номер группы:");scanf("%s",Stud.NGr);fprintf(fp,"%s ",Stud.NGr);
    printf("Год рождения:");scanf("%d",&Stud.GodR);fprintf(fp,"%d ",Stud.GodR);
    printf("Средний балл:");scanf("%f",&Stud.SrBall);fprintf(fp,"%f ",Stud.SrBall);
    printf("Размер стипендии:");scanf("%f",&Stud.Stip);fprintf(fp,"%f\n",Stud.Stip);
    fclose(fp);
    return 0;
}

// Функция чтения очередной записи о студенте из файла
int ReadNext(FILE *fp)
{
    fscanf(fp,"%s",Stud.Family); // прочитали фамилию
    fscanf(fp,"%s",Stud.Imy); // прочитали имя
    fscanf(fp,"%s",Stud.Otcestvo); // прочитали отчество
    fscanf(fp,"%s",Stud.NGr); // прочитали номер группы
    fscanf(fp,"%d",&Stud.GodR); // прочитали год рождения
    fscanf(fp,"%f",&Stud.SrBall); // прочитали размер стипендии
    fscanf(fp,"%f",&Stud.Stip); // прочитали размер стипендии
    return 0;
}

// Поиск по номеру группы
int PoiskNGr()
{
    FILE *fp;
    int pr=0;
    char Str[80];
    printf("Введите номер группы:");
    scanf("%s",Str);
    printf("\n");
    
    // начинаем читать файл с начала
    if((fp=fopen("Students.txt","r"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 2;
        
    }
    while(!feof(fp))
    {
        ReadNext(fp);
        if (!strcmp(Str,Stud.NGr))
        {
            pr=1;
            if(!feof(fp))
            {
                printf("%s %s %s %s %d %5.2f %7.2f\n",Stud.Family,Stud.Imy,Stud.Otcestvo,Stud.NGr,Stud.GodR,Stud.SrBall,Stud.Stip);
            }
            
        }
        
    }
    if (pr!=1) printf("Не найдено подобной записи!\n");
    fclose(fp);
    return 0;
}

// Функция поиска по фамилии
int PoiskFamily()
{
    FILE *fp;
    int pr=0;
    char Str[80];
    printf("Введите фамилию:");
    scanf("%s",Str);
    printf("\n");
    // начинаем читать файл с начала
    if((fp=fopen("Students.txt","r"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 2;
    }
    while(!feof(fp))
    {
        ReadNext(fp);
        if (!strcmp(Str,Stud.Family))
        {
            pr=1;
            if(!feof(fp))printf("%s %s %s %s %d %5.2f %7.2f\n",Stud.Family,Stud.Imy,Stud.Otcestvo,Stud.NGr,Stud.GodR,Stud.SrBall,Stud.Stip);
        }
        
    }
    if (pr!=1) printf("Не найдено подобной записи!\n");
    fclose(fp);
    return 0;
}

// Поиск по диапазону года рождения
int PoiskGodr()
{
    FILE *fp;
    int pr=0,GodMin,GodMax;
    printf("Год рождения от:");
    scanf("%d",&GodMin);
    printf("Год рождения по:");
    scanf("%d",&GodMax);
    printf("\n");
    // начинаем читать файл с начала
    if((fp=fopen("Students.txt","r"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 2;
        
    }
    while(!feof(fp))
    {
        ReadNext(fp);
        if (Stud.GodR>=GodMin && Stud.GodR<=GodMax)
        {
            pr=1;
            if(!feof(fp))printf("%s %s %s %s %d %5.2f %7.2f\n",Stud.Family,Stud.Imy,Stud.Otcestvo,Stud.NGr,Stud.GodR,Stud.SrBall,Stud.Stip);
        }
        
    }
    if (pr!=1) printf("Не найдено подобной записи!\n");
    fclose(fp);
    return 0;
}

// Поиск по диапазону среднего балла
int PoiskSrBall()
{
    FILE *fp;
    int pr=0;
    float BalMin,BalMax;
    printf("Средний балл от:");
    scanf("%f",&BalMin);
    printf("Средний балл по:");
    scanf("%f",&BalMax);
    printf("\n");
    // начинаем читать файл с начала
    if((fp=fopen("Students.txt","r"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 2;
        
    }
    while(!feof(fp))
    {
        ReadNext(fp);
        if (Stud.SrBall>=BalMin && Stud.SrBall<=BalMax)
        {
            pr=1;
            if(!feof(fp))printf("%s %s %s %s %d %5.2f %7.2f\n",Stud.Family,Stud.Imy,Stud.Otcestvo,Stud.NGr,Stud.GodR,Stud.SrBall,Stud.Stip);
        }
        
    }
    if (pr!=1) printf("Не найдено подобной записи!\n");
    fclose(fp);
    return 0;
}

// Удаление записи
int Udal()
{
    FILE *fp,*fp1;
    int pr=0;
    char Fam[50],Imy[50],Otc[50];
    int God;
    printf("Введите ФИО для удаления: ");
    scanf("%s %s %s",Fam,Imy,Otc);
    printf("Введите год рождения: ");
    scanf("%d",&God);
    printf("\n");
    // начинаем читать файл с начала
    if((fp=fopen("Students.txt","r"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 2;
    }
    // промежуточный файл
    if((fp1=fopen("Students.bak","w"))==NULL)
    {
        printf("Ошибка!\n\7");
        return 3;
    }
    while(!feof(fp))
    {
        ReadNext(fp);
        // Переписываем в промежуточный файл по очереди все записи, кроме удаляемой
        if (strcmp(Fam,Stud.Family) || strcmp(Imy,Stud.Imy) || strcmp(Otc,Stud.Otcestvo) || God!=Stud.GodR)
        {
            if(!feof(fp)) printf(fp1,"%s %s %s %s %d %5.2f %7.2f\n",Stud.Family,Stud.Imy,Stud.Otcestvo,Stud.NGr,Stud.GodR,Stud.SrBall,Stud.Stip);
        }
        else pr=1;
    }
    if (pr==1)
        printf("Запись успешно удалена!");
    else
        printf("Не найдено подобной записи!\n");
    fclose(fp);
    fclose(fp1);
    // Для успеха копирования промежуточного файла сначала стираем основной
    if (remove("Students.txt")==-1)
    {
        printf("Ошибка!\n\7");
        return 4;
        
    }
    // Теперь переименовываем промежуточный файл в основной
    if (rename("Students.bak","Students.txt")==-1)
    {
        printf("Ошибка!\n\7");
        return 5;
    }
    return 0;
}

// Меню
int Menu()
{
    int alt;
    printf ("\nВведите номер требуемого режим работы:\n\n");
    printf ("1. Добавление данных\n");
    printf ("2. Поиск данных по фамилии\n");
    printf ("3. Поиск данных по номеру группы\n");
    printf ("4. Поиск данных по диапазону годов рождения\n");
    printf ("5. Поиск данных по диапазону среднего балла\n");
    printf ("6. Удаление данных\n");
    printf ("7. Выход\n");
    scanf("%d",&alt);
    return alt;
}

// Главная функция программы
int main()
{
    int Reg=0;
    printf("\nСистема управления базой данных о студентах\n");
    while (Reg!=7) // Цикл, пока не будет введен вариант выхода
    {
        Reg=Menu();
        switch (Reg)
        {
            case 1:
                Dobavl();
                break; // Вызов функции добавления данных
            case 2:
                PoiskFamily();
                break; // Вызов функции поиска по фамилии группы
            case 3:
                PoiskNGr();
                break; // Вызов функции поиска по номеру
            case 4:
                PoiskGodr();
                break; // Вызов функции поиска по году рождения
            case 5:
                PoiskSrBall();
                break; // Вызов функции поиска по среднему баллу
            case 6:
                Udal();
                break; // Вызов функции удаления
        }
        
    }
    return 0;
}
