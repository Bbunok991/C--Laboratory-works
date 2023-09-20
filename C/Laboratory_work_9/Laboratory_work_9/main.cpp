//Программа графика-C++, выполнил Авдеев Андрей, гр. 6111

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
//Класс геометрической фигуры
class figura
{
    protected:
        int cvet,x,y;
    public:
        virtual void Pokaz()=0;
        void Skryt(int BLACK)//Функция скрытия фигуры
        {
            cvet=BLACK;
            Pokaz();
        }
        void Pokras(int color)//Функция изменения цвета фигуры
        {
            cvet=color;
        }
        void setxy(int X,int Y) // Установка новых координат
        {
            x=X;
            y=Y;
        }
};

//Класс треугольник, наследующий функции класса figura
class treug:public figura
{
    public:
    //Конструктор для создания переменной типа treug
    treug(int x1, int y1)
    {
        x=x1;
        y=y1;
    }
    void Pokaz()//Функция показа фигуры
    {
        setcolor(cvet);
        line(x,y,x,y+80);
        line(x,y+80,x-50,y+80);
        line(x-50,y+80,x,y);
    }
};

//Класс прямоугольник — наследник класса figura
class pryam:public figura
{
    public:
    //Констурктор для создания переменной типа pryam
    pryam(int x1,int y1)
    {
        x=x1;
        y=y1;
    }
    void Pokaz()//Функция показа фигуры
    {
        setcolor(cvet);
        rectangle(x+1,y,x+100,y+80);
    }
};

//Класс линия — наследник класса figura
class liniya:public figura
{
    public:
        //Конструктор для создания переменной типа liniya
        liniya(int x1, int y1)
        {
            x=x1;
            y=y1;
        }
        void Pokaz()//Функция показа фигуры
        {
            setcolor(cvet);
            line(x+102,y+40,x+122,y+40);
        }
};

//Класс круг - наследник класса figura
class krug:public figura
{
    private:
        int r;
    public:
        //Констуктор для создания переменной типа krug
        krug(int x1, int y1, int rad)
        {
            x=x1;
            y=y1;
            r=rad;
        }
        void Pokaz()//Функция показа фигуры
        {
            setcolor(cvet);
            circle(x+26,y+91,r);
        }
};

//Класс человек, наследующий функции класа figura
class chelovek:public figura
{
    private:
        int x,y,r,pol;
    public:
        //Конструктор для создания переменной типа chelovek
        chelovek(int x1, int y1,int rad)
        {
            x=x1;
            y=y1;
            r=rad;
        }
        void pol0()//Положение номер 0
        {
            pol=0;
        }
        void pol1()//Положение номер 1
        {
            pol=1;
        }
        void pol2()//Положение номер 2
        {
            pol=2;
        }
        void pol3()//Положение номер 3
        {
            pol=3;
        }
        void Pokaz();//Функция показа фигуры
    
};
    
