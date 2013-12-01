import random

f = open("a2_3.sql", "w")

op = {1:"<", 2:">", 3:"<=", 4:">="}
for i in range(100):
    out = "SELECT COUNT(*) FROM R,S WHERE R.ID = S.ID AND R.ID " + op[random.randint(1,4)] + " " + str(random.randint(1,10000)) + " AND S.ID " + op[random.randint(1,4)] + " " + str(random.randint(1,10000)) + ";\n"
    f.write(out)
f.close()