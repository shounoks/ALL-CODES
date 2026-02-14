# filename: transposition.py
import math
from base_cipher import BaseCipher


class TranspositionCipher(BaseCipher):
    def get_rules(self):
        return "Key must be a unique word (e.g. 'ZEBRA'). No spaces."

    def encrypt(self, text, key):
        msg = "".join(text.split())
        k_len = len(key)
        if k_len == 0: return "Error: Empty Key"

        # DSA: Sorting Indices
        key_indices = sorted(range(k_len), key=lambda k: key[k])

        res = []
        for i in key_indices:
            res.append(msg[i::k_len])
        return "".join(res)

    def decrypt(self, text, key):
        msg = "".join(text.split())
        k_len = len(key)
        if k_len == 0: return "Error: Empty Key"

        # Grid Calculation (DSA Logic)
        n_rows = math.ceil(len(msg) / k_len)
        n_empty = (n_rows * k_len) - len(msg)
        n_full = k_len - n_empty

        key_indices = sorted(range(k_len), key=lambda k: key[k])
        col_lengths = [n_rows] * k_len
        for i in range(n_full, k_len):
            col_lengths[i] = n_rows - 1

        cols = [''] * k_len
        curr = 0
        for k_idx in key_indices:
            length = col_lengths[k_idx]
            cols[k_idx] = msg[curr: curr + length]
            curr += length

        res = []
        for r in range(n_rows):
            for c in range(k_len):
                if r < len(cols[c]):
                    res.append(cols[c][r])
        return "".join(res)