void chelovek::Pokaz()//Функция показа фигуры
{
    setcolor(cvet);
    switch(pol)//Выбор положения фигуры
    {
        case 0:
            line(x,y,x,y-20);
            line(x,y-20,x+10,y-40);
            line(x+10,y-40,x+20,y-20);
            line(x+20,y-20,x+20,y);
            line(x+10,y-40,x+10,y-80);
            line(x+10,y-80,x-10,y-60);
            line(x-10,y-60,x,y-40);
            line(x+10,y-80,x+30,y-60);
            line(x+30,y-60,x+20,y-40);
            circle(x+10,y-90,r);
            break;
        case 1:
            line(x+10,y,x-10,y-10);
            line(x-10,y-10,x+10,y-20);
            line(x+10,y-20,x+30,y-10);
            line(x+30,y-10,x+10,y);
            line(x+10,y-20,x+10,y-60);
            line(x+10,y-60,x-10,y-40);
            line(x-10,y-40,x+10,y-30);
            line(x+10,y-60,x+30,y-40);
            line(x+30,y-40,x+10,y-30);
            circle(x+10,y-70,r);
            break;
        case 2:
            line(x,y,x,y-20);
            line(x,y-20,x+10,y-40);
            line(x+10,y-40,x+30,y-20);
            line(x+30,y-20,x+50,y);
            line(x+10,y-40,x+10,y-80);
            line(x+10,y-80,x-10,y-60);
            line(x-10,y-60,x-20,y-50);
            line(x+10,y-80,x+30,y-60);
            line(x+30,y-60,x+40,y-50);
            circle(x+10,y-90,r);
            break;
        case 3:
            line(x-30,y,x-10,y-20);
            line(x-10,y-20,x+10,y-40);
            line(x+10,y-40,x+20,y-20);
            line(x+20,y-20,x+20,y);
            line(x+10,y-40,x+10,y-80);
            line(x+10,y-80,x-10,y-60);
            line(x-10,y-60,x-20,y-50);
            line(x+10,y-80,x+30,y-60);
            line(x+30,y-60,x+40,y-50);
            circle(x+10,y-90,r);
            break;
    }
}
int main()
{
    int x1,y1,x9,y9,x16,y16,k,r,r1,i,r2,l,d;
    int s1,s2,s3,v1,v2,v3,v4,n,k1,k2,k3,k4,k5,k6,k7,k8,vv;
    //Подключение графического режима
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\BGI\\");
    //Создание фигур, составляющих паровоз
    x1=689;y1=300;r=10;
    treug nos(x1,y1);
    pryam vag1(x1,y1);
    liniya sv1(x1,y1);
    pryam vag2(x1+121,y1);
    liniya sv2(x1+121,y1);
    krug kol1(x1,y1,r);
    krug kol2(x1+50,y1,r);
    krug kol3(x1+120,y1,r);
    krug kol4(x1+170,y1,r);
    krug kol5(x1+240,y1,r);
    krug kol6(x1+290,y1,r);
    krug kol7(x1+360,y1,r);
    krug kol8(x1+410,y1,r);
    pryam vag3(x1+242,y1);
    liniya sv3(x1+242,y1);
    pryam vag4(x1+363,y1);
    //Цикл движения паровоза
    for(n=5,s1=13,s2=2,s3=54,v1=7,v2=32,v3=11,v4=14,k1=10,k2=6,k3=22,
        k4=18,k5=76,k6=44,k7=5,k8=65,x1=689;x1+363>0;n++,s1++,s2++,s3++, v1++,v2++,v3++,v4++,k1++,k2++,k3++,k4++,k5++,k6++,k7++,k8++,x1-=5)
    {
        nos.Pokras(n);
        nos.Pokaz();
        vag1.Pokras(v1);
        vag1.Pokaz();
        sv1.Pokras(s1);
        sv1.Pokaz();
        vag2.Pokras(v2);
        vag2.Pokaz();
        sv2.Pokras(s2);
        sv2.Pokaz();
        kol1.Pokras(k1);
        kol1.Pokaz();
        kol2.Pokras(k2);
        kol2.Pokaz();
        kol3.Pokras(k3);
        kol3.Pokaz();
        kol4.Pokras(k4);
        kol4.Pokaz();
        kol5.Pokras(k5);
        kol5.Pokaz();
        kol6.Pokras(k6);
        kol6.Pokaz();
        kol7.Pokras(k7);
        kol7.Pokaz();
        kol8.Pokras(k8);
        kol8.Pokaz();
        vag3.Pokras(v3);
        vag3.Pokaz();
        sv3.Pokras(s3);
        sv3.Pokaz();
        vag4.Pokras(v4);
        vag4.Pokaz();
        delay(30);
        //Сокрытие этих фигур
        nos.Skryt();
        vag1.Skryt();
        sv1.Skryt();
        vag2.Skryt();
        sv2.Skryt();
        vag3.Skryt();
        kol1.Skryt();
        kol2.Skryt();
        sv3.Skryt();
        vag4.Skryt();
        kol4.Skryt();
        kol3.Skryt();
        kol5.Skryt();
        kol6.Skryt();
        kol7.Skryt();
        kol8.Skryt();
        //Изменение координат этих фигур
        nos.setxy(x1,y1);
        vag1.setxy(x1,y1);
        sv1.setxy(x1,y1);
        vag2.setxy(x1+121,y1);
        sv2.setxy(x1+121,y1);
        vag3.setxy(x1+242,y1);
        kol1.setxy(x1,y1);
        kol2.setxy(x1+50,y1);
        sv3.setxy(x1+242,y1);
        vag4.setxy(x1+363,y1);
        kol4.setxy(x1+170,y1);
        kol3.setxy(x1+120,y1);
        kol5.setxy(x1+240,y1);
        kol6.setxy(x1+290,y1);
        kol7.setxy(x1+360,y1);
        kol8.setxy(x1+410,y1);
    }
    //Задание координат для объектов типа chelovek
    x9=300; y9=200;r1=10;
    //Создание фигур типа человек в позе No 0
    chelovek ch1(x9,y9,r1);
    chelovek ch2(x9+60,y9,r1);
    chelovek ch3(x9-60,y9,r1);
    ch1.pol0();
    ch2.pol0();
    ch3.pol0();
    ch1.Pokras(29);
    ch2.Pokras(9);
    ch3.Pokras(4);
    ch1.Pokaz();
    ch2.Pokaz();
    ch3.Pokaz();
    delay(1000);
    ch1.Skryt();
    ch2.Skryt();
    ch3.Skryt();
    //Цикл танцующих человечков
    for(vv=0; vv<10; vv++)
    {
        //Смена координат для позы No 1
        ch1.pol1();
        ch2.pol1();
        ch3.pol1();
        ch1.Pokras(29);
        ch2.Pokras(9);
        ch3.Pokras(4);
        ch1.Pokaz();
        ch2.Pokaz();
        ch3.Pokaz();
        delay(200);
        ch1.Skryt();
        ch2.Skryt();
        ch3.Skryt();
        //Смена координат для позы No 2
        ch1.pol2();
        ch2.pol2();
        ch3.pol2();
        ch1.Pokras(29);
        ch2.Pokras(9);
        ch3.Pokras(4);
        ch1.Pokaz();
        ch2.Pokaz();
        ch3.Pokaz();
        delay(200);
        ch1.Skryt();
        ch2.Skryt();
        ch3.Skryt();
        //Смена координат для позы No 1
        ch1.pol1();
        ch2.pol1();
        ch3.pol1();
        ch1.Pokras(29);
        ch2.Pokras(9);
        ch3.Pokras(4);
        ch1.Pokaz();
        ch2.Pokaz();
        ch3.Pokaz();
        delay(200);
        ch1.Skryt();
        ch2.Skryt();
        ch3.Skryt();
        //Смена координат для позы No 3
        ch1.pol3();
        ch2.pol3();
        ch3.pol3();
        ch1.Pokras(29);
        ch2.Pokras(9);
        ch3.Pokras(4);
        ch1.Pokaz();
        ch2.Pokaz();
        ch3.Pokaz();
        delay(200);
        ch1.Skryt();
        ch2.Skryt();
        ch3.Skryt();
    }
    //Создание объекта типа krug
    x16=294; y16=149; r2=20;
    krug kr(x16,y16,r2);
    //Цикл для движения круга, отталкивающегося от стен
    for(d=0; d<5 ; d++)
    {
        //Цикл для движения вправо вверх
        for(x16=-6, y16=149,l=0; x16<294; x16+=15, y16-=11,l++)
        {
            kr.Pokras(l);
            kr.Pokaz();
            delay(30);
            kr.Skryt();
            kr.setxy(x16,y16);
        }
        //Цикл для движения вправо вниз
        for(x16=294, y16=-71,l=0; x16<594; x16+=15, y16+=11 ,l++)
        {
            kr.Pokras(l);
            kr.Pokaz();
            delay(30);
            kr.Skryt();
            kr.setxy(x16,y16);
        }
        //Цикл для движения влево вниз
        for(x16=594, y16=149,l=0; x16>294; x16-=15, y16+=11 ,l++)
        {
            krug kr(x16,y16,r2);
            kr.Pokras(l);
            kr.Pokaz();
            delay(30);
            kr.Skryt();
            kr.setxy(x16,y16);
        }
        //Цикл для движения влево вверх
        for(x16=294, y16=369, r2=20,l=0; x16>-6; x16-=15, y16-=11 ,l++)
        {
            krug kr(x16,y16,r2);
            kr.Pokras(l);
            kr.Pokaz();
            delay(30);
            kr.Skryt();
            kr.setxy(x16,y16);
        }
        
    }
    //Закрытие графики
    closegraph();
    return 0;
}
