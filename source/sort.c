#include "../include/sort.h"

// 插入排序
void sort_Insertion(int arr[], int n)
{
    int i, j, tmp;
    for ( i = 1; i < n; i++)
    {
        tmp = arr[i];
        j = i - 1;
        while ( j >= 0 && tmp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
    }
}

void comparison_sort_Insertion()       // 测试插入排序性能
{
    static double run_time;

    for (int t = 0; t < 5; t++)
    {
        int *a = (int*) malloc(NUMBERS * sizeof (int));
        double temp_time;
        // 初始化随机数种子，使用更高分辨率的种子生成
        srand((unsigned)time(NULL) + t);

        for (int i = 0; i < NUMBERS; i++){
            a[i] = rand() % NUMBERS + 1;
        }
        //===============================================
        LARGE_INTEGER time_start;  // 开始时间
        LARGE_INTEGER time_over;   // 结束时间
        LARGE_INTEGER freq;        // 计时器频率
        // 获取计时器频率
        QueryPerformanceFrequency(&freq);
        double dqFreq = (double)freq.QuadPart;
        // 主循环外部进行一次计时器起始点的初始化
        QueryPerformanceCounter(&time_start);

        // 对数组进行排序
        sort_Insertion(a, NUMBERS);

        //=============================================
        QueryPerformanceCounter(&time_over);
        temp_time = (double)(time_over.QuadPart - time_start.QuadPart) / dqFreq;
        run_time += temp_time;
        free(a);
    }

    run_time = run_time / 5;
    printf("Average running time: %f s\n", run_time);
}

void quicksort(int *arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void comparison_sort_Quick()       // 测试快速排序性能
{
    static double run_time = 0;

    for (int t = 0; t < 5; t++)
    {
        int *a = (int *)malloc(NUMBERS * sizeof(int));
        double temp_time;
        // 初始化随机数种子，使用更高分辨率的种子生成
        srand((unsigned)time(NULL) + t);
        for (int i = 0; i < NUMBERS; i++){
            a[i] = rand() % NUMBERS + 1;
        }
        //===============================================
        LARGE_INTEGER time_start;  // 开始时间
        LARGE_INTEGER time_over;   // 结束时间
        LARGE_INTEGER freq;        // 计时器频率
        // 获取计时器频率
        QueryPerformanceFrequency(&freq);
        double dqFreq = (double)freq.QuadPart;
        // 主循环外部进行一次计时器起始点的初始化
        QueryPerformanceCounter(&time_start);

        // 对数组进行排序
        quicksort(a, 0, NUMBERS - 1);

        //=============================================
        QueryPerformanceCounter(&time_over);
        temp_time = (double)(time_over.QuadPart - time_start.QuadPart) / dqFreq;
        run_time += temp_time;

        free(a);
    }
    run_time = run_time / 5;
    printf("Average running time: %f s\n", run_time);
}