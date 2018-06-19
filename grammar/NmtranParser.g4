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

parser grammar NmtranParser;
options { tokenVocab=NmtranLexer; }

nmModel :
	EOL*
//	nmHeaderBlock
    (
	nmOptionBlock|
	nmThetaBlock|
	nmMatrixBlock|
	nmStmtBlock
	)*
	;

//nmProbBlock: STRING EOL*;

//nmDataSource:   DATA_BLOCK STRING nmOption* EOL+;

nmOption:	(optionKwd (ASSIGN expression)?
            | optionKwd ASSIGN '(' expression (',' expression )* ')'
			| stringLiteral
			| '(' expression+ ')'
			| nmCompDefn) EOL*
;

optionKwd: OPTION_KWD | ID ;

nmOptionBlock:
			OPTION_BLOCK_NAME EOL* nmOption* EOL+
            ;

nmStmtBlock:
            STMT_BLOCK_NAME EOL*
			(nmStatement)*
            ;

nmStatement:
			(nmClause|nmCondStmt|whileLoop) EOL+ //|nmLimit//|nmOdeInit | nmOdeDefn ||
;

nmClause:
			(nmEquation |nmOdeInit|nmOdeDefn|exitStmt|callStmt)
;
nmThetaBlock: THETA_BLOCK EOL* nmLimit*;

nmMatrixBlock: MATRIX_BLOCK EOL* nmOption* nmMatrix*;

nmEquation:
	 ID ('(' expression ')' )? (ASSIGN expression)?
;

callStmt: CALL expression;

exitStmt : ID integerLiteral integerLiteral;


nmOdeInit:
	 A_0  '(' integerLiteral ')' ASSIGN expression
;

nmOdeDefn:
	 DADT  '(' integerLiteral ')' ASSIGN expression
;

nmLimit :
	 (('(' expression ((','? expression ((','? expression)|',')? )|',')? ')' ID?)
			|  '(' (expression  ID?) ')'
			|  (expression  ID?) ) EOL+
;

nmMatrix:
    (expression+ ID*
    | '(' expression+ ID* ')' ) EOL+
    ;

nmCompDefn :
	 ID ('(' ID+ ')')? ( ASSIGN expression)?
;


expression: orexpression
;

orexpression
        :   andexpression
	    |   orexpression  OR andexpression
	    ;


andexpression
        :   equalityexpression
        |   andexpression AND equalityexpression
        ;


equalityexpression
        :   relationalexpression
        |   equalityexpression (EQ | NE) relationalexpression
        ;


relationalexpression
        :   rangeExpression
        |   relationalexpression (GE | LE | GT | LT) rangeExpression
        ;


rangeExpression
        :   additiveexpression
        |   rangeExpression COLON additiveexpression
        ;

additiveexpression
        :   multiplicativeexpression
        |   additiveexpression (PLUS|MINUS) multiplicativeexpression
        ;

multiplicativeexpression
        :   powerexpression
        |   multiplicativeexpression (MUL|DIV) powerexpression
        ;

powerexpression
        :   unaryexpression
        |   powerexpression POW unaryexpression
;

unaryexpression :
	((MINUS|PLUS))? primaryexpression
;

primaryexpression :
		stringLiteral|
		integerLiteral|
		realLiteral|
		functionCall|
//		UtilityReference|
//		EtaLiteral|
//		EpsLiteral|
//		ThetaLiteral|
		symbolReference|
//		compAssign |
//		odeRef|
		parenthesis //|
//		SpecialVars
;

nmCondStmt :
	IF '(' expression ')' THEN EOL+ nmStatement+ (ELSE EOL+ nmStatement* )? ((END IF)|ENDIF)
	| IF '(' expression ')' nmClause //(ELSE EOL+ nmStatement+ )?
;


whileLoop :
	DO WHILE '(' expression ')' EOL+ nmStatement+ END DO
;



parenthesis :  '(' expression ')';

compAssign: '(' expression expression+ ')'
        ;

symbolReference :  ID;

//odeRef :   'A' '(' dvIdx = integerLiteral ')' ;

functionCall :  ID '(' expression (',' expression)* ')' ;

//SpecialVars :		NAME;

//UtilityReference :  NAME '(' IntegerLiteral ')';

//EpsLiteral :  'EPS' '(' IntegerLiteral ')';
//
//ThetaLiteral :  'THETA' '(' IntegerLiteral ')';

stringLiteral:	STRING

;

integerLiteral:	INT

;


realLiteral: SCIENTIFIC | REAL | (INT ('.')?)

;

//scientificNotation: numberLiteral SCIENTIFIC_E  numberLiteral
//                    ;

//numberLiteral: (PLUS|MINUS)? (INT|REAL);