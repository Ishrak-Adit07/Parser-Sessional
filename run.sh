flex 2005105.l
bison -d -t -v 2005105.y
g++ -g lex.yy.c 2005105.tab.c -g
./a.out input.txt
