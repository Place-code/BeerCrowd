#include <iostream>
#include <string>
#include <sstream>

std::string check (std::string students, std::string reports) {
    std::string rejected, student, report;
    int nclass = 0, attclass = 0;
    std::stringstream stok(students);
    std::stringstream rtok(reports);
    while (stok >> student && rtok >> report) {
        for (char ch : report) {
            if (ch != 'M')
                ++nclass;
            if (ch == 'P')
                ++attclass;
        }
        if ((float)attclass/nclass < 0.75) {
            rejected += student;
            rejected += ' ';
        }
        nclass = 0;
        attclass = 0;
    }
    if (!rejected.empty())
        rejected.pop_back();
    return rejected;
}

int main() {
    int cases, stulen;
    std::string students, reports;
    std::cin>>cases;
    std::cin.ignore();
    for (int i = 0; i < cases; ++i) {
        std::cin>>stulen;
        std::cin.ignore();
        std::getline(std::cin, students);
        std::getline(std::cin, reports);
        std::cout<<check(students, reports)<<"\n";
    }
    return 0;
}