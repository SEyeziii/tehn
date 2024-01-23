#include "gtest/gtest.h" // Подключение библиотеки Google Test
#include "complex.h"     // Замените "complex.cpp" на путь к вашему заголовочному файлу

// Тесты для методов класса Complex

// Тест конструктора по умолчанию
TEST(ComplexTest, DefaultConstructor) {
Complex c;
EXPECT_EQ(c.getReal(), 0.0);
EXPECT_EQ(c.getImaginary(), 0.0);
}

// Тест конструктора с параметрами
TEST(ComplexTest, ParametrizedConstructor) {
Complex c(3.0, 4.0);
EXPECT_EQ(c.getReal(), 3.0);
EXPECT_EQ(c.getImaginary(), 4.0);
}

// Тест метода add
TEST(ComplexTest, AddMethod) {
Complex a(3.0, 4.0);
Complex b(1.0, 2.0);
Complex result = a.add(b);
EXPECT_EQ(result.getReal(), 4.0);
EXPECT_EQ(result.getImaginary(), 6.0);
}

// Тест метода subtract
TEST(ComplexTest, SubtractMethod) {
Complex a(3.0, 4.0);
Complex b(1.0, 2.0);
Complex result = a.subtract(b);
EXPECT_EQ(result.getReal(), 2.0);
EXPECT_EQ(result.getImaginary(), 2.0);
}

// Тест метода multiply
TEST(ComplexTest, MultiplyMethod) {
Complex a(3.0, 4.0);
Complex b(1.0, 2.0);
Complex result = a.multiply(b);
EXPECT_EQ(result.getReal(), -5.0);
EXPECT_EQ(result.getImaginary(), 10.0);
}

// Тест метода divide
TEST(ComplexTest, DivideMethod) {
Complex a(3.0, 4.0);
Complex b(1.0, 2.0);
Complex result = a.divide(b);
EXPECT_EQ(result.getReal(), 2.0);
EXPECT_EQ(result.getImaginary(), 0.0);
}

// Тест метода equals
TEST(ComplexTest, EqualsMethod) {
Complex a(3.0, 4.0);
Complex b(3.0, 4.0);
EXPECT_TRUE(a.equals(b));
}

// Тест метода power
TEST(ComplexTest, PowerMethod) {
Complex a(3.0, 4.0);
Complex result = a.power(2);
EXPECT_EQ(result.getReal(), -7.0);
EXPECT_EQ(result.getImaginary(), 24.0);
}

// Тест метода modulus
TEST(ComplexTest, ModulusMethod) {
Complex a(3.0, 4.0);
double result = a.modulus();
EXPECT_DOUBLE_EQ(result, 5.0);
}

// Пример теста метода display (вывода в консоль)
TEST(ComplexTest, DisplayMethod) {
testing::internal::CaptureStdout(); // Захват вывода в консоль
Complex a(3.0, 4.0);
a.display();
std::string output = testing::internal::GetCapturedStdout(); // Получение захваченного вывода
EXPECT_EQ(output, "3.00 + 4.00i\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
