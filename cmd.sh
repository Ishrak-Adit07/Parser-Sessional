flex 2005105.l
bison -d -t -v test.y
g++ -g lex.yy.c test.tab.c -g
./a.out input.txt
