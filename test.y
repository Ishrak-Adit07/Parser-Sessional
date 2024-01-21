%{
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "2005105_Symboltable.cpp"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE* yyin;

int line_count = 1;  // NOTICE
int error_count = 0;
int scope_count = 1;

FILE* input;
ofstream logStream;
ofstream error;

//int scopeTablesSize = 10;

//Root scopetable for global scope, with new SymbolTable
//ScopeTable* scopeTable = new ScopeTable(scopeTablesSize);
//SymbolTable* symbolTable = new SymbolTable(scopeTable, scopeTablesSize, logStream);

SymbolTable* symbolTable;

/* auxiliary variables and structures and containers */
string type, type_final;  // basially for function declaration-definition
string name, name_final;  // basically for function declaration-definition

struct var{
    string var_name;
    int var_size;  // it is set to -1 for variables
} temp_var;

vector<var> var_list;  /* for identifier(variable, array) insertion into symbolTable */
string tempTypeSpecifier; // Holds type specifier temporarily while variable declaration;

Parameter tempParameter; //Holds parameter temporarily before pushing into parameter List
vector<Parameter> parameterList;  // parameter list for identifiers such as function declaration, definition

vector<string> argumentList;  // argument list for function call

/*
void insertVariable(string _type, var var_in) {
    // symbolTable insertion for variable and array 
    SymbolInfo* symbolInfo = new SymbolInfo(var_in.var_name, "ID");
    symbolInfo->setReturnType(_type);  // setting variable type
    symbolInfo->setArraySize(var_in.var_size);

    symbolTable->insertSymbol(*symbolInfo);
    return ;
}
*/

//Functions for inserting identifiers into SymbolTable

//For variables and arrays
//arraySize set to -1 for variables
void insertVariable(string Type, string Name, int arraySize) {

    SymbolInfo* symbolInfo = new SymbolInfo(Name, "ID");
    symbolInfo->setReturnType(Type);  // setting variable type
    symbolInfo->setArraySize(arraySize);

    symbolTable->Insert(symbolInfo);
    return;
}

//For function declarations and definitions
//FuncDecDefBySize = -2 for declarations and -3 for definitions
void insertFunction(string Type, string Name, int FuncDecDefBySize) {

    SymbolInfo* symbolInfo = new SymbolInfo(Name, "ID");
    symbolInfo->setReturnType(Type);  // setting return type of function
    symbolInfo->setArraySize(FuncDecDefBySize);

    for(Parameter p : parameterList){
        symbolInfo->addToParameterList(p);
    }

    symbolTable->Insert(symbolInfo);
    return;
}

/* yyerror prototype function for reporting syntax error */
void yyerror(string s);
%}

%define api.value.type {SymbolInfo*}

%token CONST_INT CONST_FLOAT ID DO SWITCH DEFAULT BREAK
%token CASE CONTINUE CONST_CHAR
%token INT FLOAT VOID IF ELSE FOR WHILE PRINTLN RETURN MAIN CHAR DOUBLE

%token ASSIGNOP NOT INCOP DECOP LOGICOP RELOP ADDOP MULOP BITOP
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON 

%token SINGLE_LINE_STRING MULTI_LINE_STRING UNFINISHED_STRING
%token MULTI_LINE_COMMENT UNFINISHED_COMMENT SINGLE_LINE_COMMENT

%token UNFINISHED_NUMBER TOO_MANY_DECIMAL_POINTS ILLFORMED_NUMBER EMPTY_CONST_CHAR
%token UNFINISHED_CONST_CHAR MULTICHAR_CONST_CHAR UNRECOGNIZED_CHAR INVALID_ID_SUFFIX_NUM_PREFIX

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start: program {
        logStream << "At line no: " << (line_count-1) << " start: program" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
	}
	;

program: program unit {   
        logStream << "At line no: " << line_count << " program: program unit" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)$2->getName(), "NON_TERMINAL");
        logStream << $$->getName() << "\n"  << endl;
    }
	| unit {
        logStream << "At line no: " << line_count << " program: unit" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }
	;

