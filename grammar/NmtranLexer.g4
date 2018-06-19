/*******************************************************************************
 * Copyright (c) 2018 Eight Pillars Ltd.
 *
 * This file is part of the NMTRAN Parser.
 *
 * The NMTRAN Parser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The NMTRAN Parser Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with The NMTRAN Parser.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

lexer grammar NmtranLexer;

ASSIGN: '=';

MUL: '*';

DIV: '/';

PLUS: '+';

MINUS: '-';

POW: '^'|'**';

EOL: NEWLINE;

DO: 'DO';

WHILE: 'WHILE';

CALL: 'CALL';

IF: 'IF';

THEN: 'THEN';

ELSE: 'ELSE';

END: 'END';

ENDIF: 'ENDIF';

EQ: '.EQ.'|'==';

NE: '.NE.';

GT: '.GT.'|'>';

LT: '.LT.'|'<';

GE: '.GE.'|'>=';

LE: '.LE.'|'<=';

OR: '.OR.';

AND: '.AND.';

COMMA: ',';

LPAREN: '(';

RPAREN: ')';

COLON:  ':';

THETA_BLOCK: '$THETA';

MATRIX_BLOCK: '$' ('OMEGA'|'SIGMA');

//IGNORE: 'IGNORE' -> pushMode(RAW_STRINGS);

//FILE: 'FILE' -> pushMode(RAW_STRINGS);

OPTION_BLOCK_NAME :	'$' ('INP' |'SUB'|'EST'|'TAB'|'COV'|'SUB'|'MOD'|'SIZ'|'PRO'|'DAT'|'MSF'|'ABB'|'SIM'|'CON') [A-Z]*;

STMT_BLOCK_NAME: '$' ('PK'|'DES'|'PRE'[A-Z]*|('ERR' [A-Z]*)|'MIX' [A-Z]*);

//COMP:   'COMP';

A_0:    'A_0';

DADT:   'DADT';

//BLOCK_NAME :	'$' ID;

//SCIENTIFIC: NUMBER+ 'E' (MINUS|PLUS)? NUMBER;

OPTION_KWD: [-] ('0'..'9') ID;

ID:  (('a'..'z')|('A'..'Z')) (('a'..'z')|('A'..'Z')|('0'..'9')|'_')*;

//IGNORE_CHAR: '£'|'#'|'@';

STR_COMMENT: '"' (~('"'|'\n'|'\r'))* -> skip;

SL_COMMENT:	';' ~('\n'|'\r')* -> skip ;

STRING:		'"' (~('"'|'\n'|'\r'))* '"';

SCIENTIFIC: /*(PLUS|MINUS)?*/ NUMBER SCIENTIFIC_E (PLUS|MINUS)? NUMBER
                    ;

//INT : ('0'..'9')+;

INT: DIGIT+;

REAL: (DIGIT* '.' DIGIT+) ;

DOT: '.';

//REAL: (('0' .. '9') +)? '.' ('0' .. '9')+
//        ;


WS:			(' '|'\t') -> skip;

NEWLINE:		('\r'? '\n');

fragment NUMBER: INT|REAL;

fragment DIGIT: [0-9];

fragment SCIENTIFIC_E: 'E';



//mode RAW_STRINGS;
//
//RAW_WS:			(' '|'\t') -> skip;
//
//RAW_ASSIGN: '=';
//
//RAW_STRING: (~('\r'|'\n'|' '|'\t'|'='))+(~('\r'|'\n'|' '|'\t'))* -> popMode;
//
//mode PROB_STRING;
//
//RAW_PROB_STR: WS* (.)+? WS* EOL -> popMode;