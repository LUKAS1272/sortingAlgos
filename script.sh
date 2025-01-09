# insertion sort (unsorted)
gcc ./algos/insertion/int.c && time ./a.out < ./inputs/unsorted/int_1m.txt > ./outputs/insertion/int_u.txt
gcc ./algos/insertion/string.c && time ./a.out < ./inputs/unsorted/word_1m.txt > ./outputs/insertion/word_u.txt
gcc ./algos/insertion/float.c && time ./a.out < ./inputs/unsorted/float_1m.txt > ./outputs/insertion/float_u.txt
gcc ./algos/insertion/string.c && time ./a.out < ./inputs/unsorted/string_1m.txt > ./outputs/insertion/string_u.txt

# bubble sort (unsorted)
gcc ./algos/bubble/int.c && time ./a.out < ./inputs/unsorted/int_1m.txt > ./outputs/bubble/int_u.txt
gcc ./algos/bubble/string.c && time ./a.out < ./inputs/unsorted/word_1m.txt > ./outputs/bubble/word_u.txt
gcc ./algos/bubble/float.c && time ./a.out < ./inputs/unsorted/float_1m.txt > ./outputs/bubble/float_u.txt
gcc ./algos/bubble/string.c && time ./a.out < ./inputs/unsorted/string_1m.txt > ./outputs/bubble/string_u.txt

# selection sort (unsorted)
gcc ./algos/selection/int.c && time ./a.out < ./inputs/unsorted/int_1m.txt > ./outputs/selection/int_u.txt
gcc ./algos/selection/string.c && time ./a.out < ./inputs/unsorted/word_1m.txt > ./outputs/selection/word_u.txt
gcc ./algos/selection/float.c && time ./a.out < ./inputs/unsorted/float_1m.txt > ./outputs/selection/float_u.txt
gcc ./algos/selection/string.c && time ./a.out < ./inputs/unsorted/string_1m.txt > ./outputs/selection/string_u.txt

# selection sort (sorted)
gcc ./algos/selection/int.c && time ./a.out < ./inputs/sorted/int_1m.txt > ./outputs/selection/int_s.txt
gcc ./algos/selection/string.c && time ./a.out < ./inputs/sorted/word_1m.txt > ./outputs/selection/word_s.txt
gcc ./algos/selection/float.c && time ./a.out < ./inputs/sorted/float_1m.txt > ./outputs/selection/float_s.txt
gcc ./algos/selection/string.c && time ./a.out < ./inputs/sorted/string_1m.txt > ./outputs/selection/string_s.txt

# quick sort (unsorted)
gcc ./algos/quick/string.c && time ./a.out < ./inputs/unsorted/word_1m.txt > ./outputs/quick/word_u.txt
gcc ./algos/quick/string.c && time ./a.out < ./inputs/sorted/word_1m.txt > ./outputs/quick/word_s.txt