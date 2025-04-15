clear
gcc -Wall -Wextra -Wunused -Wmissing-declarations -std=c99 -I./hfiles/ -o bin/HomelessSim src/*.c -lraylib -lGL -lm -lpthread -ldl -lrt
bin/HomelessSim
