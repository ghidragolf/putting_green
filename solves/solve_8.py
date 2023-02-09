# finding bytes in memory
# @author 
# @category GhidraGolf
# @keybinding 
# @menupath 
# @toolbar 

evil = "\\x65\\x76\\x69\\x6c"

addr = findBytes(getCurrentProgram().getMinAddress(), evil)

println("Evil Offset: 0x" + str(addr.getOffset()))

