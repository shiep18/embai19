import mcpi.minecraft as minecraft
import time

mc = minecraft.Minecraft.create()
pos = mc.player.getTilePos()
while True:
    time.sleep(1)
    pos = mc.player.getTilePos()
    mc.postToChat("x="+str(pos.x)+" y="+str(pos.y)+" z="+str(pos.z))
    if pos.x==-28 and pos.y==11:
        mc.postToChat('welcome home')
