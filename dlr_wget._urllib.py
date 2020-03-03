import wget
import urllib.request as r
import time
def loadLink(url):
	try:
		r.urlopen(url)
	except Exception as e:
		print(e)
	print('Link is detected: '+ url )

def get():
	url = input('Input URL: ')
	loadLink(url)
	download_this(url)

def download_this(url):
	print('Fixing URL error')
	if(url[len(url)-1] != '/'):
		url = url+'/'
	folder = input('folder name to download: ')
	print('--Auto download started--')
	x = 1
	while(x <= 50):
		wget.download(url+str(x)+'.jpg', 'c:/users/minlaxzwin/Desktop/'+folder+'/'+str(x)+'.jpg')
		x = x+1
		print('_'+str(x-1))
		time.sleep(2)

if __name__ == '__main__':
	get()