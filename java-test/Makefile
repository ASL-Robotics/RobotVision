all: test.out Test.class
	java Test

cpp: test.out
	./test.out

Test.class: Test.java
	javac Test.java

test.out: Test.cpp
	g++ Test.cpp -o test.out

clean:
	rm test.out Test.class