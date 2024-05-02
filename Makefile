all:
	g++ linear_regression.cpp -o linear_regression -std=c++11

fclean:
	rm -f linear_regression

run: all
	./linear_regression

