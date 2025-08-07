#include <iostream>

int main() {
    std::string mystr;
    //std::cin >> mystr;
    std::getline(std::cin, mystr);
    std:: cout << mystr << std::endl;
    
    return 0;
}