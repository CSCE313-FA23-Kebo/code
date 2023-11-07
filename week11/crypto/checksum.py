import hashlib
# The checksum is used for error detection!

def generate_checksum(file_path):
    with open(file_path, 'rb') as f:
        data = f.read()
    checksum = hashlib.md5(data).hexdigest() # checksum option 2
    #checksum = hashlib.sha256(data).hexdigest() # checksum option 1
    return checksum

checksum = generate_checksum('numbers.txt')
print(checksum) 