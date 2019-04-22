import mcpi.minecraft as minecraft
import mcpi.block as block

mc = minecraft.Minecraft.create()

pos = mc.player.getTilePos()

for a in range(10):
    mc.setBlock(pos.x+a, pos.y, pos.z, block.STONE.id) 
