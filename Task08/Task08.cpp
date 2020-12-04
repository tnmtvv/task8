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




void quicksort(int start, int finish, int arr[], int& NoS, int& NoC) {

    if (start >= finish)
        return;
    int p_indx = start + abs(finish - start) / 2;
    int piv = arr[p_indx];
    printf_s("Опопрный элемент: %d\n", piv);

    int i = start;
    int j = finish;

    
    do
    {
        while (i != p_indx && arr[i] < piv) {
            if (i < j)
            {
                printf_s("Сравниваем %d %d\n", arr[i], piv);
                NoC++;
            }
            i++;
           
        }
        if (i != p_indx && i < j)
        {
            
                printf_s("Сравниваем %d %d\n", arr[i], piv);
                NoC++;
            
        }

        while (j != p_indx && arr[j] > piv) {
            if (i < j)
            {
                printf_s("Сравниваем %d %d\n", arr[j], piv);
                NoC++;
            }
            j--;

        }
        if (j != p_indx && i < j)
        {
            printf_s("Сравниваем %d %d\n", arr[j], piv);
            NoC++;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);


            if (i != j) 
            {
                NoS++;
                printf_s("Переставляем %d %d\n", arr[i], arr[j]);

            }
            i++;
            j--;
           
        }
    } while (i <= j);

    if (i < finish) {
        printf_s("рекурсивный вызов от %d до %d\n", i, finish);

        quicksort(i, finish, arr, NoS, NoC);

    }

    if (j > start) {
        printf_s("рекурсивный вызов от %d до %d\n", start, j);

        quicksort(start, j, arr, NoS, NoC);


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
                
            }
            NoC++;

        }
        if (arr[j] > min)
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


    
    
    int iter = 5;
    
    while (iter != 0) {
        int n;

        printf_s("Введите количество эементов\n");
        scanf_s("%d", &n);


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

        int NoS = 0; //swaps
        int NoC = 0; //comps

        printf("\n");
        bubblesort(arr, n);
        printf("\n");
        choiceSort(arr1, n);
        printf("\n");
        quicksort(0, n-1, arr2, NoS, NoC);

        printf("\nQuicksort\n");

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
