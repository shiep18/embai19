import logging
import serial
from time import sleep


serial = serial.Serial('COM9', 9600, timeout=0.5)  #/dev/ttyUSB0 
DOMAIN = "hachina"

#ENTITYID = DOMAIN + ".hello_world"
 
# 在python中，__name__代表模块名字
#_LOGGER = logging.getLogger(__name__)
 
 
def setup(hass, config):
    def change_state(call):
        """change_state函数切换改变实体的状态."""
        serial.write('1'.encode())
    def change_state2(call):
        """change_state函数切换改变实体的状态."""
        serial.write('2'.encode())
    def change_state3(call):
        """change_state函数切换改变实体的状态."""
        serial.write('3'.encode())
    def change_state4(call):
        """change_state函数切换改变实体的状态."""
        serial.write('4'.encode())
    def change_state5(call):
        """change_state函数切换改变实体的状态."""
        serial.write('5'.encode())
    def change_state6(call):
        """change_state函数切换改变实体的状态."""
        serial.write('6'.encode())
    def change_state7(call):
        """change_state函数切换改变实体的状态."""
        serial.write('7'.encode())
    def change_state8(call):
        """change_state函数切换改变实体的状态."""
        serial.write('8'.encode())
    def change_state9(call):
        """change_state函数切换改变实体的状态."""
        serial.write('9'.encode())
    def change_statea(call):
        """change_state函数切换改变实体的状态."""
        serial.write('a'.encode())
    def change_stateb(call):
        """change_state函数切换改变实体的状态."""
        serial.write('b'.encode())
    def change_statec(call):
        """change_state函数切换改变实体的状态."""
        serial.write('c'.encode())
    # 注册服务hachina.change_state
    hass.services.register(DOMAIN, 'change_state', change_state)
    hass.services.register(DOMAIN, 'change_state2', change_state2)
    hass.services.register(DOMAIN, 'change_state3', change_state3)
    hass.services.register(DOMAIN, 'change_state4', change_state4)
    hass.services.register(DOMAIN, 'change_state5', change_state5)
    hass.services.register(DOMAIN, 'change_state6', change_state6)
    hass.services.register(DOMAIN, 'change_state7', change_state7)
    hass.services.register(DOMAIN, 'change_state8', change_state8)
    hass.services.register(DOMAIN, 'change_state9', change_state9)
    hass.services.register(DOMAIN, 'change_statea', change_statea)
    hass.services.register(DOMAIN, 'change_stateb', change_stateb)
    hass.services.register(DOMAIN, 'change_statec', change_statec)
    return True