unit: /*var_declaration {
        logStream << "At line no: " << line_count << " unit: var_declaration" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }
    |
    */ func_declaration {
        logStream << "At line no: " << line_count << " unit: func_declaration" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }
    /*
    | func_definition {
        logStream << "At line no: " << line_count << " unit: func_definition" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }
    */
    ;
     
func_declaration: type_specifier id embedded LPAREN parameter_list RPAREN embedded_out_dec SEMICOLON {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)$5->getName()+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        //name = (string)$2->getName();
        parameterList.clear();
    }
    | type_specifier id embedded LPAREN RPAREN embedded_out_dec SEMICOLON {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        //name = (string)$2->getName();
        parameterList.clear();
    }
    ;

func_definition: type_specifier id embedded LPAREN parameter_list RPAREN embedded_out_def compound_statement {
        logStream << "At line no: " << line_count << " func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)$5->getName()+(string)")"+(string)$8->getName()+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        //name = (string)$2->getName();
    }
    | type_specifier id embedded LPAREN RPAREN embedded_out_def compound_statement {
        logStream << "At line no: " << line_count << " func_definition: type_specifier ID LPAREN RPAREN compound_statement" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)")"+(string)$7->getName()+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        //name = (string)$2->getName();
    }
    ;		

embedded: {
            type_final = type;
            name_final = name;
    }
    ;	

embedded_out_dec: {

            SymbolInfo* lookupNode = symbolTable->Lookup(name_final);

            if(lookupNode == NULL){ //Not previously declared/defined
                //Inserting into symbolTable, -2 denoting function declaration
                insertFunction(type_final, name_final, -2); 
            }
            else{//Previously declared
                error << "Error at line no: " << line_count << " multiple declaration of " << name_final << "\n" << endl;
                error_count++;
            }
    }
    ;		


embedded_out_def: {

            SymbolInfo* lookupNode = symbolTable->Lookup(name_final);

            if(lookupNode == NULL) { //Not previously declared/defined
                //Inserting into symbolTable, -3 denoting function definition
                insertFunction(type_final, name_final, -3);
            } 

            else if(lookupNode->getArraySize() == -1) {
                // Previously declared variable found 
                error << "Error at line no: " << line_count << " variable with name " << name_final << " declared earlier\n" << endl;
                error_count++;
            }

            else if(lookupNode->getArraySize() == -3) {
                // Previously defined function found 
                error << "Error at line no: " << line_count << " multiple definition of " << name_final << "\n" << endl;
                error_count++;
            } 

            else {// Previously declared function found, so no problem 

                // Checking consistencies within declaration and definition
                if(lookupNode->getReturnType() != type_final) {
                    // return type not matching 
                    error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                    error_count++;

                } 

                //Two cases for void param**
                //Void param provided in declaration, no param provided in definition, no problem
                else if(lookupNode->getParameterListSize()==1 && parameterList.size()==0 && lookupNode->getParameter(0).getType()=="void") {
                    lookupNode->setArraySize(-3);  // NOTICE: given function declaration has a matching definition, so it can be called
                } 
                //No param provided in declaration, void param provided in definition, no problem
                else if(lookupNode->getParameterListSize()==0 && parameterList.size()==1 && parameterList[0].getType()=="void") {
                    lookupNode->setArraySize(-3);  // NOTICE: given function declaration has a matching definition, so it can be called
                } 
                //Two cases for void param**

                //Parameter list size between declaration and definition not matching 
                else if(lookupNode->getParameterListSize() != parameterList.size()) {
                    error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                    error_count++;
                } 

                //Parameter list size between declaration and definiton matching, so now we match params' types
                else {

                    bool validParameterList = true; //Valid if all parameters are valid

                    // Checking parameter list size 
                    if(lookupNode->getParameterListSize() == parameterList.size()) {
                        //Size matched, set identifier as function defintion
                        lookupNode->setArraySize(-3);
                    } else {
                        //Size not matched, function definition not valid
                        validParameterList = false;
                    }

                    // Checking params' types
                    if(validParameterList){ //If sizes matched, only then we check types
                        for(int i=0; i<parameterList.size(); i++) {
                            if(lookupNode->getParameter(i).getType() != parameterList[i].getType()) {
                                validParameterList = false; //If any of the param's type does not match
                                break;                      //function definition is invalid
                            }
                        }
                    }

                    if(!validParameterList){
                        error << "Error at line no: " << line_count << " inconsistent function definition with its declaration for " << name_final << "\n" << endl;
                        error_count++;
                    }

                }
            }
    }
    ;	

