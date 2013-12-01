import random

f = open('ScanQueries.sql', 'w')

OP = ["<",">"]
for i in range(10):
    ABC = ["A","B","C"]
    random.shuffle(ABC)
    
    q = "SELECT COUNT(*) FROM Data WHERE " + \
      ABC[0] + " " + \
      OP[random.randint(0,1)] + " " + \
      str(random.randint(1,100)) + " AND " + \
      ABC[1] + " " + \
      OP[random.randint(0,1)] + " " + \
      str(random.randint(1,100)) + ";\n"
    
    f.write(q)
f.write("\n");
f.close()    
