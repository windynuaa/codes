import serial           #安装此拓展库
import time
import threading
class gps(threading.Thread):
    ser = ''
    latitude=''
    altitude=''
    longitude=''
    located=False
    def get_position(self):
        if self.located:
            return selflatitude,self.longitude
        else:
            return '未定位','未定位'
    def __init__(self, threadID, name, counter,com, baudrate):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.ser = serial.Serial(com, baudrate, bytesize=8, parity='N', stopbits=1, timeout=1)
        if self.ser.isOpen():
            print('test read')
            self.ser.readline()
            print('test end')
        else:
            print('init fail')
    def run(self):                   #把要执行的代码写到run函数里面 线程在创建后会直接运行run函数 
        self.temp=self.ser.readline()
        self.temp_split=self.temp.split(b',')
        if self.temp_split[0]==b'$GNGSA':
            if self.temp_split[2]!=b'1':
                  self.located=True
        if self.temp_split[0]==b'$GNGGA':
            self.longitude=self.temp_split[4]+b','+self.temp_split[5]
            self.latitude=self.temp_split[2]+b','+self.temp_split[3]

g=gps(1,'gps',1,'COM3',9600)
g.start()
while 1:
    print(g.get_position())
    time.sleep(0.5)
