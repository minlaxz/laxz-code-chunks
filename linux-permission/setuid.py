#!/usr/bin/python3
import os
uid = os.getuid()
euid = os.geteuid()
print("REAL UID {0}".format(uid))
print("EFFECTIVE UID {0}".format(euid))
