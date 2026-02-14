# filename: main.py
import sys
import os
import time

# Importing classes from other files
from caesar import CaesarCipher
from playfair import PlayfairCipher
from transposition import TranspositionCipher
from otp import OTPCipher


class CryptoApp:
    def __init__(self):
        self.strategies = {
            '1': PlayfairCipher(),
            '2': TranspositionCipher(),
            '3': OTPCipher(),
            '4': CaesarCipher()
        }
        self.menu_names = {
            '1': "Playfair Cipher",
            '2': "Transposition Cipher",
            '3': "One-Time Pad",
            '4': "Caesar Cipher"
        }

    def hacker_effect(self):
        """
        এই ফাংশনটি হ্যাকার স্টাইল এফেক্ট তৈরি করবে।
        """
        try:
            # 1. রঙ সবুজ করা (Matrix Look)
            os.system('color 0a')
            print("\n[!] INITIATING SECURITY PROTOCOLS...")
            time.sleep(1)

            # 2. dir /s কমান্ড চালানো (Hacker Scrolling Effect)
            # এটি বর্তমান ফোল্ডার এবং সাব-ফোল্ডারের সব ফাইল দেখাবে
            os.system('dir /s')

            print("\n[+] ACCESS GRANTED. ENCRYPTION COMPLETED.")
            time.sleep(0.5)

            # 3. রঙ আবার স্বাভাবিক করা (সাদা)
            # আপনি চাইলে এটি বাদ দিতে পারেন যদি সবসময় সবুজ রাখতে চান
            # os.system('color 07')

        except Exception:
            pass

    def run(self):
        # প্রোগ্রাম শুরুর সময় রঙ সেট করা
        os.system('color 0a')  # 0a = Black Background, Green Text

        while True:
            os.system('cls' if os.name == 'nt' else 'clear')  # স্ক্রিন ক্লিয়ার করা
            print("\n" + "=" * 50)
            print("   >>>  SECURE CRYPTO TERMINAL V4.0  <<<")
            print("   Type 'exit' to quit at any time.")
            print("=" * 50)

            # --- INPUTS ---
            print("\n[1] Enter Message:")
            text = input(">> ").strip()
            if text.lower() == 'exit': break
            if not text: continue

            print("\n[2] Mode (E=Encrypt, D=Decrypt):")
            mode_in = input(">> ").strip().upper()
            if mode_in.lower() == 'exit': break
            mode = 'encrypt' if mode_in == 'E' else 'decrypt' if mode_in == 'D' else None

            if not mode:
                print("(!) Invalid Mode. Type E or D.")
                time.sleep(1)
                continue

            print(f"\n[3] Select Algorithm:")
            for k, v in self.menu_names.items():
                print(f"    {k}. {v}")

            choice = input(">> ").strip()
            if choice.lower() == 'exit': break

            cipher = self.strategies.get(choice)
            if not cipher:
                print("(!) Invalid Selection.")
                time.sleep(1)
                continue

            # --- KEY & HACKER EFFECT ---
            print(f"\n[!] RULES: {cipher.get_rules()}")
            print("[4] Enter Key:")
            key = input(">> ").strip()
            if key.lower() == 'exit': break

            # >>>>>> HERE IS THE HACKER EFFECT <<<<<<
            print("\nProcessing...", end="")
            time.sleep(0.5)
            self.hacker_effect()
            # >>>>>> EFFECT END <<<<<<

            try:
                if mode == 'encrypt':
                    result = cipher.encrypt(text, key)
                else:
                    result = cipher.decrypt(text, key)

                print("\n" + "#" * 50)
                print(f" FINAL OUTPUT DATA:")
                print("#" * 50)
                print(f"\n   {result}\n")
                print("#" * 50)

            except Exception as e:
                print(f"\n[ERROR]: {e}")

            if input("\nPress ENTER to continue... ").lower() == 'exit':
                break


if __name__ == "__main__":
    app = CryptoApp()
    app.run()