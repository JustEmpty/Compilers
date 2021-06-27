import os

testsDir = "../tests-fir/"
arr = os.listdir(testsDir)
arr = sorted(arr)

counter = 0
counter2 = 0
for test in arr:
    if test[-4:] == ".fir":
        counter2 += 1
        print('\033[96m' + test + '\033[00m')
        file = testsDir + test[:-4]
        os.system("./fir --target asm " + file + ".fir > " + file + ".txt")
        os.system("yasm -felf32 " + file + ".asm")
        os.system("ld -m elf_i386 -o " + test[:-4] + " " + test[:-4] + ".o -L$HOME/compiladores/root/usr/lib -lrts")
        os.system("mv " + test[:-4] + " " + testsDir)
        os.system("mv " + test[:-4] + ".o" + " " + testsDir)
        os.system("./" + file + " > " + file + ".out")
        os.system("diff -BZwEb " + file + ".out" + " " + testsDir + "expected/" + test[:-4] + ".out > " + file + ".diff")
        with open(file + ".diff") as f:
            contents = f.read()
            if len(contents) != 0:
                print('\033[91m' + contents + '\033[00m')
            else:
                counter += 1
            f.close()
        for x in ('.o', '.out', '.txt', '.asm', '.diff', ''):
            try:
                os.remove(testsDir + test[:-4] + x)
            except:
                pass


print("TOTAL: " + str(counter) + "/" + str(counter2))
