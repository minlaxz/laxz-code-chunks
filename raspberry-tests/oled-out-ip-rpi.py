import time,os
ip = os.popen("hostname -I").readline()
ssid = os.popen("iwgetid").readline().replace('wlan0     ','Pi is Connected to... ')
string = "This Boot-up Python Script is created by Min Latt (Admin)\n"
def get_device():
    DC = 24
    RST = 25
	try:
	    from luma.oled.device import sh1106
        from luma.core.interface.serial import spi
    except ImportError:
	    os.popen("python3 -m pip install --upgrade luma.oled")
    serial = spi(device=0, port=0, bus_speed_hz=8000000, transfer_size=4096, gpio_DC=DC , gpio_RST=RST)
    return(sh1106(serial, rotate=2))

from PIL import Image,ImageFont
from luma.core.virtual import terminal
from luma.core.render import canvas

def make_font(name,size):
    font_path = os.path.abspath(os.path.join(os.path.dirname(__file__), 'fonts', name))
    return ImageFont.truetype(font_path, size)

def main():
    while True:
        for fontname, size in [("ProggyTiny.ttf", 16)]:
            font = make_font(fontname, size) if fontname else None
            term = terminal(get_device(), font)
            term.animate=True
            term.println(string)
            term.println(ip)
            term.puts(ssid)
            time.sleep(5)
        break
if __name__ == "__main__":