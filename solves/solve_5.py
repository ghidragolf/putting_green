# Using the decompiler
# @author 
# @category GhidraGolf
# @keybinding 
# @menupath 
# @toolbar 

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import hashlib

program = getCurrentProgram()
ifc = DecompInterface()
ifc.openProgram(program)
code = ifc.decompileFunction(getFirstFunction(), 0, None)
c_code = code.getDecompiledFunction().getC()
println(c_code)
