# Dan Otieno.
# CPE 449 - Dictionary Attack.
# 09/16/2023.
# Other sources used to complete this assignment:
# https://docs.python.org/3/library/crypt.html
# https://passlib.readthedocs.io/en/stable/
import os
import sys
import hmac
from passlib.hash import sha512_crypt

# Function to read password hashes from the shadow file in /Lab2.
def read_shadow(shadow_path):
    pass_hashes = {}

    try:
        with open(shadow_path, 'r') as shadow_file:
            lines = shadow_file.readlines()
            for line in lines:
                line_split = line.strip().split(':')
                if len(line_split) >= 2:
                    username = line_split[0]
                    password_hash = line_split[1]
                    pass_hashes[username] = password_hash
    except FileNotFoundError:
        print(f"Error: {shadow_path} not found.")
    return pass_hashes

# Hmac function to calculate and return hash.
def fnHash(word, key):
    hmacHash = hmac.new(key.encode(), word.encode(), 'sha512')
    return hmacHash.hexdigest()

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 dattack.py /Lab2/shadow dictionary.txt")
        sys.exit(1)

    shadow_path = sys.argv[1]
    dictionary_path = sys.argv[2]

    # Read password hashes from shadow path, in this case /Lab2/shadow.
    shadow_hashes = read_shadow(shadow_path)

    # Check each password in the dictionary.txt file.
    try:
        with open(dictionary_path, 'r') as dictionary_file:
            dictionary_passwords = dictionary_file.readlines()
            for password in dictionary_passwords:
                password = password.strip()
                for username, shadow_hash in shadow_hashes.items():
                    if shadow_hash.startswith("$6"): # $6 indicates Passlib hash.
                        if sha512_crypt.verify(password, shadow_hash):
                            print(f"\nMatch found for userId {username}.\nPassword = {password}.\n")
                            break  # Stop comparison when a match is found.
                    else:
                        key = shadow_hash.split('$')[3] #Use Hmac if it does not start with $6.
                        hmacHash = fnHash(password, key)
                        if hmacHash == shadow_hash:
                            print(f"\nMatch found for userId {username}.\nPassword = {password}.\n")
                            break # Stop comparison when a match is found.
                else:
                    print(f"No match was found for userId {username}.") # Print this line if no match is found.
    except FileNotFoundError:
        print(f"Error: {dictionary_path} not found.")


if __name__ == "__main__":
    main()