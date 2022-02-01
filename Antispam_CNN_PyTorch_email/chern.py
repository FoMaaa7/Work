from imaplib import IMAP4_SSL

YA_HOST = "imap.mail.ru"
YA_PORT = 993
YA_USER = "katerina.test11@mail.ru"

YA_PASSWORD = "3Rk-kCX-5Hp-JvY"
SENDER = "Yoba"

connection = IMAP4_SSL(host=YA_HOST, port=YA_PORT)
connection.login(user=YA_USER, password=YA_PASSWORD)
status, msgs = connection.select('INBOX')
assert status == 'OK'

typ, data = connection.search(None, 'FROM', '"%s"' %s SENDER)
print(data)
for num in data[0].split():
    typ, message_data= connection.fetch(num, '(RFC822)')
    print(data)
    print('Message %s\n%s\n' % (num, message_data[0][1]))
connection.close()
connection.logout()