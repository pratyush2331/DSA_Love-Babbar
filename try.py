from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import rsa, padding
from cryptography.hazmat.primitives import padding as sym_padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from email import message_from_string
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import smtplib
import imaplib
import base64

def generate_key_pair():
    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=2048,
        backend=default_backend()
    )
    public_key = private_key.public_key()
    return private_key, public_key

def encrypt_message(message, public_key):
    ciphertext = public_key.encrypt(
        message.encode(),
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return base64.b64encode(ciphertext)

def decrypt_message(ciphertext, private_key):
    ciphertext = base64.b64decode(ciphertext)
    plaintext = private_key.decrypt(
        ciphertext,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return plaintext.decode()

def send_encrypted_email(sender_email, app_password, recipient_email, subject, body):
    private_key, public_key = generate_key_pair()

    # Create a MIME message
    message = MIMEMultipart()
    message['From'] = sender_email
    message['To'] = recipient_email
    message['Subject'] = subject

    # Encrypt the message body
    encrypted_body = encrypt_message(body, public_key)

    # Attach the encrypted message to the email
    message.attach(MIMEText(encrypted_body.decode(), 'plain'))

    # Connect to SMTP server and send the email
    with smtplib.SMTP('smtp.gmail.com', 587) as server:
        server.starttls()
        server.login(sender_email, app_password)
        server.sendmail(sender_email, recipient_email, message.as_string())

def receive_encrypted_email(username, password, server):
    # Connect to IMAP server and retrieve the latest email
    with imaplib.IMAP4_SSL(server) as mail:
        mail.login(username, password)
        mail.select('inbox')
        status, messages = mail.search(None, 'ALL')

        if status == 'OK':
            latest_email_id = messages[0].split()[-1]
            status, msg_data = mail.fetch(latest_email_id, '(RFC822)')

            if status == 'OK':
                raw_email = msg_data[0][1].decode('utf-8')
                email_message = message_from_string(raw_email)

                # Decrypt the message body
                encrypted_body = email_message.get_payload()
                decrypted_body = decrypt_message(encrypted_body, private_key)

                print(f"Subject: {email_message['Subject']}")
                print(f"From: {email_message['From']}")
                print(f"Decrypted Message: {decrypted_body}")

# Example usage
sender_email = 'pratyush2331@gmail.com'
app_password = 'BlockchainWith$2331'
recipient_email = 'pratyush.raj2020@vitstudent.ac.in'
subject = 'Test Encrypted Email'
body = 'This is a test email message.'

send_encrypted_email(sender_email, app_password, recipient_email, subject, body)

# Example for receiving the encrypted email
private_key, _ = generate_key_pair()
receive_encrypted_email(recipient_email, app_password, 'imap.gmail.com')
