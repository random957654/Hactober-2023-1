#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string& inputFileName, const std::string& outputFileName, int key) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    char ch;
    while (inputFile.get(ch)) {
        ch = ch + key;
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(const std::string& inputFileName, const std::string& outputFileName, int key) {
    encryptFile(inputFileName, outputFileName, -key); // Decryption is the same as encryption with the negative key
}

int main() {
    std::string inputFileName, outputFileName;
    int key;

    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;

    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    std::cout << "Enter encryption key: ";
    std::cin >> key;

    encryptFile(inputFileName, outputFileName, key);
    std::cout << "File encrypted successfully." << std::endl;

    decryptFile(outputFileName, "decrypted_" + outputFileName, key);
    std::cout << "File decrypted successfully." << std::endl;

    return 0;
}
