# Sensor_data_analysis
# Лабораторная №2-3 (Одномерные динамические массивы и указатели)
ФИО: Картохина Виктория Алексеевна 

Группа: СКБ252


## Цель работы
1. Научиться работать с динамическими массивами (new, delete);
2. Освоить передачу массивов по указателю в функции;
3. Научиться обрабатывать массивы через арифметику указателей (*(p+i));
4. Осознать, как управлять памятью вручную без STL.

##  Задание
**"Анализ данных сенсора"**

Вы инженер, собирающий показания датчика температуры. Датчик записывает N измерений за день (в диапазоне от -50 до +50°C).

**Программа должна:**
- Считывать все значения в динамический массив;
- Анализировать данные (среднее, минимум, максимум, выбросы);
- Создавать новый динамический массив, содержащий только значения, превышающие среднее.

##  Требования к программе

1. Ввод количества измерений (int n), динамическое выделение памяти под `float* data = new float[n]`;
2. Ввод всех n значений;
3. Реализовать функции:
   - `void inputData(float* p, int n);`
   - `float average(const float* p, int n);`
   - `float minValue(const float* p, int n);`
   - `float maxValue(const float* p, int n);`
   - `float* filterAboveAverage(float* p, int n, int& newCount);`
4. Вывести:
   - Среднее, минимум, максимум;
   - Значения, превышающие среднее, в отдельном массиве.
5. Всё через указатели и арифметику указателей (без data[i]).
6. После завершения работы освободить память (delete[]).

##  Описание алгоритма

### Основные функции:

1. **inputData()** - запрашивает и считывает значения в массив через указатели
2. **printData()** - выводит элементы массива через арифметику указателей
3. **average()** - вычисляет среднее арифметическое всех элементов
4. **minValue()** - находит минимальное значение в массиве
5. **maxValue()** - находит максимальное значение в массиве
6. **filterAboveAverage()** - создает новый массив с элементами выше среднего


##  Код программы

```cpp
#include <iostream>

using namespace std;

void inputData(float* p, int n){
    cout << "Введите значения: ";
    for (int i = 0; i < n; i++){
        cin >> *(p+i);
    }
}
void printData(float* p, int n){
    cout << "Значения в массиве: ";
    for (int i = 0; i < n; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}
float average(const float* p, int n){
    float sum = 0;
     for (int i = 0; i < n; i++){
        sum += *(p+i);
    }
    return sum / n;
}
float minValue(const float* p, int n){
    float min = *p;
     for (int i = 0; i < n; i++){
        if(*(p+i) < min){
            min = *(p+i);
        }
    }
    return min;
}
float maxValue(const float* p, int n){
    float max = *p;
     for (int i = 0; i < n; i++){
        if(*(p+i) > max){
            max = *(p+i);
        }
    }
    return max;
}

float* filterAboveAverage(float* p, int n, int& newCount){
    float av = average(p, n);
    newCount = 0;
    
    for (int i = 0; i < n; i++){
       if(*(p+i) > av){
            newCount++;
       }
    }

    float* filtered = new float[newCount];
    int ind = 0;
    for (int i = 0; i < n; i++){
        if(*(p+i) > av){
            *(filtered + ind) = *(p+i);
            ind++;
        }
    }
    return filtered;
}
int main() {
    cout << "=== Анализ сенсора ===" << endl;
    cout << "Введите количество измерений: ";
    int n;
    cin >> n;
    float* data = new float[n];
  
    inputData(data, n);
    printData(data, n);
    cout << "Среднее значение: " << average(data, n) << endl;
    cout << "Минимальное значение: " << minValue(data, n) << endl;
    cout << "Максимальное значение: " << maxValue(data, n) << endl;
    int newCount;
    float* filtered = filterAboveAverage(data, n, newCount);
    printData(filtered, newCount);

    delete[] data;
    delete[] filtered;
    return 0;
}
```


##  Cсылка на репризиторий
Cсылка на репризиторий: https://github.com/kartokhina/Sensor_data_analysis

##  Вывод
В ходе выполнения лабораторной работы написала программу на C++ для анализа данных сенсора температуры. Вспомнила синтаксис C++, освоила работу с динамическими массивами и арифметикой указателей. 
