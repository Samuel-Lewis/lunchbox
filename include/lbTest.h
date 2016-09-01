// ===========================//
//      Super Test Script     //
//   Sam Lewis | 16 Aug 2016  //
// ===========================//

#ifndef LB_TEST_H
#define LB_TEST_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

// Vector printing
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << "{";
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i < vec.size()-1) {
            os << ", ";
        }
    }
    os << "}";

    return os;
}

class lbTest {
public:
    static void TEST_GROUP(std::string title) {
        // End any previous tests
        TEST_GROUP_END();
        _current = new Res(title);

        // Title printing
        std::cerr << "\n\033[1m[[ " << title << " ]]\033[0m" << std::endl;
    }

    // Test for non vector types
    template <typename T>
    static void TEST(T const& expected, T const& actual) {
        _current->numTests++;
        std::cerr << " \033[34m"<<_current->numTests << ".\033[0m ";

        if (actual == expected) {
            std::cerr << "\033[32;1mPASSED\033[0m" << std::endl;
            _current->numPassed++;
        } else {
            std::cerr << "\033[31;1mFAILED\033[0m" << std::endl;
            std::cerr << "\tExpect:\t" << expected << std::endl;
            std::cerr << "\tActual:\t" << actual << std::endl;
        }
    }

    // Test for vector types
    template <typename T, typename A>
    static void TEST(std::vector<T,A> const& expected, std::vector<T,A> const& actual) {
        _current->numTests++;
        std::cerr << " \033[34m"<<_current->numTests << ".\033[0m ";

        if (actual == expected) {
            std::cerr << "\033[32;1mPASSED\033[0m" << std::endl;
            _current->numPassed++;
        } else {
            std::cerr << " \033[31;1mFAILED\033[0m" << std::endl;
            std::cerr << "\tExpect:\t" << expected << std::endl;
            std::cerr << "\tActual:\t" << actual << std::endl;
        }
    }

    // End single test group
    static void TEST_GROUP_END() {
        // Close prev group
        if (_current->numTests == 0 || _current->title == "") {
            return;
        }

        // Pretty print of just ended test
        float perc = 100* ((float)_current->numPassed / (float)_current->numTests);
        std::cerr.precision(4);
        std::cerr << " > \033[1m" << _current->numPassed << " / " << _current->numTests << " :: \033[33;1m" << perc << "%\033[0m" << std::endl;

        // Store for final printing
        _totalResults.push_back(_current);
    }

    // End all groups
    static void TEST_END() {
        TEST_GROUP_END();

        int totalTests = 0;
        int totalPassed = 0;

        // Work out max spacing limit thing
        int maxW = 0;
        for (size_t i = 0; i < _totalResults.size(); i++) {
            maxW = maxW < (int)_totalResults[i]->title.size() ? (int)_totalResults[i]->title.size() : maxW;
        }

        // Title
        std::cerr << std::endl;
        std::cerr << "\033[35m" << std::string(maxW+27,'=') << "\033[0m" <<  std::endl;
        std::cerr << std::string(((maxW+25)/2 - 4), ' ') << "\033[1mEND TESTS\033[0m" << std::endl;
        std::cerr << "\033[35m" << std::string(maxW+27,'=') << "\033[0m" <<  std::endl;

        // Print out all individual results
        for (size_t i = 0; i < _totalResults.size(); i++) {
            totalTests += _totalResults[i]->numTests;
            totalPassed += _totalResults[i]->numPassed;

            int perc = 100* ((float)_totalResults[i]->numPassed / (float)_totalResults[i]->numTests);
            std::string percS = std::to_string(perc) + "%";
            std::string frac = std::to_string(_totalResults[i]->numPassed) + "/" + std::to_string(_totalResults[i]->numTests);

            std::cerr << " ";
            std::cerr << std::left << std::setw(maxW+4) << _totalResults[i]->title;
            std::cerr << std::left << std::setw(8) << frac;
            std::cerr << std::left << std::setw(4) << percS;

            if (perc == 100) {
                std::cerr << "\t\033[32;1mPASSED\033[0m";
            } else {
                std::cerr << "\t\033[31;1mFAILED\033[0m";
            }
            std::cerr << std::endl;
        }

        std::cerr << "\033[35m" << std::string(maxW+27,'-') << "\033[0m" <<  std::endl;

        // Calculate and print total
        int perc = 100* ((float)totalPassed / (float)totalTests);
        std::string percS = std::to_string(perc) + "%";
        std::string frac = std::to_string(totalPassed) + "/" + std::to_string(totalTests);

        std::cerr << " ";
        std::cerr << std::left << std::setw(maxW+8) << "\033[1mTOTAL";
        std::cerr << std::left << std::setw(8) << frac;
        std::cerr << std::left << std::setw(4) << percS;

        if (perc == 100) {
            std::cerr << "\t\033[32;1mPASSED\033[0m";
        } else {
            std::cerr << "\t\033[31;1mFAILED\033[0m";
        }
        std::cerr << "\033[0m" << std::endl;
        std::cerr << "\033[35m" << std::string(maxW+27,'=') << "\033[0m" <<  std::endl;
    }

private:
    lbTest() {}
    ~lbTest() {}

    struct Res {
        int numTests;
        int numPassed;
        std::string title;

        Res(std::string t) : numTests(0), numPassed(0), title(t) {}
    };

    static Res* _current;
    static std::vector<Res*> _totalResults;

};

// Always starts with a blank, that is then ignored later.
lbTest::Res* lbTest::_current = new Res("");
std::vector<lbTest::Res*> lbTest::_totalResults;


#endif // LB_TEST_H
