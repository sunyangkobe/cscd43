import random

f = open("a2_2.sql", "w")

for i in range(1,10001):
    out = "INSERT INTO R VALUES (" + str(i) + ", " + str(random.randint(1,10000)) + ", " + str(random.randint(1,10000)) + ", " + str(random.randint(1,10000)) + ");\n"
    f.write(out)
    
for i in range(1,10001):
    out = "INSERT INTO S VALUES (" + str(i) + ", " + str(random.randint(1,10000)) + ", " + str(random.randint(1,10000)) + ", " + str(random.randint(1,10000)) + ");\n"
    f.write(out)
    

f.close()