import random

f = open('IndexScanQueries.sql', 'w')

for i in range(10):
    a = random.randint(1,99)
    b = min(a + random.randint(1,15), 100)
    q = "SELECT COUNT(*) FROM Data WHERE ID > " + str(a) +" AND ID < " + str(b) + ";\n"
    f.write(q)
f.write("\n");
f.close()    
