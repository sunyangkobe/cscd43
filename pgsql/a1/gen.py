import random

f = open('upload.sql', 'w')

for i in range(1,5001):
    #q = "INSERT INTO data VALUES("+str(i)+","+str(random.randint(1,100))+","+str(random.randint(1,100))+","+str(random.randint(1,100))+");\n"
    q = str(i)+","+str(random.randint(1,100))+","+str(random.randint(1,100))+","+str(random.randint(1,100))+"\n"
    f.write(q)
    
f.close()    