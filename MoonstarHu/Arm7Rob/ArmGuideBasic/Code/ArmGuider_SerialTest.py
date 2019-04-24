# -*- coding: utf-8 -*-

from HTTP_API.client_api import Moonstar_communication


import serial


now_data=Moonstar_communication(Host = "119.23.237.255", Port = 80)


portx="COM9"
bps=9600
timex=5
ser=serial.Serial(portx,bps,timeout=timex)
print("serial port parameters : ",ser)
print("Port:",ser.port)
print("Baudrate:",ser.baudrate)
print("ArmGuider Initialization Done.")
while True:
    try:
    # 读数据
        data=now_data.get_status("DOOR1")
        print(type(data))
        print(data)
        
        # receive=ser.read(60)
        # print(receive)
    # 写数据
        result = ser.write(data.encode("utf-8"))
        print("Write Done!")
        #   ser.close()#关闭串口
        # 异常处理 
    except Exception as e:
        print("Error：",e)