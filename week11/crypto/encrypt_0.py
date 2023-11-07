from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# Generate a new RSA key pair
key = RSA.generate(2048)
# Get the public key
public_key = key.publickey()
message = b'RISC-V Education: https://riscvedu.org/'
cipher = PKCS1_OAEP.new(public_key)
em = cipher.encrypt(message)
print(f'{em}')

