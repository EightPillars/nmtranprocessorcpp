NMTRAN Parser
==================

This project provides a C++ NMTRAN parser.  The aim is to develop this code into an R package that can load
and NMTRAN file into an R Object that can be modified within R.

Currently the parser has been written and the R package is work in progress.

It is developed by Stuart Moodie.

## Architecture/Design

The parser has been developed using ANTLR4 (http://www.antlr.org) and its C++ runtime (https://github.com/antlr/antlr4/blob/master/doc/targets.md).

NMTRAN cannot be parsed by the standard Lexer used in ANTLR, which expects the terminal type to be determined by a string
regex.  In NMTRAN terminal type is also determined by context.  So for example the text after the `$PROBLEM` block is
treated as a string, but text after the $PK block is treat as variable name:

```
$PROBLEM varId is not variable name, but a string

$PK
varId = THETA(1) ; varId is a variable name
```      

To address this there are 2 options if using ANTLR:

1. Write a custom lexer.
2. Pre-process the NMTRAN file to turn context dependent terminals into content independent one.

I've chosen option 2 here.  This certainly is the easiest option and has proven to be effective in getting something
 working quickly.  So for example:
 
```
$PROBLEM varId is not variable name, but a string
```

becomes

```
$PROBLEM "varId is not variable name, but a string"
```
   
and the ANTLR Lexer/Parser can now assume that all strings in NMTRAN are delimited with quotes.    
   
The performance overhead of the preprocessing step is minimal.


## Building the code

The code is built using CMAKE:

```
cmake CMakeLists.txt

make
```

## Caveats

1. The code is very much in development.
2. I have focussed on getting something working rather and proving that this approach work then exhaustively testing
 everything.
3. The tests here are limited, but the grammar is identical to that used by the Java version of the
 NMTRAN parser, [nmparserj](https://github.com/EightPillars/nmtranparserj), which has an extensive suite of tests.
       
  
  
  