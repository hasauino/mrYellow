from multiprocessing import Process, Queue
import time

def info(title):
    print title


def node1(name,q):
	i=0
	while True:
		i+=0.001
		q.put(i)
		time.sleep(5)
    
def node2(name,q):
	rec=0
	while True: 
		if not q.empty():
			rec=q.get()
		print rec
		time.sleep(1)



if __name__ == '__main__':
	q = Queue(maxsize=1)
	p1 = Process(target=node1, args=('faceDetection',q,))
	p2 = Process(target=node2, args=('arduino',q,))
	p1.start()
	p2.start()

