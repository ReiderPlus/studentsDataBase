#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для подсчёта суммы средних баллов
double sumGPA(const std::vector<Student>& database) {
    double total = 0.0;
    for (const Student& student : database) {
        total += student.gpa;
    }
    return total;
}

// Функция для тестирования
void runTests() {
    std::cout << "ЗАПУСК ТЕСТОВ\n";
    
    std::vector<Student> testDatabase;
    int passedTests = 0;
    int totalTests = 5;
    
    // Тест 1: Сумма GPA пустой базы данных
    {
        double result = sumGPA(testDatabase);
        if (std::abs(result - 0.0) < 0.001) {
            std::cout << "Тест 1 пройден: Сумма GPA пустой базы = 0\n";
            passedTests++;
        } else {
            std::cout << "Тест 1 не пройден: Сумма GPA пустой базы должна быть 0\n";
        }
    }
    
    // Тест 2: Сумма GPA одного студента
    {
        testDatabase.push_back({"Иван", 20, "Информатика", 3.5});
        double result = sumGPA(testDatabase);
        if (std::abs(result - 3.5) < 0.001) {
            std::cout << "Тест 2 пройден: Сумма GPA одного студента\n";
            passedTests++;
        } else {
            std::cout << "Тест 2 не пройден: Некорректная сумма GPA одного студента\n";
        }
    }
    
    // Тест 3: Сумма GPA нескольких студентов
    {
        testDatabase.push_back({"Мария", 21, "Математика", 4.0});
        testDatabase.push_back({"Петр", 22, "Физика", 3.8});
        double result = sumGPA(testDatabase);
        if (std::abs(result - 11.3) < 0.001) { // 3.5 + 4.0 + 3.8 = 11.3
            std::cout << "Тест 3 пройден: Сумма GPA нескольких студентов\n";
            passedTests++;
        } else {
            std::cout << "Тест 3 не пройден: Некорректная сумма GPA нескольких студентов\n";
        }
    }
    
    // Тест 4: Студент с нулевым GPA
    {
        testDatabase.push_back({"Анна", 19, "Химия", 0.0});
        double result = sumGPA(testDatabase);
        if (std::abs(result - 11.3) < 0.001) { // 0.0 не должен изменить сумму
            std::cout << "Тест 4 пройден: Студент с нулевым GPA\n";
            passedTests++;
        } else {
            std::cout << "Тест 4 не пройден: Некорректная обработка нулевого GPA\n";
        }
    }
    
    // Тест 5: Студент с высоким GPA
    {
        testDatabase.push_back({"Алексей", 23, "Биология", 3.0});
        double result = sumGPA(testDatabase);
        if (std::abs(result - 14.3) < 0.001) { // 11.3 + 3.0 = 14.3
            std::cout << "Тест 5 пройден: Студент с высоким GPA\n";
            passedTests++;
        } else {
            std::cout << "Тест 5 не пройден: Некорректная обработка высокого GPA\n";
        }
    }
    
    std::cout << "\nРЕЗУЛЬТАТЫ ТЕСТИРОВАНИЯ\n";
    std::cout << "Пройдено тестов: " << passedTests << " из " << totalTests << "\n";
    
    if (passedTests == totalTests) {
        std::cout << "Все тесты пройдены\n";
    } else {
        std::cout << "Некоторые тесты не пройдены\n";
    }
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Показать сумму средних баллов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                std::cout << "Сумма средних баллов: " << sumGPA(database) << "\n\n";
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
