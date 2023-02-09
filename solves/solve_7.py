# basic patching
# @author 
# @category GhidraGolf
# @keybinding 
# @menupath 
# @toolbar 

from ghidra.program.model.data import StringDataType

program = getCurrentProgram()

addr = findBytes(program.getMinAddress(), "hello world!")
println("Patching: " + str(addr))
program.getMemory().setBytes(addr, "hello Ghidra".encode('utf-8'))

println("Hello Ghidra: " + addr.toString())
