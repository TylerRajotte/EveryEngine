# Tyler Rajotte
# Who wants to learn how to use make when you could just build your own version of make from scratch
import os

# Settings
outputname = "EveryEngine"
flags = "-w"
linkerflags = "-lGL -lSDL2 -lGLEW"
runAfterCompile = True
compiler = "g++"
#compiler = "x86_64-w64-mingw32-g++"

currentbuildcount = 0

if not(os.path.isfile("BuildCount.txt")):
    print("Creating new Build counter")
    newbuildcounter = open("BuildCount.txt", "w")
    newbuildcounter.write("0")
    newbuildcounter.close()

buildcounter = open("BuildCount.txt", "r+")
currentbuildcount = int(buildcounter.read())
buildcounter.seek(0)
currentbuildcount += 1
buildcounter.write(str(currentbuildcount))
buildcounter.close()

try:
    os.remove(outputname + "-" + str(currentbuildcount - 1))
except OSError:
    print("Could not clean old compiled code")
outputname = outputname + "-" + str(currentbuildcount)

filestocompile = ""
directory = os.listdir(".")

for file in directory:
    try:
        if file.split(".")[1] == "cpp" or file.split(".")[1] == "h":
            filestocompile += file + " "
    except IndexError:
        continue

# print("g++ {}{} {} -o {}".format(filestocompile, flags, linkerflags, outputname))
# print("./" + outputname)

# os.system("{} {}{} {} -o {}".format(compiler, filestocompile, flags, linkerflags, outputname))
if runAfterCompile:
    os.system("./" + outputname)
