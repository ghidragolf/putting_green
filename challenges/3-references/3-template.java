import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;

public class GetRefs extends GhidraScript {

    @Override
    protected void run() throws Exception {
        String functionName = "flag";
        Address entryPoint;
        Reference[] refs;

        FunctionManager fm = getCurrentProgram().getFunctionManager();
        Function[] functions = fm.getFunctions(true);

        for (Function function : functions) {
            if function.getName().equals(functionName) {
                /*
                entryPoint = ????; // get the entry point of the function 

                refs = ?????; // get the references to entryPoint
                */
                break;
            }
        }
        for (Reference reference : refs) {
            println("Reference to address: 0x" + reference.getFromAddress().getOffset());
        }
    }
}