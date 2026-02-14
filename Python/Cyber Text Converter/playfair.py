# filename: playfair.py
from base_cipher import BaseCipher


class PlayfairCipher(BaseCipher):
    def get_rules(self):
        return "Key must be Text. 'J' becomes 'I'. Odd length text gets 'X'."

    def _create_matrix(self, key):
        # DSA: Set for uniqueness, List for Matrix
        key = key.upper().replace("J", "I")
        seen = set()
        matrix = []

        for char in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
            if char.isalpha() and char not in seen:
                matrix.append(char)
                seen.add(char)
        return matrix

    def encrypt(self, text, key):
        matrix = self._create_matrix(key)
        # DSA: HashMap (Dictionary) for O(1) coordinate lookup
        char_pos = {c: (i // 5, i % 5) for i, c in enumerate(matrix)}

        clean = "".join([c.upper() for c in text if c.isalpha()]).replace("J", "I")
        pairs = []
        i = 0
        while i < len(clean):
            a = clean[i]
            b = clean[i + 1] if i + 1 < len(clean) else 'X'
            if a == b:
                pairs.append((a, 'X'))
                i += 1
            else:
                pairs.append((a, b))
                i += 2

        res = []
        for a, b in pairs:
            r1, c1 = char_pos[a]
            r2, c2 = char_pos[b]

            if r1 == r2:
                res.extend([matrix[r1 * 5 + (c1 + 1) % 5], matrix[r2 * 5 + (c2 + 1) % 5]])
            elif c1 == c2:
                res.extend([matrix[((r1 + 1) % 5) * 5 + c1], matrix[((r2 + 1) % 5) * 5 + c2]])
            else:
                res.extend([matrix[r1 * 5 + c2], matrix[r2 * 5 + c1]])
        return "".join(res)

    def decrypt(self, text, key):
        matrix = self._create_matrix(key)
        char_pos = {c: (i // 5, i % 5) for i, c in enumerate(matrix)}
        clean = "".join([c.upper() for c in text if c.isalpha()])

        if len(clean) % 2 != 0: return "Error: Ciphertext length must be even."

        res = []
        for i in range(0, len(clean), 2):
            a, b = clean[i], clean[i + 1]
            try:
                r1, c1 = char_pos[a]
                r2, c2 = char_pos[b]

                if r1 == r2:
                    res.extend([matrix[r1 * 5 + (c1 - 1) % 5], matrix[r2 * 5 + (c2 - 1) % 5]])
                elif c1 == c2:
                    res.extend([matrix[((r1 - 1) % 5) * 5 + c1], matrix[((r2 - 1) % 5) * 5 + c2]])
                else:
                    res.extend([matrix[r1 * 5 + c2], matrix[r2 * 5 + c1]])
            except KeyError:
                return "Error: Invalid char in ciphertext."
        return "".join(res)