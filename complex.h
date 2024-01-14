#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>

// Эпсилон для сравнения вещественных чисел
const double epsilon = 1e-10;

class Complex {
private:
    double real;
    double imaginary;

public:
    // Конструктор по умолчанию
    Complex() : real(0.0), imaginary(0.0) {}

    // Конструктор с параметрами
    Complex(double re, double im) : real(re), imaginary(im) {}

    // Методы получения и установки действительной и мнимой частей
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    void setReal(double re) {
        real = re;
    }

    void setImaginary(double im) {
        imaginary = im;
    }

    // Методы сложения, вычитания, умножения и деления
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex multiply(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    Complex divide(const Complex& other) const {
        assert(fabs(other.real) > epsilon || fabs(other.imaginary) > epsilon);
        double divisor = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (real * other.real + imaginary * other.imaginary) / divisor;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / divisor;
        return Complex(newReal, newImaginary);
    }

    // Метод сравнения комплексных чисел
    bool equals(const Complex& other) const {
        return (real == other.real) && (imaginary == other.imaginary);
    }

    // Метод возведения в степень (целочисленной)
    Complex power(int exponent) const {
        assert(exponent >= 0);  // Предполагаем, что степень неотрицательная
        Complex result(1, 0);
        for (int i = 0; i < exponent; ++i) {
            result = result.multiply(*this);
        }
        return result;
    }

    // Метод вычисления модуля
    double modulus() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Метод форматного вывода в консоль
    void display() const {
        std::cout << std::fixed << std::setprecision(2) << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }
};

