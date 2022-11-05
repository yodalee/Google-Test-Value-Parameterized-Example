
import random

with open("testdata.txt", "w") as f:
    for _ in range(5):
        rand = random.randrange(0, 1 << 32 - 1)
        f.write("{}\n".format(rand))
        f.write("0x{:08X}\n".format(rand))
