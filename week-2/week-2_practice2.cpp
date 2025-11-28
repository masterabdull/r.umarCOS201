#include "iostream"

int main() {
    int A;
    std::cout << "Enter A:" << std::endl;
    std::cin >> A;
    int B;
    std::cout << "Enter B:" << std::endl;
    std::cin >> B;
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    int sum = A + B;
    std::cout<< "The sum is " << sum << std::endl;
    int diff = A - B;
     std::cout<< "The difference is " << diff << std::endl;
    int mult = A * B;
     std::cout<< "The product is " << mult << std::endl;

}