#include "function.h"
#include "functionHelp.h"


    int main() {
        int index;
        while (true) {
            printList();
            std::cout << "1. Тест перегрузки оператора new\n";
            std::cout << "2. Удалить последнюю строку (с перегруженным оператором delete)\n";
            std::cout << "3. Удалить строку по индексу\n";
            std::cout << "4. Вывести список\n";
            std::cout << "5. Тест перегрузки оператора +\n";
            std::cout << "6. Тест перегрузки оператора +=\n";
            std::cout << "7. Тест перегрузки оператора -\n";
            std::cout << "8. Тест перегрузки оператора -=\n";
            std::cout << "9. Тест перегрузки оператора *\n";
            std::cout << "10. Тест перегрузки оператора *=\n";
            std::cout << "11. Тест перегрузки оператора =\n";
            std::cout << "12. Тест перегрузки оператора ==\n";
            std::cout << "13. Тест перегрузки оператора >\n";
            std::cout << "14. Тест перегрузки оператора <\n";
            std::cout << "15. Тест перегрузки оператора []\n";
            std::cout << "16. Выход\n";
            std::cout << "Выберите действие: ";
            std::cin >> index;
            std::cin.ignore();

            switch (index) {
            case 1:
            {
                new MyString();
                system("cls");
                break;
            }
            case 2:
            {
                deleteLastString();
                system("cls");
                break;
            }
            case 3:
            {
                system("cls");
                printList();
                deleteStringByIndex();
                system("cls");
                break;
            }
            case 4:
            {
                system("cls");
                break;
            }
            case 5: 
            {
                system("cls");
                printList();
                peregruzkaPlus();
                break;
            }
            case 6: 
            {
                system("cls");
                printList();
                peregruzkaPlusEquals();
                break;
            }
            case 7: 
            {
                system("cls");
                printList();
                peregruzkaMinus();
                break;
            }
            case 8: 
            {
                system("cls");
                printList();
                peregruzkaMinusEquals();
                break;
            }
            case 9:
            {
                system("cls");
                printList();
                overloadMultiply();
                break;
            }
            case 10:
            {
                system("cls");
                printList();
                overloadMultiplyExactly();
                break;
            }
            case 11:
            {
                system("cls");
                printList();
                assignmentOperatorOverload();
                break;
            }
            case 12:
            {
                system("cls");
                printList();
                overloadingTheEqualityOperator();
                break;
            }
            case 13:
            {
                system("cls");
                printList();
                operatorOverloadIsGreater();
                break;
            }
            case 14:
            {
                system("cls");
                printList();
                LessOperatorOverload();
                break;
            }
            case 15:
            {
                system("cls");
                peregruzSkobki();
                break;
            }
            case 16:
                return 0;
            default:
                std::cout << "Неверный выбор.\n";
            }
        }

        return 0;
    }
