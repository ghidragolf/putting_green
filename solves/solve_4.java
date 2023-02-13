//get called functions list
//@author 
//@category GhidraGolf
//@keybinding 
//@menupath 
//@toolbar 

import java.util.Iterator;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class solve_4 extends GhidraScript {

    @Override
    public void run() throws Exception {
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        
        while (functions.hasNext()) {
            Function func = functions.next();
            
            if (func.getName().equals("secondMain")) {
            	Set<Function> calledFunctions =  func.getCalledFunctions(null);
            	Iterator<Function> funcs = calledFunctions.iterator();
            	
            	while(funcs.hasNext()) {
                    Function called = funcs.next();
                    println("Called function: " + called.getName());

            	}
            	
            }
        }
    }
}
