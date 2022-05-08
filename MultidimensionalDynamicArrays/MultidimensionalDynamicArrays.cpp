/*
    Домашнє завдання 
"Багатовимірні динамічні масиви"
1. Знайти суму елементів матриці, які є додатні.  Кількість стовпців і рядків матриці повинен вводити користувач.
    За введеним даним, динамічно, повинна виділитися пам'ять під матрицю. Матрицю заповнювати випадковими значеннями,
    як негативними так і позитивними.
    Знайдіть суму елементів, які знаходяться на головній діагоналі.
    Знайдіть суму елементів, які знаходяться на другорядній діагоналі.
    Обчисліть суму елементів, які знаходяться під головною діагоналлю
2.2. Відсортуйте динамічний масив за зростанням або спаданням.
    Реалізуйте меню для користувача.
    Наприклад:
        1 – сортування за зростанням
        2 – за спаданням.
    */

#include <Windows.h>
#include <ctime>        
#include <iostream>
#include <conio.h>  
#include <stdio.h> 


using namespace std;


void inputArr(int** matrix, int n, int m) {      
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 41 - 20;    
        }
    }
}


void printArr(int** matrix, int n, int m) { 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}


int sumOfPos(int** matrix, int n, int m) {      
    int sum = 0;        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {       

            if (matrix[i][j] > 0)       
            {
                sum += matrix[i][j];        
            }
        }
    }
    return sum;     
}


void sumOfMainD(int** matrix, int n, int m) {      
    int sum = 0;        
    if (n == m) {        
        for (int i = 0; i < n; i++)
        {                                       
            for (int j = 0; j < m; j++) {

                if (i == j)                     
                {
                    sum += matrix[i][j];         
                }
            }
        }
        cout << "Сума діагоналі = " << sum;   
    }
    else {
        cout << "Вибачте, але ваша Матриця не має головної діагоналі"; 
    }
}


void sumOfSecD(int** matrix, int n, int m) {      
    int sum = 0;
    if (n == m) {           
        for (int i = 0; i < n; i++)
        {                       
            for (int j = 0; j < m; j++)
            {
                if (i + j == m - 1)          
                {
                    sum += matrix[i][j];         
                }
            }
        }
        cout << "Сума вторинної діагоналі = " << sum;
    }
    else {
        cout << "Вибачте, але ваша матриця не має вторинної діагоналі";    
    }
}


void sumOfUnderMainD(int** matrix, int n, int m) {      
    int sum = 0;
    if (n == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {        

                sum += matrix[i][j];
            }
        }
        cout << "Сума під головною діагоналлю = " << sum;
    }
    else {
        cout << "Вибачте, але ваша матриця не має головної діагоналі";
    }
}


void sortUp(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)                 
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < n; z++)
            {
                for (int x = 0; x < m; x++)          
                {
                    if (z + 1 == n && x + 1 == m) {      
                        continue;       
                    }
                    else {
                        if (x + 1 == m && matrix[z][x] > matrix[z + 1][0])       
                        {
                            int temp = matrix[z][x];
                            matrix[z][x] = matrix[z + 1][0];
                            matrix[z + 1][0] = temp;
                        }
                        else {
                            if (x + 1 == m) 
                            {
                                continue; 
                            }
                            else {
                                if (matrix[z][x] > matrix[z][x + 1])         
                                {
                                    swap(matrix[z][x], matrix[z][x + 1]);        
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void sortDown(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)                 
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < n; z++)
            {
                for (int x = 0; x < m; x++)          
                {
                    if (z + 1 == n && x + 1 == m) {      
                        continue;       
                    }
                    else {
                        if (x + 1 == m && matrix[z][x] < matrix[z + 1][0])       
                        {
                            int temp = matrix[z][x];
                            matrix[z][x] = matrix[z + 1][0];
                            matrix[z + 1][0] = temp;
                        }
                        else {
                            if (x + 1 == m) 
                            {
                                continue; 
                            }
                            else {
                                if (matrix[z][x] < matrix[z][x + 1])         
                                {
                                    swap(matrix[z][x], matrix[z][x + 1]);        
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int** matrix = nullptr;
    int n = 100;
    int m = 100;

    cout << "Введіть розмір стовпців матриці (N) і рядків (M)" << endl; 

    cin >> n >> m;

    matrix = new int* [n];


    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];         
    }


    inputArr(matrix, n, m);     
    printArr(matrix, n, m);      


    cout << endl;
    cout << "Сума додатніх елементів = " << sumOfPos(matrix, n, m);    
    cout << endl;


    sumOfMainD(matrix, n, m);           
    cout << endl;
    sumOfSecD(matrix, n, m);            
    cout << endl;
    sumOfUnderMainD(matrix, n, m);     
    cout << endl;
    cout << endl;
    cout << "Відсортуйте свою матрицю" << endl;
    cout << "Вибір способу сортування" << endl;                  
    cout << "Якщо вам потрібно Вгору, введіть = u " << endl;            
    cout << "Якщо вам потрібно Вниз, введіть = d " << endl;


    char a = _getch();      


    if (a == 'u') {                 
        sortUp(matrix, n, m);       
        printArr(matrix, n, m);
    }


    if (a == 'd') {                 
        sortDown(matrix, n, m); 
        printArr(matrix, n, m);
    }
}