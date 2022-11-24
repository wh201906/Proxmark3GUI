import os, sys, shutil
from win32api import GetFileVersionInfo
from json import load
from re import fullmatch, sub, IGNORECASE

compressDirList = []


def getPEVersion(fname):
    try:
        fileInfo = GetFileVersionInfo(fname, "\\")
        version = "V%d.%d.%d" % (
            fileInfo["FileVersionMS"] / 65536,
            fileInfo["FileVersionMS"] % 65536,
            fileInfo["FileVersionLS"] / 65536,
        )
    except Exception:
        print("Cannot get version number of", fname)
    return version


os.chdir(sys.path[0])
print("Current Directory:", os.getcwd())
targetName = os.path.abspath(os.getcwd()).split("\\")[-2]
print("Target Name", targetName)

src32Dir = ""
src64Dir = ""
dirList = os.listdir("../")

for i in dirList:
    if not os.path.isdir("../" + i):
        continue
    if not i.startswith("build"):
        continue

    if i.endswith("32_bit-Release"):
        src32Dir = "../" + i
    elif i.endswith("64_bit-Release"):
        src64Dir = "../" + i

src32Path = src32Dir + "/release/" + targetName + ".exe"
src64Path = src64Dir + "/release/" + targetName + ".exe"
print("Target Files:")
print(src32Path)
print(src64Path)

ver32 = getPEVersion(src32Path)
ver64 = getPEVersion(src64Path)
print("Versions:")
print("win32:", ver32)
print("win64:", ver64)
if ver32 != ver64:
    print("WARNING!")
    print("Version names are not the same!")
dst32Dir = "./" + ver32 + "-win32"
dst64Dir = "./" + ver64 + "-win64"
dst32Path = dst32Dir + "/" + targetName + ".exe"
dst64Path = dst64Dir + "/" + targetName + ".exe"

if os.path.exists(dst32Dir) and os.path.exists(dst32Path):
    print(dst32Path, "exists, replacing...")
    os.remove(dst32Path)
elif not os.path.exists(dst32Dir):
    print(dst32Dir, "doesn't exist, creating...")
    shutil.copytree("./32", dst32Dir)
shutil.copyfile(src32Path, dst32Path)
compressDirList.append(dst32Dir)

if os.path.exists(dst64Dir) and os.path.exists(dst64Path):
    print(dst64Path, "exists, replacing...")
    os.remove(dst64Path)
elif not os.path.exists(dst64Dir):
    print(dst64Dir, "doesn't exist, creating...")
    shutil.copytree("./64", dst64Dir)
shutil.copyfile(src64Path, dst64Path)
compressDirList.append(dst64Dir)

# TODO: GUI+client
clientList = [
    "official-v3.1.0",
    "rrg_other-v4.13441",
    "rrg_other-v4.14434",
    "rrg_other-v4.14831",
    "rrg_other-v4.15864",
]

configList = []
for config in os.listdir("../config"):
    configPath = os.path.join("../config", config)
    if os.path.isfile(configPath) and config.endswith(".json"):
        configList.append(config)


def generateClient(clientName):
    global compressDirList
    clientSrcDir = "./client/" + clientName
    clientDstDir = "./" + ver64 + "-win64-" + clientName
    clientDstGUIDir = clientDstDir + "/GUI"

    if os.path.exists(clientDstDir) and os.path.exists(clientDstGUIDir):
        print(clientDstGUIDir, "exists, replacing...")
        shutil.rmtree(clientDstGUIDir)
    elif not os.path.exists(clientDstDir):
        print(clientDstDir, "doesn't exist, creating...")
        shutil.copytree(clientSrcDir, clientDstDir)
    shutil.copytree(dst64Dir, clientDstGUIDir)
    if "official" in clientName:
        shutil.copyfile(
            "./client/GUIsettings_Official.ini", clientDstGUIDir + "/GUIsettings.ini"
        )
    elif "rrg" in clientName:
        shutil.copyfile(
            "./client/GUIsettings_RRG.ini", clientDstGUIDir + "/GUIsettings.ini"
        )
        # Use exactly matched configFile if possible
        version = clientName[clientName.find("v") :]
        for config in configList:
            if version in config:
                print("Find matched config file", config)
                with open(
                    clientDstGUIDir + "/GUIsettings.ini", "r", encoding="utf-8"
                ) as f:
                    data = f.read()
                    data = sub(
                        "configFile=:/config/.+\\.json",
                        "configFile=:/config/" + config,
                        data,
                    )
                with open(
                    clientDstGUIDir + "/GUIsettings.ini", "w", encoding="utf-8"
                ) as f:
                    f.write(data)

    compressDirList.append(clientDstDir)
    return clientDstDir


for cl in clientList:
    generateClient(cl)

use7z = input("Compress?(y/N)")
if fullmatch("yes|y", use7z, IGNORECASE):
    print(compressDirList)
    for it in compressDirList:
        archivePath = it + ".7z"

        if os.path.exists(archivePath):
            print(archivePath, "exists, replacing...")
            os.remove(archivePath)
        os.system("7z a -t7z -mmt8 -mx9 " + archivePath + " " + it)
