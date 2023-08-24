all: a.out libmylog.so

libmylog.so: c_api.h    c_wrap.cc  log.cc     log.h
	g++ -Wall -std=c++11 -fPIC -shared c_wrap.cc log.cc -o libmylog.so

a.out: test.c libmylog.so
	g++ -Wall test.c -L. -lmylog -o a.out


.PHONY: clean

clean:
	rm a.out libmylog.so
