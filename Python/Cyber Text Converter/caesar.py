# filename: caesar.py
from base_cipher import BaseCipher


class CaesarCipher(BaseCipher):
    def get_rules(self):
        return "Key can be a Number (e.g. '3') or Word (e.g. 'KEY' -> 3)."

    def _get_shift(self, key):
        # DSA: Key Parsing logic
        try:
            return int(key)
        except ValueError:
            return len(key)

    def process(self, text, key, mode):
        shift = self._get_shift(key) % 26
        if mode == 'decrypt':
            shift = -shift

        result = []
        for char in text:
            if char.isalpha():
                base = ord('A') if char.isupper() else ord('a')
                # DSA: Modular Arithmetic (Cyclic Shift)
                val = (ord(char) - base + shift) % 26 + base
                result.append(chr(val))
            else:
                result.append(char)
        return "".join(result)

    def encrypt(self, text, key):
        return self.process(text, key, 'encrypt')

    def decrypt(self, text, key):
        return self.process(text, key, 'decrypt')
