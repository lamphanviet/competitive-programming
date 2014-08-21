#include <stdio.h>
#include <string.h>

int fre;

void A1()
{
    while (fre-->0)
    {
        printf("1\n");
        if (fre!=0) printf("\n");
    }
}
void A2()
{
    while (fre-->0)
    {
        printf("1\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A3()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A4()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A5()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n55555\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A6()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n55555\n666666\n55555\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A7()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n55555\n666666\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A8()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}
void A9()
{
    while (fre-->0)
    {
        printf("1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n88888888\n7777777\n666666\n55555\n4444\n333\n22\n1\n");
        if (fre!=0) printf("\n");
    }
}


main()
{
    int time,amp;
    scanf("%d",&time);
    while (time-->0)
    {
        scanf("%d %d",&amp,&fre);
        switch (amp)
        {
            case 1: A1(); break;
            case 2: A2(); break;
            case 3: A3(); break;
            case 4: A4(); break;
            case 5: A5(); break;
            case 6: A6(); break;
            case 7: A7(); break;
            case 8: A8(); break;
            case 9: A9(); break;
        }
        if (time!=0) printf("\n");
    }
}
