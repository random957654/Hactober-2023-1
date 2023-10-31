# Morse code dictionary
morse_code_dict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.',
    'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---',
    'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--',
    'Z': '--..',
    '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
    '6': '-....', '7': '--...', '8': '---..', '9': '----.', '0': '-----',
    ' ': ' '
}

def text_to_morse(text):
    morse_code = ''
    for char in text.upper():
        if char in morse_code_dict:
            morse_code += morse_code_dict[char] + ' '
        else:
            morse_code += ' '
    return morse_code

def morse_to_text(morse_code):
    text = ''
    morse_code += ' '  # Add a space to ensure the last character is decoded
    morse_symbol = ''
    for symbol in morse_code:
        if symbol != ' ':
            morse_symbol += symbol
        else:
            if morse_symbol in morse_code_dict.values():
                text += [char for char, code in morse_code_dict.items() if code == morse_symbol][0]
            elif morse_symbol == '':
                text += ' '
            else:
                text += 'enter the correct morse code'  # Placeholder for unrecognized Morse code
            morse_symbol = ''
    return text

# Main program
print("Morse Code Translator")
choice = input("Choose an option:\n1. Text to Morse Code\n2. Morse Code to Text\n")

if choice == '1':
    text = input("Enter the text to translate to Morse code: ")
    morse_code = text_to_morse(text)
    print(f"Morse Code: {morse_code}")
elif choice == '2':
    morse_code = input("Enter the Morse code to translate to text: ")
    text = morse_to_text(morse_code)
    print(f"Text: {text}")
else:
    print("Invalid choice. Please enter 1 or 2 for the desired translation.")
