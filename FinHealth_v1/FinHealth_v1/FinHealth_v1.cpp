#include <iostream>
#include <string>
#include <fstream>


int main()
{
    setlocale(LC_ALL, "RU");
    std::string line;
    std::string name_file = "";

    int income = 0;
    int bill = 0;
    int sum_income = 0;
    int sum_bill = 0;
    int profit = 0;
    int sum_profit = 0;
    float i = 0.10; // процент вклада
    int n = 3; // количество лет (срок вклада)

    int month = 1;

    while (name_file != "exit") {
        std::cout << "Start the FinHealth v1" << std::endl;
        std::cout << "Enter file data in format [name.extension] or 'exit' to close the program: ";

        std::cin >> name_file;
        std::ifstream in_data(name_file);
        if (in_data.is_open()) {

            std::cout << "   Monthly income: " << "\t" << "Monthly bill: " << std::endl;
            while (std::getline(in_data, line)) {

                income = stoi(line.substr(0, line.find(",")));
                bill = stoi(line.substr(line.find(",") + 1, line.size() - 1));

                std::cout << month << ". " << income << "\t\t" << bill << std::endl;
                profit += income - bill;
                sum_income += income;
                sum_bill += bill;

                month++;
            }
            std::cout << "\n" << "Profit by year: " << profit << "\n" << "Income by year: " << sum_income << "\n" << "Bill by year: " << sum_bill << "\n\n";

            sum_profit = profit * pow((1.0 + i), n);
            std::cout << "Deposit by sum: " << profit << " for " << n << " years at " << i * 100 << "%" << "\n"
                << "Profit by deposit: " << sum_profit - profit << std::endl;

            in_data.close();

        }
        return 0;
    }

}

