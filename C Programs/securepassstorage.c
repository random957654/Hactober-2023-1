#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void generate_salt(char salt[]) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 16; i++) {
        salt[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    salt[16] = '\0';
}

void hash_password(const char password[], const char salt[], char hashed_password[]) {
    char salted_password[128];
    sprintf(salted_password, "%s%s", password, salt);
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, salted_password, strlen(salted_password));
    SHA256_Final(hash, &sha256);
    
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&hashed_password[i * 2], "%02x", hash[i]);
    }
    hashed_password[64] = '\0';
}

int main() {
    char password[64];
    char salt[17];
    char hashed_password[65];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    generate_salt(salt);
    printf("Generated Salt: %s\n", salt);
    
    hash_password(password, salt, hashed_password);
    printf("Hashed Password: %s\n", hashed_password);
    
    return 0;
}
