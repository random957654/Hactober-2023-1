#include <iostream>
#include <cctype>

int myAtoi(const char* str) {
    int sign = 1;
    int result = 0;
    int i = 0;

    // Ignorer les espaces en début de chaîne
    while (std::isspace(str[i])) {
        i++;
    }

    // Gérer le signe positif ou négatif
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // Convertir les caractères en entier
    while (std::isdigit(str[i])) {
        // Vérifier le dépassement de capacité
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}

int main() {
    const char* str = "12345";
    int num = myAtoi(str);
    std::cout << "La conversion de la chaîne en entier donne : " << num << std::endl;

    return 0;
}
