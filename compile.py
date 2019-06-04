# Tyler Rajotte
# Who wants to learn how to use make when you could just build your own version of make from scratch
import os

# Settings
outputname = "opengltutorial"
flags = "-w"
linkerflags = "-lGL -lSDL2 -lGLEW"
runAfterCompile = True
compiler = "g++"
#compiler = "x86_64-w64-mingw32-g++"

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

os.system("{} {}{} {} -o {}".format(compiler, filestocompile, flags, linkerflags, outputname))
if runAfterCompile:
    os.system("./" + outputname)
