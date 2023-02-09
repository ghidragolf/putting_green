# decoding strings
# @author 
# @category GhidraGolf
# @keybinding 
# @menupath 
# @toolbar 

import base64
from ghidra.program.model.data import TerminatedStringDataType

definedData = currentProgram.getListing().getDefinedData(True)

for data in definedData:
    if str(data.getDataType()) == "string" and "=" in data.getValue(): # applicable only to our case of encoded data
        encoded = data.getValue()
        println("Decoded: " + base64.b64decode(encoded))
