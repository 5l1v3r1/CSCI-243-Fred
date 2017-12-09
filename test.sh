#!/bin/bash
echo "valgrind --leak-check=full --track-origins=yes ./fred </dev/null"
valgrind --leak-check=full --track-origins=yes ./fred </dev/null

echo "valgrind --leak-check=full --track-origins=yes ./fred -s sym.1"
valgrind --leak-check=full --track-origins=yes ./fred -s sym.1

echo "valgrind --leak-check=full --track-origins=yes ./fred -s sym.2"
valgrind --leak-check=full --track-origins=yes ./fred -s sym.2

echo "valgrind --leak-check=full --track-origins=yes ./fred -s sym.3"
valgrind --leak-check=full --track-origins=yes ./fred -s sym.3

echo "valgrind --leak-check=full --track-origins=yes ./fred"
valgrind --leak-check=full --track-origins=yes ./fred