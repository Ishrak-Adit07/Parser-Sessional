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

unit: //var_declaration {
    //     logStream << "At line no: " << line_count << " unit: var_declaration" << "\n"  << endl;

    //     $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
    //     logStream << $1->getName() << "\n"  << endl;
    // }
     func_declaration {
        logStream << "At line no: " << line_count << " unit: func_declaration" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }
    /*| func_definition {
        logStream << "At line no: " << line_count << " unit: func_definition" << "\n"  << endl;

        $$ = new SymbolInfo($1->getName(), "NON_TERMINAL");
        logStream << $1->getName() << "\n"  << endl;
    }*/
    ;

func_declaration: type_specifier ID embedded LPAREN parameter_list RPAREN embedded_out_dec SEMICOLON {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)$5->getName()+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        name = (string)$2->getName();
        parameterList.clear();
    }
    | type_specifier ID embedded LPAREN RPAREN embedded_out_dec SEMICOLON {
        logStream << "At line no: " << line_count << " func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON" << "\n"  << endl;

        $$ = new SymbolInfo((string)$1->getName()+(string)" "+(string)$2->getName()+(string)"("+(string)")"+(string)";"+(string)"\n"+(string)"\n", "NON_TERMINAL");
        logStream << $$->getName() << endl;

        name = (string)$2->getName();
        parameterList.clear();
    }
    ;


embedded: {
            /* NOTICE: embedded action */
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

parameter_list: parameter_list COMMA type_specifier ID {
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
        | type_specifier ID {
            logStream << "At line no: " << line_count << " parameter_list: type_specifier ID" << "\n"  << endl;

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
    }
 		| VOID {
            //$$ = new SymbolInfo("void", "NON_TERMINAL");
            logStream << "At line no: " << line_count << " type_specifier: VOID" << "\n"  << endl;
            logStream << "void" << "\n"  << endl;

            type = "void";
    }
 	;
 

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