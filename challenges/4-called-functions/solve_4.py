def run():
    functions = getCurrentProgram().getFunctionManager().getFunctions(True)
        
    while functions.hasNext():
        func = functions.next()
        if func.getName() == "secondMain":
            """
            calledFunctions = ????? # get called functions of func
            """
            
            for calledFunc in calledFunctions:
                """
                functionName = ?????? # get name of calledFunc
                """
                println("Called function: " + functionName)

run()

