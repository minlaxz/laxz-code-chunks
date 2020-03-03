#!/usr/bin/python3

import argparse
import os
import time
import sys

string = '\n\n#created by Min Latt'

ap = argparse.ArgumentParser()
ap.add_argument("-m","--message", default = None, type = str,
    help="show message")
ap.add_argument("-p","--prefix", default = None, type = str,
    help="path to pip directory")

args = vars(ap.parse_args())

def _job(job,function):
    if job == 'message':
        _m(function)
    elif job == 'prefix':
        _pip()

def _pip():
    prefix = args["prefix"]
    if('//' in prefix):
        prefix = prefix.replace("//","/")
    elif(prefix[-1:] != '/'):
        prefix = prefix+'/'

    try:
        if 'pip' not in os.listdir(prefix):
            raise FileNotFoundError
        else:
            version = os.popen(prefix+"python -c 'from pip import __version__; print(__version__); '").read()
            v = int(version.replace('.','').replace('\n',''))
            if(v < 1900):
                __m("You need to update your pip version.\n'(sudo)pip install --upgrade pip'\nExiting.")
            _convert_req(_gen_req(prefix))

    except NotADirectoryError:
        _m("You da need to add 'file or pip' to prefix path!")
    except FileNotFoundError:
        _m('file not found or invalid path.')
        __m('stopping laxz.py')
    except PermissionError:
        _m("This is system file path or laxz can't read this path.")
        __m('stopping laxz.py')
    except Exception as e:
        __m(e)

def _gen_req(prefix):
    _pip_path = os.path.sep.join([prefix,"pip"])
    if ('//' in _pip_path):
        _pip_path = _pip_path.replace('//','/')
    #if(_pip_path[-5:]=='//pip'):
    #    _pip_path = _pip_path.replace("//","/")
    cmd_1 = prefix+'pip list > req.txt'
    cmd_2 = 'rm -f '+prefix+'req.txt'
    if('req.txt' or 'req_n.txt' in os.listdir(prefix)):
        print("generated file found in the path: "+prefix+"\nRemoving")
        time.sleep(1)
        os.system(cmd_2)
    _m('Running command: ' + cmd_1)
    os.system(cmd_1)
    if 'req.txt' in os.listdir(prefix):
        _m('new req.txt generated.')
    else:
        raise FileNotFoundError
    if(prefix[-1:] != '/'):
        prefix += '/'
    elif(prefix[-2:] == '//'):
        prefix.replace('//','/')
    print('Processing '+prefix+'req.txt')
    return(prefix+'req.txt')

def _convert_req(req_path):
    #print(req_path)
    #os.chdir('/home/minlaxz/')
    try:
        with open(req_path,'r') as f:
            data = f.read()
            _data = data.split()
        _sub_convert_req(req_path,_data)

    except FileNotFoundError:
        _m('File Not Found. Internal Error')
        __m('Exiting')

def _sub_convert_req(req_path,_data):
    cmd_3 = 'rm -f '+req_path
    req_n_path = os.path.sep.join([args["prefix"],"req_n.txt"])
    f = open(req_n_path,'w+')
    for i in range(4,len(_data)-1,2):
        data = _data[i]+"=="+_data[i+1]
        f.write("%s\r\n" %data)
    else:
        f.write("%s\r\n"%string)
        f.close()
        os.system(cmd_3)
        a = input("Do you want to view the file? [y,n]: ")
        if(a=='y'):
            os.system('gvfs-open '+req_n_path)
        _m('Finished')
        sys.exit(0)

def _m(msg):
    print("[laxz'INFO]: " + msg)

def __m(msg):
    print("[laxz'ERROR]: " + msg)
    sys.exit(0)

def ___m(msg):
    print("[laxz'FETAL]" + msg)
    sys.exit(1)

for key , val in args.items():
    if val == None:
        pass
    else:
        _job(key,val)

