# finding specific symbol types
# @author 
# @category GhidraGolf
# @keybinding 
# @menupath 
# @toolbar 

from ghidra.program.model.symbol import SymbolType

def run():
    st = getCurrentProgram().getSymbolTable()
    fm = getCurrentProgram().getFunctionManager()

    defSymbols = st.getDefinedSymbols()

    for symbol in defSymbols:
        if symbol.getSymbolType() == SymbolType.CLASS and symbol.isGlobal(): 
            for child in st.getChildren(symbol):
                if child.getSymbolType() == SymbolType.FUNCTION:
                    println(symbol.getName() + " : " + child.getName())

run()
