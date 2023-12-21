gcc -Wall -Wextra -pedantic -Og -ggdb -DSTATIC= start.c -c
gcc -Wall -Wextra -pedantic -Og -ggdb -DSTATIC= stop.c -c
gcc -Wall -Wextra -pedantic -Og -ggdb -DSTATIC= stop_watch.c -c
gcc -Wall -Wextra -pedantic -Og -ggdb main.c -c
gcc start.o stop.o stop_watch.o main.o -o main
./main
