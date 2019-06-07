# Tyler Rajotte
# Who wants to learn how to use make when you could just build your own version of make from scratch
import os

# Settings
outputname = "EveryEngine"
sourceCodeDirectory = "Source/"
flags = "-w"
linkerflags = "-lGL -lSDL2 -lGLEW"
runAfterCompile = True
compiler = "g++"

# Build Counter
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

# New Walk powered source code finder
filestocompile = ""
for root, dirs, files in os.walk(sourceCodeDirectory, topdown=False):
    for file in files:
        cleanedname = None
        if root[-1] != "/":
            cleanedname = root + "/" + file
        else:
            cleanedname = root + file

        if cleanedname.split(".")[1] == "cpp" or cleanedname.split(".")[1] == "h":
            filestocompile += cleanedname + " "

# print("{} {}{} {} -o {}".format(compiler, filestocompile, flags, linkerflags, outputname))
# print("./" + outputname)

os.system("{} {}{} {} -o {}".format(compiler, filestocompile, flags, linkerflags, outputname))
if runAfterCompile:
    os.system("./" + outputname)
