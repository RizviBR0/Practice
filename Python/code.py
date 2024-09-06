import random
import string

uppercase_letter = list(string.ascii_uppercase)
lowercase_letter = list(string.ascii_lowercase)

letters = uppercase_letter + lowercase_letter
numbers = list(string.digits)
symbols = list(string.punctuation)

n_letter = int(input("Number of letter: "))
n_number = int(input("Number of number: "))
n_symbol = int(input("Number of symbol: "))

password_list = ""

for letter in range(n_letter):
    password_list += random.choice(letters)

for number in range(n_number):
    password_list += random.choice(numbers)

for symbol in range(n_symbol):
    password_list += random.choice(symbols)

password_list = list(password_list)
random.shuffle(password_list)

password = ""

for char in password_list:
    password += char

print(f"Your password is : {password}")