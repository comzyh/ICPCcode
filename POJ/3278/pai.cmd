g++ gen.cpp -o gen.exe && gen > data.in
g++ main.cpp -o YZ.exe && YZ < data.in >YZ.out
g++ 3278.cpp -o ZYH.exe && ZYH < data.in > ZYH.out
fc ZYH.out ZYH.out
pause