import urllib
import ssl
from urllib import request, parse
import json
import cv2
import numpy as np
import serial
from time import sleep

def recv(serial):
    while True:
        data = serial.read_all()
        if data == '':
            continue
        else:
            break
        sleep(0.02)
    return data
 
# client_id 为官网获取的AK， client_secret 为官网获取的SK
def get_token():
    context = ssl._create_unverified_context()
    host = 'https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&client_id=VgevjMvguUG5QsVOoocz20kj&client_secret=zMuCI0Iz4OH6FmfV9f2SILySsAE0Mj74'
    request = urllib.request.Request(host)
    request.add_header('Content-Type', 'application/json; charset=UTF-8')
    response = urllib.request.urlopen(request, context=context)
    # 获取请求结果
    content = response.read()
    # 转换为字符
    content = bytes.decode(content)
    # 转换为字典
    content = eval(content[:-1])
    return content['access_token']
 
 
# 转换图片
# 读取文件内容，转换为base64编码
# 二进制方式打开图文件
def imgdata(file1path, file2path):
    import base64
    f = open(r'%s' % file1path, 'rb')
    pic1 = base64.b64encode(f.read())
    f.close()
    f = open(r'%s' % file2path, 'rb')
    pic2 = base64.b64encode(f.read())
    f.close()
    # 将图片信息格式化为可提交信息，这里需要注意str参数设置
    params = json.dumps(
        [{"image": str(pic1, 'utf-8'), "image_type": "BASE64", "face_type": "LIVE", "quality_control": "LOW"},
         {"image": str(pic2, 'utf-8'), "image_type": "BASE64", "face_type": "IDCARD", "quality_control": "LOW"}]
    )
    return params.encode(encoding='UTF8')
 
 
# 进行对比获得结果
def img_compare(file1path, file2path):
    global flag_huancun
    global flag_0
    token = get_token()
    # 人脸识别API
    # url = 'https://aip.baidubce.com/rest/2.0/face/v3/detect?access_token='+token
    # 人脸对比API
    context = ssl._create_unverified_context()
    # url = 'https://aip.baidubce.com/rest/2.0/face/v3/match?access_token=' + token
    params = imgdata(file1path, file2path)
 
    request_url = "https://aip.baidubce.com/rest/2.0/face/v3/match"
    request_url = request_url + "?access_token="+ token
    request = urllib.request.Request(url=request_url,data=params)
    request.add_header('Content-Type', 'application/json')
    response = urllib.request.urlopen(request ,context=context)
    content = response.read()
    content = eval(content)
    # # 获得分数
    score = content['result']['score']
    if score > 80:
        flag_0 = True
        return '照片相似度：' + str(score) + ',同一个人'
        serial1.write('2')
    else:
        flag_0 = False
        return '照片相似度：' + str(score) + ',不是同一个人'
 
 
if __name__ == '__main__':
    file1path = '0.jpg'
    file2path = '1.jpg'

    classfier = cv2.CascadeClassifier("D:\\openCV\\sourceopencv310\\source\\data\\haarcascades_cuda\\haarcascade_frontalface_alt2.xml")
    
    cap=cv2.VideoCapture(1)
    cv2.namedWindow('face_compare')

    serial1 = serial.Serial('COM12', 57600, timeout=0.5)
    serial2 = serial.Serial('COM17', 9600, timeout=0.5)
    serial3 = serial.Serial('COM20', 9600, timeout=0.5)
    aa = '0'
    flag_0 = False
    flag_receive_huancun1 = False
    flag_receive_huancun2 = False
    #flag_0 = True
    while(1):
        ret ,img = cap.read()
        if not ret:
            print("cap not open")
            continue
        cv2.imwrite('1.jpg', img)

        try:
            res = img_compare(file1path, file2path)
            #print(res)
            #print(flag_0)
        except:
            flag_0 = False
            #continue
        data2 =recv(serial2)
        print(data2)
        data3 =recv(serial3)
        if data3 != b'':
            flag_receive_huancun2 = True
        if flag_receive_huancun2 == True:
            flag_0 = True
        if data2 == b'opendoorCODA0.mp3\r\n' or data2 == b'opendoor':
            flag_receive_huancun1 = True
        if flag_receive_huancun1 == True:
            flag_0 = True
        print(flag_0)
        if flag_0 == True:
            data1 =recv(serial1)
            #print(data1)
            if data1 == b'0' or data1 == b'48484848484848484848484848484848' or data1 == b'00000000000000000000000000000000' or data1 == b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00':
                flag_0 = False
                flag_receive_huancun1 = False
                flag_receive_huancun2 = False
                print('have open the door')
            else:
                print('try to open the door')
                serial1.write(aa.encode('utf-8'))

        cv2.imshow('face_compare',img)
        k = cv2.waitKey(1) & 0xFF
        if k == 27:
            break
    cv2.destroyAllWindows()
    # res = img_compare(file1path, file2path)
    # print(res)
