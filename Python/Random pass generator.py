import random
import string

# creating a list of uppercase letters and lowercase letters
uppercase_letters = list(string.ascii_uppercase)
lowercase_letters = list(string.ascii_lowercase)

# creating a list of all letters
letters = uppercase_letters + lowercase_letters
# creating a list of numbers
numbers = list(string.digits)
# creating a list of special characters
symbols = ['!', '@', '#', '$', '%', '^', '&', '*', '(', ')']

print("Welcome to the Random Password Generator!\n-----------------------------------------")
number_of_letters = int(input("How many letters would you like in your password?\n"))
number_of_symbols = int(input("How many symbols would you like?\n"))
number_of_numbers = int(input("How many numbers would you like?\n"))

# creating an empty string to store the password
password_lists = ""

# adding random letters, symbols and numbers to the password
for letter in range(number_of_letters):
    password_lists += random.choice(letters)

for symbol in range(number_of_symbols):
    password_lists += random.choice(symbols)

for number in range(number_of_numbers):
    password_lists += random.choice(numbers)

# converting the password to a list
password_lists = list(password_lists)
# shuffling the password list
random.shuffle(password_lists)

# converting the password list back to a string
password = ""
for char in password_lists:
    password += char

print(f"Your password is: {password}")