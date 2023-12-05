#include <iostream>
 #include <stdexcept>
 class Student {
 private:
    std::string name;
    int examResult;
 public:
    Student(const std::string& studentName) : name(studentName), examResult(0) 
{}
    void setExamResult(int result) {
        if (result != 1 && result != 2) {
            throw std::invalid_argument("Invalid exam result. Use 1 for pass, 2 
for fail.");
        }
        examResult = result;
    }
    int getExamResult() const {
        return examResult;
    }
    const std::string& getName() const {
        return name;
    }
 };
 class ExamAnalyzer {
 private:
    Student students[10];
    int passCount;
    int failCount;
 public:
    ExamAnalyzer() : passCount(0), failCount(0) {}
    void inputResults() {
        for (int i = 0; i < 10; ++i) {
            std::cout << "Enter result (1 for pass, 2 for fail) for student " <<
 students[i].getName() << ": ";
            int result;
            std::cin >> result;
            try {
                students[i].setExamResult(result);
                updateResultCount(result);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                --i;  // Re-enter the result for the current student
            }
        }
    }
    void displaySummary() const {
        std::cout << "\nSummary:\n";
        std::cout << "Number of students who passed: " << passCount << 
std::endl;
        std::cout << "Number of students who failed: " << failCount << 
std::endl;
        if (passCount > 8) {
            std::cout << "Raise tuition." << std::endl;
    }
        }
 private:
    void updateResultCount(int result) {
        if (result == 1) {
            ++passCount;
        } else {
            ++failCount;
        }
    }
 };
 int main() {
    ExamAnalyzer analyzer;
    // Input exam results for each student
    analyzer.inputResults();
    // Display the summary
    analyzer.displaySummary();
    return 0;
 }