parameter_list: parameter_list COMMA type_specifier id {
            logStream << "At line no: " << line_count << " parameter_list: parameter_list COMMA type_specifier ID" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName()+(string)","+(string)$3->getName()+(string)" "+(string)$4->getName(), "NON_TERMINAL");
            logStream << $$->getName() << endl;

            //Adding parameter to list
            tempParameter.setType((string)$3->getName());
            tempParameter.setName((string)$4->getName());

            parameterList.push_back(tempParameter);
    }
        | parameter_list COMMA type_specifier {
            logStream << "At line no: " << line_count << " parameter_list: parameter_list COMMA type_specifier" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName()+(string)","+(string)$3->getName(), "NON_TERMINAL");
            logStream << $$->getName() << endl;

            //Adding parameter to list            
            tempParameter.setType((string)$3->getName());
            tempParameter.setName("");

            parameterList.push_back(tempParameter);
    }
        | type_specifier id {
            logStream << "At line no: " << line_count << " parameter_list: type_specifier ID" << "\n"  << endl;

            logStream << $1->getName() << endl;

            $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName(), "NON_TERMINAL");
            logStream << $$->getName() << endl;

            //Adding parameter to list            
            tempParameter.setType((string)$1->getName());
            tempParameter.setName((string)$2->getName());

            parameterList.push_back(tempParameter);
    }
        | type_specifier {
            logStream << "At line no: " << line_count << " parameter_list: type_specifier" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName(), "NON_TERMINAL");
            logStream << $$->getName() << endl;

            //Adding parameter to list
            tempParameter.setType((string)$1->getName());
            tempParameter.setName("");

            parameterList.push_back(tempParameter);
    }
    ;

compound_statement: /*LCURL embedded_in statements RCURL {
            logStream << "At line no: " << line_count << " compound_statement: LCURL statements RCURL" << "\n"  << endl;

            $$ = new SymbolInfo((string)"{ "+(string)"\n"+(string)$3->getName()+(string)"}"+(string)"\n", "NON_TERMINAL");  // NOTICE
            logStream << $$->getName() << endl;

            //Printing all scopetables before exiting current scopetable as per offline requirement
            symbolTable->printAllScopeTable(logStream);
            symbolTable->ExitScope();
    }
    |*/ LCURL embedded_in RCURL {
            logStream << "At line no: " << line_count << " compound_statement: LCURL RCURL" << "\n"  << endl;

            $$ = new SymbolInfo((string)"{ "+(string)"\n"+(string)"\n"+(string)"}"+(string)"\n", "NON_TERMINAL");  // NOTICE
            logStream << $$->getName() << endl;

            //Printing all scopetables before exiting current scopetable as per offline requirement
            symbolTable->printAllScopeTable(logStream);
            symbolTable->ExitScope();
    }
        ;

embedded_in: {
            /* NOTICE: embedded action */
            symbolTable->EnterScope();

            /* If a new parameter list is applicable for new scope, we need to insert them into 
            SymbolTable as identifiers (variable) */

            //No params, or void provided
            if(parameterList.size()==1 && parameterList[0].getType()=="void") {
                //No actions necessary
            } 
            //At least one non-void param provided
            else {

                for(Parameter p : parameterList){
                    insertVariable(p.getType(), p.getName(), -1);
                }

            }

            //Clearing parameter list for next usage
            parameterList.clear(); 
    }
    ;

