LIB = -lrt

all: cons prod

cons: consumer.c
	gcc -o cons consumer.c $(LIB)

prod: producer.c
	gcc -o prod producer.c $(LIB)

run: cons prod
	./prod
	./cons

clean:
	rm -f cons prod
