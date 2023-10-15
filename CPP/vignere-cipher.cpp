#include <iostream>
#include <string>
#include <cassert>

/** \namespace ciphers
 * \brief Algorithms for encryption and decryption
 */
namespace ciphers {
    /** \namespace vigenere
     * \brief Functions for [vigenère cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) algorithm.
     */
    namespace vigenere {   
        namespace {
            /**
             * This function finds character for given value (i.e.A-Z)
             * @param x value for which we want character 
             * @return  corresponding character for perticular value
             */        
            inline char get_char(const int x) {
                // By adding 65 we are scaling 0-25 to 65-90. 
                // Which are in fact ASCII values of A-Z. 
                return char(x + 65); 
            }
            /**
             * This function finds value for given character (i.e.0-25)
             * @param c character for which we want value
             * @return returns corresponding value for perticular character
             */  
            inline int get_value(const char c) {
                // A-Z have ASCII values in range 65-90.
                // Hence subtracting 65 will scale them to 0-25.
                return int(c - 65);
            }
        } // Unnamed namespace
        /**
         * Encrypt given text using vigenere cipher.
         * @param text text to be encrypted
         * @param key to be used for encryption
         * @return new encrypted text
         */
        std::string encrypt (const std::string &text, const std::string &key) {
            std::string encrypted_text = ""; // Empty string to store encrypted text
            // Going through each character of text and key
            // Note that key is visited in circular way hence  j = (j + 1) % |key|
            for(size_t i = 0, j = 0; i < text.length(); i++, j = (j + 1) % key.length()) {
                int place_value_text = get_value(text[i]); // Getting value of character in text
                int place_value_key = get_value(key[j]); // Getting value of character in key
                place_value_text = (place_value_text + place_value_key) % 26; // Applying encryption
                char encrypted_char = get_char(place_value_text); // Getting new character from encrypted value
                encrypted_text += encrypted_char; // Appending encrypted character
            }
            return encrypted_text; // Returning encrypted text
        }
        /**
         * Decrypt given text using vigenere cipher.
         * @param text text to be decrypted
         * @param key key to be used for decryption
         * @return new decrypted text
         */        
        std::string decrypt (const std::string &text, const std::string &key) {
            // Going through each character of text and key
            // Note that key is visited in circular way hence  j = (j + 1) % |key|
            std::string decrypted_text = ""; // Empty string to store decrypted text
            for(size_t i = 0, j = 0; i < text.length(); i++, j = (j + 1) % key.length()) {
                int place_value_text = get_value(text[i]); // Getting value of character in text
                int place_value_key = get_value(key[j]); // Getting value of character in key
                place_value_text = (place_value_text - place_value_key + 26) % 26; // Applying decryption
                char decrypted_char = get_char(place_value_text); // Getting new character from decrypted value
                decrypted_text += decrypted_char; // Appending decrypted character
            }        
            return decrypted_text; // Returning decrypted text
        }
    } // namespace vigenere
} // namespace ciphers
