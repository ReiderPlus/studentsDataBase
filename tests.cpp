#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include "main.cpp"

// Объявляем структуру и функции из main.cpp
struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Объявляем функции из main.cpp
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
double sumGPAs(const std::vector<Student>& database);

// Вспомогательная функция для сравнения double с учетом погрешности
bool almostEqual(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

// Тестовая функция
void runTests() {
    std::cout << "Запуск тестов...\n";
    
    // Тест 1: Проверка суммы баллов на пустой базе
    std::vector<Student> emptyDB;
    assert(almostEqual(sumGPAs(emptyDB), 0.0));
    std::cout << "Тест 1 пройден: сумма баллов пустой базы = 0\n";
    
    // Тест 2: Проверка добавления студента
    std::vector<Student> testDB;
    Student testStudent{"Иван", 20, "Информатика", 4.5};
    testDB.push_back(testStudent);
    assert(testDB.size() == 1);
    std::cout << "Тест 2 пройден: студент добавлен в базу\n";
    
    // Тест 3: Проверка суммы баллов с одним студентом
    assert(almostEqual(sumGPAs(testDB), 4.5));
    std::cout << "Тест 3 пройден: сумма баллов одного студента = 4.5\n";
    
    // Тест 4: Проверка суммы баллов с несколькими студентами
    Student testStudent2{"Мария", 21, "Математика", 3.8};
    Student testStudent3{"Алексей", 22, "Физика", 4.2};
    testDB.push_back(testStudent2);
    testDB.push_back(testStudent3);
    assert(almostEqual(sumGPAs(testDB), 12.5)); // 4.5 + 3.8 + 4.2 = 12.5
    std::cout << "Тест 4 пройден: сумма баллов трех студентов = 12.5\n";
    
    // Тест 5: Проверка корректности данных студента
    assert(testDB[0].name == "Иван");
    assert(testDB[0].age == 20);
    assert(testDB[0].major == "Информатика");
    assert(almostEqual(testDB[0].gpa, 4.5));
    std::cout << "Тест 5 пройден: данные студента корректны\n";
    
    std::cout << "Все тесты пройдены успешно!\n";
}

int main() {
    runTests();
    return 0;
}
