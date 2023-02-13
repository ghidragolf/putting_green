import ghidra.app.script.GhidraScript

functionName = "flag" 

fm = currentProgram.getFunctionManager() 
functions = fm.getFunctions(True) 

for func in functions:
    if func.getName() == functionName:
        
        """
        entryPoint = ???? # get the entry point of the function 

        refs = ????? # get the references to entryPoint
        """

        break

for ref in refs:
    print("Reference to address offset: 0x" + str(ref.getFromAddress()))
