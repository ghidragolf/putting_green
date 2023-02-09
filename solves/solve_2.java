//metadata collection
//@author 
//@category GhidraGolf
//@keybinding 
//@menupath 
//@toolbar 

import ghidra.app.script.GhidraScript;

public class solve_2 extends GhidraScript {

    @Override
    public void run() {

        /* find the missing function. Replace CHANGEME */
        println(getCurrentProgram().getExecutablePath()); // get executable path
        println(getCurrentProgram().getName()); // get name
        println(getCurrentProgram().getExecutableMD5()); // get md5sum
    }
}
