// Task08.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

void output(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf_s("%d ", arr[i]);
    }
    printf("\n");
}

void copy(int arr[], int* arr1, int n) {
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
}

void swap(int &a, int &b) {
    int t;

    t = a;
    a = b;
    b = t;
}


void quicksort(int start, int finish, int arr[], int n, int& NoS, int& NoC) {

    int piv = arr[start + abs(finish - start) / 2];

    int i = start;
    int j = finish;

    while (i < j)
    {
        while (arr[i] < piv) {
            NoC++;
            i++;
        }


        while (arr[j] > piv) {
            NoC++;
            j--;
        }


        if (i < j) 
        {
            swap(arr[i], arr[j]);
            NoS++;
            i++;
            j--;
        }

        else if (i == j) {
            i++;
            j--;
        }

    } 

    if (i < finish) {
        quicksort(i, finish, arr,n, NoS, NoC);

    }

    if (j > start) {
        quicksort(start, j, arr,n, NoS, NoC);

    }

   
    

}

void betterbubblesort(int arr[], int n) {

    int NoC = 0;        
    int NoM = 0;       

    int Mooves = 5; // заводим переменную, отвечающую за перестаановки в цикле

    while (Mooves)
    {
        Mooves = 0;
        for (int i = 0; i < n-1; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]); //если в цикле нет перестановок, мы закончим сортировку
                NoM++;
                Mooves = 5;
            }
            NoC++;
        }
    }




}

void choiceSort(int arr[], int n) {
    int NoS = 0;
    int NoC = 0;

    int min;
    for (int j = 0; j < n; j++) {
        min = arr[j];
        int indmin = j;
        for (int i = j+1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                indmin = i;
                NoC++;
                
            }
            
        }
        if (arr[j] != min)
        {
            swap(arr[indmin], arr[j]);
            NoS++;
        }
    }
    printf("Сортировка выбором\n");

    printf("Отсортированный массив: ");
    output(arr, n);
    printf("Количество перестановок: ");
    printf("%d\n", NoS);
    printf("Количество сравнений: ");
    printf("%d\n", NoC);

}



void bubblesort(int arr[], int n) {
    int swaps = 0; //перестановки
    int comp = 0; //сравнения
    int j = 0;
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n - 1 -j; i++) {
            comp++;
            if (arr[i] > arr[i + 1]) {
                swaps++;
                swap(arr[i], arr[i + 1]);
            }
            
        }
        
        j++;
    }

    printf("Пузырек\n");
    printf("Отсортированный массив: ");
    output(arr, n);
    printf("Количество перестановок: ");
    printf("%d\n", swaps);
    printf("Количество сравнений: ");
    printf("%d\n", comp);

}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const int n = 5;
    
    int iter = 5;
    
    while (iter != 0) {
        int* arr = (int*)malloc(n * sizeof(int));
        int* arr1 = (int*)malloc(n * sizeof(int));
        int* arr2 = (int*)malloc(n * sizeof(int));


        for (int i = 0; i < n; i++) {
            printf("arr[%i] = ", i);
            scanf_s("%i", &arr[i]);


        }

        printf_s("Исходный массив\n");
        output(arr, n);

        copy(arr, arr1, n);
        copy(arr, arr2, n);

        int NoS = 0;
        int NoC = 0;

        printf("\n");
        bubblesort(arr, n);
        printf("\n");
        choiceSort(arr1, n);
        printf("\n");
        quicksort(0, n - 1, arr2, n, NoS, NoC);

        printf("Quicksort\n");

        printf("Отсортированный массив: ");
        output(arr2, n);
        printf("Количество перестановок: ");
        printf("%d\n", NoS);
        printf("Количество сравнений: ");
        printf("%d\n", NoC);



        printf("\nпродолжить - 1, выйти - 0\n");
        scanf_s("%d", &iter);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
