# filename: base_cipher.py
from abc import ABC, abstractmethod


class BaseCipher(ABC):

    @abstractmethod
    def encrypt(self, text, key):
        pass

    @abstractmethod
    def decrypt(self, text, key):
        pass

    @abstractmethod
    def get_rules(self):
        pass