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