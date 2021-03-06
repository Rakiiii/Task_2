#include "Include_and_constants.h"
#include <windef.h>

const int AmountOfDaysInMonth[13] = { 31 , 30 , 31 , 30 , 31 , 30 , 31 , 30 , 31 , 30 , 31 , 28 , 29 } ; //храним сколько в каком месяце дней

int TranslateNumberOfDayOfWeekToWord( int Number ) //определяем день недели отталкиваясь от полученного по формуле значению
{
    printf( "\nIt's " ) ;
    switch( Number )
    {
        case 1 :
            printf( "Monday" ) ;
            return 0;
        case 2 :
            printf( "Tuesday" ) ;
            return 0;
        case 3 :
            printf( "Wednesday" ) ;
            return 0 ;
        case 4 :
            printf( "Thursday" ) ;
            return 0 ;
        case 5 :
            printf( "Friday" ) ;
            return 0 ;
        case 6 :
            printf( "Saturday" ) ;
            return 0;
        case 0:
            printf( "Sunday" ) ;
            return 0 ;
        default:
            printf( "Unncorect expression" ) ;
            return 0 ;
    }
}

int TakeYear()//читаем год пока он не окажется в допустимом промежутке
{
    int Number = In() ;
    while(Number < 1582 || Number > 4902)
    {
        printf( "Print correct year between 1582 and 4902_  " ) ;
        Number = In() ;
    }
    system( "cls" ) ;
    return Number ;
}

int TakeMonth() //даем пользователю выбрать месяц
{
    printf( "\n1.January\n2.February\n3.March\n4.April\n5.May\n6.June\n7.July\n8.August\n9.September\na.October\n"
                   "b.November\nc.December\nChoose month_ " ) ;
    char ChooseMonth = getch() ;
    switch( ChooseMonth )
    {
        case '1' :
            return 11 ;
        case '2' :
            return 12 ;
        case '3' :
            return 1 ;
        case '4' :
            return 2 ;
        case '5' :
            return 3 ;
        case '6' :
            return 4 ;
        case '7' :
            return 5 ;
        case '8' :
            return 6 ;
        case '9' :
            return 7 ;
        case 'a' :
            return 8 ;
        case 'b' :
            return 9 ;
        case 'c' :
            return 10 ;
        default:
            break ;
    }
}


int TakeDay(int MonthNumber) // читаем день пока он не попадет в промежуток количества дней в выбраном месяце
{
    int Number = In();
    while(Number < 0  || Number > AmountOfDaysInMonth[MonthNumber] )
    {
        Number = In();
    }
    system("cls");
    return Number;
}

int DayOfWeek() //основная функция призываем все остальные функции из нее
{
    system("cls");
    printf("Print year_ ");
    int Year = TakeYear();//читаем год
    printf("Choose month_");
    int Month = TakeMonth();//читаем месяц
    system("cls");
    if( Month == 11 || Month == 12 )Year--; //по условию февраль и январь приявзаны к предыдущему год,поэтому понижаем год на еденицу
    printf("Print day_  ");
    int Day = 0 ;
    if( (  Year % 4 ) == 3 && Month == 12 ) Day = TakeDay(Month + 1); // разбираемся с количеством дней в феврале
    else Day = TakeDay( Month );
    int x = (Year / 100) , y = (Year % 100); // сплитим год на две переменных
    int DayOfWeekVar = ( ( ( 2.6 * Month ) - 0.2 ) + Day + y + ( y / 4 ) + ( x / 4 ) - ( 2 * x ) ) ; //считаем все по данной формуле
    DayOfWeekVar = DayOfWeekVar % 7;
    if ( DayOfWeek < 0 )DayOfWeekVar = DayOfWeekVar + 7;
    TranslateNumberOfDayOfWeekToWord(DayOfWeekVar); // переводим полученной значение в день недели
    return 0;
}


int main() //пишем меню в консоли
{
    while(TRUE)
    {
        system( "cls" ) ;
        printf( "1.Find day of week with date\n2.Exit\n" ) ;
        char Choose = getch() ;
        switch ( Choose )
        {
            case '1' :
                DayOfWeek() ;
                printf( "\nPress any key to restart the program_ " ) ;
                getch() ;
                break ;
            case '2' :
                return 0 ;
            default:
                printf( "Try again" ) ;
        }

    }
}