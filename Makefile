all:
	g++ linear_regression.cpp -o linear_regression -std=c++11
	g++ predict.cpp -o predict -std=c++11

fclean:
	rm -f linear_regression
	rm -f predict

run: all
	./linear_regression data.csv price
	./predict 30000
reset_file:
	g++ reset_file.cpp -o reset_file -std=c++11
	./reset_file
	rm -f reset_file

