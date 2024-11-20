# filename="test_cases/1_h.txt"
# g++ input_generator.cpp -o ig
# ./ig > 10_k.txt
# echo "Input generated"
g++ main.cpp -o main
./main < ./test_cases/1_h.txt 
g++ output_validator.cpp -o ov
./ov < ./test_cases/1_h.txt
