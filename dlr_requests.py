import requests
url = "https://mtl.ttsqgs.com/images/img/17650/1.jpg"
myfile = requests.get(url)
open('C://users/minlaxzwin/Desktop/wall_ps/1.jpg','wb').write(myfile.content)