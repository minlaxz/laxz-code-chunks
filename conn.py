from urllib.request import urlopen
import urllib
def internet_on():
    try:
        urlopen('http://www.example.com', timeout=1)
        print("Connection OK")
        return True
    except urllib.error.URLError: 
        print("No Connection")
        return False


if __name__ == "__main__":
    internet_on()
