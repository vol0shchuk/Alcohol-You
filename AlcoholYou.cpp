// AlcoholYou.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<typename T>
void printVector(const vector<T>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<double> numbers = { 1.5, 2.3, 4.6, 5.7, 6.2 };

    function<double(double)> addValue = [](double x) { return x + 10.0; };
    function<double(double)> multiplyBy = [](double x) { return x * 2.0; };
    function<double(double)> square = [](double x) { return x * x; };
    function<double(double)> reciprocal = [](double x) { return 1.0 / x; };

    cout << "Original list: ";
    printVector(numbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = addValue(numbers[i]);
    }
    cout << "After adding 10 to each element: ";
    printVector(numbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = multiplyBy(numbers[i]);
    }
    cout << "After multiplying each element by 2: ";
    printVector(numbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = square(numbers[i]);
    }
    cout << "After squaring each element: ";
    printVector(numbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        numbers[i] = reciprocal(numbers[i]);
    }
    cout << "After taking reciprocal of each element: ";
    printVector(numbers);

    double sum = 0.0;
    for (size_t i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    cout << "Sum of all elements: " << sum << endl;

    double average = sum / numbers.size();
    cout << "Average of all elements: " << average << endl;

    double max = numbers[0];
    double min = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    cout << "Maximum value in the list: " << max << endl;
    cout << "Minimum value in the list: " << min << endl;

    vector<double> filteredNumbers;
    for (size_t i = 0; i < numbers.size(); i++) {
        if ((int)numbers[i] % 2 == 0) {
            filteredNumbers.push_back(numbers[i]);
        }
    }
    cout << "Filtered list (even numbers only): ";
    printVector(filteredNumbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] > numbers[j]) {
                swap(numbers[i], numbers[j]);
            }
        }
    }
    cout << "Sorted list (ascending order): ";
    printVector(numbers);

    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] < numbers[j]) {
                swap(numbers[i], numbers[j]);
            }
        }
    }
    cout << "Sorted list (descending order): ";
    printVector(numbers);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
