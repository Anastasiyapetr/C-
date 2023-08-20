/**
@mainpage 
                        Smart calculator includes math calculator and credit calculator
                        - The program is developed in C language using QT libraries and modules, that simulates the program interface.
                        - The program builts with Makefile which contains set of targets: all, install, uninstall, clean, dvi, dist, test, gcov_report.
                        - The program includes coverage of modules related to calculating expressions with unit-tests using the Check library (target test in Makefile).
                        
                        ###MATHEMATICAL CALCULATOR:###
                        
                        - Calculation of expressions in the math calculator is based on Dijkstra's algorithm (converting expressions (including functions) from infix to Reverse Polish notation)
                        - The calculation does after you complete entering the calculating expression and press the `=` symbol.
                        - Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable _x_ as a number.
                        - Plotting a graph of a function given by an expression in infix notation with the variable _x_ (with coordinate axes, mark of the used scale and an adaptive grid)
                        - To plot a graph of a function it is necessary to additionally specify the displayed domain (default value - [-100, 100]).
                        - Users can to enter up to 255 characters
                        - The calculator support the following arithmetic operations and mathematical functions:
                        
                        - **Arithmetic operators**:

                        | Operator name | Infix notation <br /> (Classic)
                        | --------- | ------ |
                        | Brackets | (a + b) |
                        | Addition | a + b |
                        | Subtraction | a - b |
                        | Multiplication | a * b |
                        | Division | a / b |
                        | Power | a ^ b |
                        | Modulus | a mod b |
                        | Unary plus | +a |
                        | Unary minus | -a |
                        

                        - **Functions**:

                            | Function description | Function |
                            | ------ | ------ |
                            | Computes cosine | cos(x) |
                            | Computes sine | sin(x) |
                            | Computes tangent | tan(x) |
                            | Computes arc cosine | acos(x) |
                            | Computes arc sine | asin(x) |
                            | Computes arc tangent | atan(x) |
                            | Computes square root | sqrt(x) |
                            | Computes natural logarithm | ln(x) |
                            | Computes common logarithm | log(x) |
                    
                    ###CREDIT CALCULATOR:###

                        - Input: total credit amount, term, interest rate, type (annuity, differentiated)
                        - Output: monthly payment, overpayment on credit, total payment

*/
