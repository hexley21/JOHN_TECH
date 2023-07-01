#include <string>
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

// Create a Rectangle class with the following specifications:
class Rectangle {
    private:
        // The class should have private member variables for the length and width of the rectangle.
        int length;
        int width;

        // Implement a private method that generates random values for the length and width using a random number generator.
        void fillValues() {
            length = rand() % 101;
            width = rand() % 101;
        }
        // Implement a private method that calculates the area of the rectangle.
        int calculateArea() {
            return length * width;
        }
    public:
        // Implement a constructor that takes two arguments and initializes the length and width of the rectangle.
        Rectangle(int length, int width) {
            this->length = length;
            this->width = width;
        }

        Rectangle() {
            fillValues();
        }
        // Implement a public method that returns the area of the rectangle.
        int getArea() {
            return calculateArea();
        }
        // Implement a public method that prints the dimensions (length and width) of the rectangle.
        void printDimensions() {
            cout << "The dimensions of this rectangle: " << length << "x" << width << endl;
        }
        // Implement a public method that compares two rectangles and checks if they have the same dimensions.
        bool compareRectangle(Rectangle &other) {
            printDimensions();
            other.printDimensions();
            bool result = ((length == other.length) && (width == other.width));
            if (result){
                cout << "The rectangles are the same" << endl;
            } else {
                cout << "The rectangles are not the same" << endl;
            }
            return result;
        }

        bool operator<(Rectangle& other) {
            return getArea() < other.getArea();
        }
};

int main() {
    srand(time(NULL));
    static const int SIZE = 5;
    // In the main function, create an array of Rectangle objects using the constructor and fill it with random dimensions.
    Rectangle rectArray[SIZE] = {Rectangle()};

    // Print the dimensions of each rectangle in the array.
    // Find the rectangle with the largest area and print its dimensions.
    // Calculate the total area of all rectangles and print the result.

    for (int i = 0; i < SIZE; i++)
    {
        rectArray[i].printDimensions();
    }
    sort(rectArray, rectArray + SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        rectArray[i].printDimensions();
    }

    int maxArea = 0;
    int maxPos = 0;
    int areaSum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        rectArray[i].printDimensions();

        int area = rectArray[i].getArea();
        areaSum += area;
        if (area > maxArea)
        {
            maxArea = area;
            maxPos = i;
        }
    }

    cout << endl << "The rectangle with the biggest area is at position [" << maxPos << "] with dimensions:" << endl;
    rectArray[maxPos].printDimensions();

    cout << endl << "The sum of areas is: " << areaSum << endl << endl;

    // Calculate the cubic root of the average area of all rectangles and print the result.
    cout << "Cubic root of the average area of all rectangles: " << pow(areaSum / SIZE, 1.0/3.0) << endl;

    
    return 0;
}
// Sort the array of rectangles based on their areas in ascending order. -

// Print the dimensions of each rectangle after sorting. -