/*	    
var_declaration: type_specifier declaration_list SEMICOLON {
            logStream << "At line no: " << line_count << " var_declaration: type_specifier declaration_list SEMICOLON" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
            logStream << $$->getName() << endl;

            tempTypeSpecifier = (string)$1->getName();
            if(tempTypeSpecifier == "void"){
                error << "Error at line no: " << line_count << " variable type can not be void " << "\n" << endl;
                error_count++;

                tempTypeSpecifier = "float"; //by default, void type specifier, mistakenly provided, will be converted to floats
            }

            /* //NOTICE: symbolTable insertion
            if($1->getName() == "void") {
                error << "Error at line no: " << line_count << " variable type can not be void " << "\n" << endl;
                error_count++;

                for(int i=0; i<var_list.size(); i++) {
                    insertVariable("float", var_list[i]);  // NOTICE: by default, void type variables are float type
                }
            } 
            else {
                for(int i=0; i<var_list.size(); i++) {
                    insertVariable((string)$1->getName(), var_list[i]);
                }
            }

            var_list.clear();
            
    }
 	;
    */
 		 
type_specifier: INT {
            //$$ = new SymbolInfo("int", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: INT" << "\n"  << endl;
            logStream << "int" << "\n"  << endl;

            type = "int";
            
    }
 		| FLOAT {
            //$$ = new SymbolInfo("float", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: FLOAT" << "\n"  << endl;
            logStream << "float" << "\n"  << endl;

            type = "float";
            type_final = type;
    }
 		| VOID {
            //$$ = new SymbolInfo("void", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: VOID" << "\n"  << endl;
            logStream << "void" << "\n"  << endl;

            type = "void";
            type_final = type;
    }
 	;

id: ID {
            //$$ = new SymbolInfo((string)$1->getName(), "NON_TERMINAL");
            name = $1->getName();
            name_final = name;
    }
    ;

/*
statements: statement {
            logStream << "At line no: " << line_count << " statements: statement" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName(), "NON_TERMINAL");
            logStream << $$->getName() << "\n"  << endl;
    }
	    | statements statement {
            logStream << "At line no: " << line_count << " statements: statements statement" << "\n"  << endl;

            $$ = new SymbolInfo((string)$1->getName()+(string)$2->getName(), "NON_TERMINAL");
            logStream << $$->getName() << "\n"  << endl;
    }
	;

    */
 

%%


int main(int argc, char* argv[]) {
	if(argc != 2) {
		cout << "Input file name not provided for parsing." << endl;
		return 0;
	}

    input = fopen(argv[1], "r");

    if(input == NULL) {
		cout << "input file not opened properly, terminating program..." << endl;
		exit(0);
	}

	logStream.open("2005105_log.txt", ios::out);
	error.open("2005105_error.txt", ios::out);
	
	if(logStream.is_open() != true) {
		cout << "Log file not available" << endl;
		fclose(input);
		
		exit(0);
	}
	
	if(error.is_open() != true) {
		cout << "Error file not available" << endl;
		fclose(input);
		logStream.close();
		
		exit(0);
	}
	
    int scopeTablesSize = 10;
	ScopeTable* scopeTable = new ScopeTable(scopeTablesSize);
    symbolTable = new SymbolTable(scopeTable, scopeTablesSize, logStream);
	
	yyin = input;
    yyparse();  // processing starts

    logStream << endl;
	symbolTable->printAllScopeTable(logStream);
	symbolTable->ExitScope();

	logStream << "Total Lines: " << (--line_count) << endl;  // NOTICE here: line_count changed (July 19) -> works for sample
	logStream << "\n" << "Total Errors: " << error_count << endl;
    error << "\n" << "Total Errors: " << error_count << endl;
	
	fclose(yyin);
	logStream.close();
	error.close();
	
	return 0;
} 

void yyerror(string s) {
    /* it may be modified later */
    logStream << "At line no: " << line_count << " " << s << endl;

    line_count++;
    error_count++;
    
    return ;
}