#include <iostream>

#include <vvm/vvm.hpp>
#include <vvm/matrix_tfm.hpp>
#include <vvm/string.hpp>


using namespace vvm;

int main() {
    
    std::cout << "Test printing vectors.\n";
    std::cout << vvm::to_string(v2f(0, 1)) << "\n";
    std::cout << vvm::to_string(v3f(2, 3, 4)) << "\n";
    std::cout << vvm::to_string(v4f(5, 6, 7, 8)) << "\n";

    std::cout << "Test printing matrices.\n";
    std::cout << vvm::to_string(m2f(0, 1, 2, 3)) << "\n";
    std::cout << vvm::to_string(m3f(1, 2, 3, 4, 5, 6, 7, 8, 9)) << "\n";
    std::cout << vvm::to_string(m4f(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)) << "\n";

    std::cout << "Test printing matrices constructed from columns.\n";
    std::cout << vvm::to_string(m2f({0, 1}, {2, 3})) << "\n";
    std::cout << vvm::to_string(m3f({1, 2, 3}, {4, 5, 6}, {7, 8, 9})) << "\n";
    std::cout << vvm::to_string(m4f({1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16})) << "\n";

    std::cout << "Test identity matrices.\n";
    std::cout << vvm::to_string(identity<m2f>()) << "\n";
    std::cout << vvm::to_string(identity<m3f>()) << "\n";
    std::cout << vvm::to_string(identity<m4f>()) << "\n";

    std::cout << "Test transformations.\n";
    std::cout << vvm::to_string(translate(v3d(1, 2, 3))) << "\n";

    std::cout << std::endl;

    return 0;
}