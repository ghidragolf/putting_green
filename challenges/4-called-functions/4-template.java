// functions that secondMain calls

import ghidra.app.script.GhidraScript;

public class FunctionCalls extends GhidraScript {

    @Override
    public void run() throws Exception {
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        
        while (functions.hasNext()) {
            Function func = functions.next();
            
            if (func.getName().equals("secondMain")) {
                // FunctionIterator calledFunctions = ??????; // get called functions from func
                
                while (calledFunctions.hasNext()) {
                    Function calledFunc = calledFunctions.next();
                    println("Called function: " + calledFunc.???????); // get name from calledFunc
                }
            }
        }
    }
}
