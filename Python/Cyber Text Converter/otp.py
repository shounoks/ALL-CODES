# filename: otp.py
from base_cipher import BaseCipher


class OTPCipher(BaseCipher):
    def get_rules(self):
        return "Key is text. Repeats if shorter than message."

    def process(self, text, key, mode):
        res = []
        clean_text = [c.upper() for c in text if c.isalpha()]
        clean_key = [c.upper() for c in key if c.isalpha()]

        if not clean_key: return "Error: Key requires letters."

        # DSA: Cyclic extension
        ext_key = (clean_key * (len(clean_text) // len(clean_key) + 1))[:len(clean_text)]

        for i, t in enumerate(clean_text):
            t_val = ord(t) - ord('A')
            k_val = ord(ext_key[i]) - ord('A')

            if mode == 'encrypt':
                val = (t_val + k_val) % 26
            else:
                val = (t_val - k_val + 26) % 26
            res.append(chr(val + ord('A')))
        return "".join(res)

    def encrypt(self, text, key):
        return self.process(text, key, 'encrypt')

    def decrypt(self, text, key):
        return self.process(text, key, 'decrypt')