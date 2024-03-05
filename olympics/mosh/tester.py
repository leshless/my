import os 
import sys
import subprocess

args = sys.argv[1:]
if ((len(args) == 0) or (len(args) > 3)):
    print("Укажите в аргументах командной строки: путь к программе, путь к входным данным, путь к директории записи выходных данных*.")
    exit(1)

elif len(args) == 2:
    progpath, readpath = args

    ifile = open(readpath, "r")
    idata = ifile.read()
    ifile.close()

    result = subprocess.run([progpath], input = idata, check = True)
    print("Выполнение программы завершено.")
else:
    progpath, readpath, writepath = args

    ifile = open(readpath, "r")
    idata = ifile.read()
    ifile.close()

    result = subprocess.run([progpath], input = idata, check = True, capture_output = True, text = True)
    odata = result.stdout
    print("Выполнение программы завершено.")

    ofile = open(writepath + os.path.splitext(os.path.basename(readpath))[0] + "ans" + ".txt", "wb")
    ofile.write(odata.encode())
    ofile.close()


    print("Выходные данные успешно сохранены.")

