//get references to function calls
//@author 
//@category GhidraGolf
//@keybinding 
//@menupath 
//@toolbar 

import java.util.ArrayList;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;

public class solve_3 extends GhidraScript {

    @Override
    protected void run() throws Exception {
        String functionName = "flag";
        Address entryPoint;
        Reference[] refs = new Reference[100];

        FunctionManager fm = getCurrentProgram().getFunctionManager();
        FunctionIterator functions = fm.getFunctions(true);

        for (Function function : functions) {
            if (function.getName().equals(functionName)) {
                /*
                entryPoint = ????; // get the entry point of the function 

                refs = ?????; // get the references to entryPoint
                */
                entryPoint = function.getEntryPoint();
            	refs = (getReferencesTo(entryPoint));
            	
                break;
         
            }
        }
        for (Reference reference : refs) {
            println("Reference to address: " + reference.getFromAddress());
        	
        }
    }
}
