import base64
from Crypto.Cipher import AES

class AES_CBC_Cipher:
    def __init__( self, key ):
        self.key = key

    def pad(self, s):
        return s + (AES.block_size - len(s) % AES.block_size) * chr(AES.block_size - len(s) % AES.block_size)
    def unpad(self, s):
        return s[:-ord(s[len(s)-1:])]

    def encrypt( self, iv, raw ):
        raw = self.pad(raw)

        cipher = AES.new( self.key, AES.MODE_CBC, iv )
        return base64.b64encode( iv + cipher.encrypt( raw ) ) 

    def decrypt( self, enc ):
        enc = base64.b64decode(enc)
        iv = enc[:16]
        cipher = AES.new(self.key, AES.MODE_CBC, iv )
        return self.unpad(cipher.decrypt( enc[16:] ))
