from Crypto.Signature import PKCS1_v1_5
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA

with open('private.pem', 'rb') as f:
    private_key = RSA.importKey(f.read(), passphrase='dees')
message = b'RISC-V Education: https://riscvedu.org/'
hash = SHA256.new(message) # Calculate the hash
print(f"This is the hash: {hash}")
pk = PKCS1_v1_5.new(private_key)
sm = pk.sign(hash)
print(sm.hex())

