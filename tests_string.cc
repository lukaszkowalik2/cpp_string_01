#include <chrono>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include "string_01.h"

using namespace string_toys;

namespace Color
{
enum Code
{
    FG_RED = 31,
    FG_GREEN = 32,
    FG_BLUE = 34,
    FG_DEFAULT = 39,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_BLUE = 44,
    BG_DEFAULT = 49
};

class Modifier
{
    Code code;

  public:
    explicit Modifier(Code pCode)
        : code(pCode)
    {
    }
    friend std::ostream& operator<<(std::ostream& os, const Modifier& mod) { return os << "\033[" << mod.code << "m"; }
};
}  // namespace Color

template<class F, class R, class... I>
auto verify(const char* fname, F func, R ref_value, I... inputs) -> bool
{
    auto out_value = func(inputs...);

    static Color::Modifier green(Color::FG_GREEN);
    static Color::Modifier red(Color::FG_RED);
    static Color::Modifier def(Color::FG_DEFAULT);

    std::cout << fname << " : ";
    if (out_value != ref_value) {
        std::cout << red << "Test failed" << def;
    } else {
        std::cout << green << "Test passed" << def;
    }
    std::cout << " for INPUT: ";
    ((std::cout << ' ' << inputs), ...) << "  OUTPUT: " << out_value << "  EXPECTED: " << ref_value << '\n';

    return true;
}

auto main() -> int
{
    {
        std::vector<std::pair<std::string, std::string>> data_reverse = {{"abc", "cba"},
                                                                         {"xZz qwe", "ewq zZx"},
                                                                         {"xZz\nqwe", "ewq\nzZx"},
                                                                         {"xZz\tqwe", "ewq\tzZx"},
                                                                         {"Litwo, ojczyzno moja", "ajom onzyzcjo ,owtiL"},
                                                                         {"łabudibu łabidudaj ą ę ó ń", "ń ó ę ą jadudibał ubidubał"}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_reverse) {
            verify("reverse", reverse, data.second, data.first);
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }

    // ---
    {
        std::vector<std::pair<std::string, std::string>> data_first_to_upper = {
            {"abc", "Abc"},
            {"xZz qwe", "XZz Qwe"},
            {"xZz\nqwe", "XZz\nQwe"},
            {"xZz\tqwe", "XZz\tQwe"},
            {"Litwo, ojczyzno moja", "Litwo, Ojczyzno Moja"},
            {"bielsko-biała", "Bielsko-Biała"},
            {"raz.dwa,trzy;cztery", "Raz.Dwa,Trzy;Cztery"},
            {"łabudibu łabidudaj ą ę ó ń", "Łabudibu Łabidudaj Ą Ę Ó Ń"},
            {"997zgłoś się", "997zgłoś Się"}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_first_to_upper) {
            verify("first_to_upper", first_to_upper, data.second, data.first);
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }

    // ---
    {
        std::vector<std::pair<std::string, int>> data_count_vowels = {{"abc", 1},
                                                                      {"xZz", 0},
                                                                      {"xZz\nqwe", 1},
                                                                      {"Litwo, ojczyzno moja", 7},
                                                                      {"łabudibu łabidudaj ą ę ó ń", 11},
                                                                      {"ŁABUDIBU ŁABIDUDAJ Ą Ę Ó Ń", 11}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_count_vowels) {
            verify("count_vowels", count_vowels, data.second, data.first);
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }

    // ---
    {
        std::vector<std::pair<std::string, int>> data_sum_digits = {{"abc", 0},
                                                                    {"xZz", 0},
                                                                    {"Countdown: 3... 2... 1... Start!", 6},
                                                                    {"First prime numbers are: 3, 5, 7, 11, 13", 21},
                                                                    {"Fiłst płime numbełs are: 3, 5, 7, 11, 13", 21}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_sum_digits) {
            verify("sum_digits", sum_digits, data.second, data.first);
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }

    // ---
    {
        std::vector<std::tuple<std::string, std::string, int>> data_search_substr = {{"abc", "d", -1},
                                                                                     {"xZz", "z", 2},
                                                                                     {"Litwo, ojczyzno moja", "ojcz", 7},
                                                                                     {"First prime numbers are: 3, 5, 7, 11, 13", "3", 25},
                                                                                     {"łabudibu łabidudaj ą ę ó ń", "łabi", 9},
                                                                                     {"łabudibu łabidudaj ą ę ó ń", "abi", 10},
                                                                                     {"abcde", "abcdefgh", -1}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_search_substr) {
            verify("search_substr", search_substr, std::get<2>(data), std::get<0>(data), std::get<1>(data));
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }

    // ---
    {
        std::vector<std::tuple<const char*, const char*, int>> data_custom_serach = {{"abc", "d", -1},
                                                                                     {"xZz", "z", 2},
                                                                                     {"Litwo, ojczyzno moja", "ojcz", 7},
                                                                                     {"First prime numbers are: 3, 5, 7, 11, 13", "3", 25},
                                                                                     {"łabudibu łabidudaj ą ę ó ń", "łabi", 9},
                                                                                     {"łabudibu łabidudaj ą ę ó ń", "abi", 10}};

        const auto start {std::chrono::steady_clock::now()};

        for (const auto& data : data_custom_serach) {
            verify("custom_serach", custom_serach, std::get<2>(data), std::get<0>(data), std::get<1>(data));
        }

        const auto end {std::chrono::steady_clock::now()};
        const std::chrono::duration<double> elapsed_seconds {end - start};
        std::cout << "\nElapsed time: " << elapsed_seconds.count() << '\n';
    }
    return 0;
}
