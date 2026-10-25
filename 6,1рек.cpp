#include <iostream>     
#include <iomanip>      
#include <ctime>        
#include <cstdlib>      
#include <windows.h>    

using namespace std;

// ---------- прототипи функцій (i - індекс поточного елемента) ----------
void Create(int* a, const int size, const int Low, const int High, int i);   // формування масиву
void Print(int* a, const int size, int i);                                   // виведення масиву
bool IsSelected(int* a, const int i);                                        // перевірка критерію
int Count(int* a, const int size, int i);                                    // кількість потрібних елементів
int Sum(int* a, const int size, int i);                                      // сума потрібних елементів
void ZeroSelected(int* a, const int size, int i);                            // заміна потрібних елементів нулями

int main()
{
    SetConsoleCP(65001);                // кирилиця у консолі (ввід)
    SetConsoleOutputCP(65001);          // кирилиця у консолі (вивід)

    srand((unsigned)time(NULL));        // ініціалізація генератора випадкових чисел

    const int n = 20;                   // кількість елементів масиву
    int a[n];                           // оголосили масив

    int Low = -20;                      // нижня межа діапазону значень
    int High = 50;                      // верхня межа діапазону значень

    Create(a, n, Low, High, 0);         // 1. формуємо масив (починаємо з індексу 0)
    cout << "Початковий масив:" << endl;
    Print(a, n, 0);                     // 2. виводимо його рядком

    cout << "Кількість = " << Count(a, n, 0) << endl;   // 3. кількість елементів за критерієм
    cout << "Сума      = " << Sum(a, n, 0) << endl;     // 4. сума елементів за критерієм

    ZeroSelected(a, n, 0);              // 5. замінюємо ці елементи нулями
    cout << "Змінений масив:" << endl;
    Print(a, n, 0);                     // 6. виводимо змінений масив

    return 0;
}

// Заповнює масив випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)   // рекурсивний спосіб
{
    a[i] = Low + rand() % (High - Low + 1);         // заповнюємо поточний елемент
    if (i < size - 1)                               // якщо це ще не останній елемент
        Create(a, size, Low, High, i + 1);          // переходимо до наступного
}

// Виводить елементи масиву в один рядок, кожен у полі шириною 4 символи
void Print(int* a, const int size, int i)                                   // рекурсивний спосіб
{
    cout << setw(4) << a[i];                        // виводимо поточний елемент
    if (i < size - 1)                               // якщо це ще не останній елемент
        Print(a, size, i + 1);                      // переходимо до наступного
    else
        cout << endl;                               // після останнього - новий рядок
}

// Критерій відбору: елемент додатний і не кратний 5
bool IsSelected(int* a, const int i)
{
    return a[i] > 0 && a[i] % 5 != 0;
}

// Рахує, скільки елементів задовольняє критерію
int Count(int* a, const int size, int i)                                    // рекурсивний спосіб
{
    if (i < size)                                   // поки не вийшли за межі масиву
    {
        if (IsSelected(a, i))                       // поточний елемент підходить
            return 1 + Count(a, size, i + 1);       // рахуємо його + решту масиву
        else
            return Count(a, size, i + 1);           // не рахуємо, йдемо далі
    }
    else
        return 0;                                   // кінець масиву - більше нічого рахувати
}

// Обчислює суму елементів, що задовольняють критерію
int Sum(int* a, const int size, int i)                                      // рекурсивний спосіб
{
    if (i < size)                                   // поки не вийшли за межі масиву
    {
        if (IsSelected(a, i))                       // поточний елемент підходить
            return a[i] + Sum(a, size, i + 1);      // додаємо його + сума решти масиву
        else
            return Sum(a, size, i + 1);             // не додаємо, йдемо далі
    }
    else
        return 0;                                   // кінець масиву - сума дорівнює 0
}

// Замінює нулями елементи, що задовольняють критерію
void ZeroSelected(int* a, const int size, int i)                            // рекурсивний спосіб
{
    if (IsSelected(a, i))                           // якщо поточний елемент підходить
        a[i] = 0;                                   // замінюємо його нулем
    if (i < size - 1)                               // якщо це ще не останній елемент
        ZeroSelected(a, size, i + 1);               // переходимо до наступного
}