#3.1 Queue()로 큐 만들기(가장 일반적인 큐, FIFO)
import queue

data_queue = queue.Queue()
data_queue.put("funcoding") #funcoding 삽입
data_queue.qsize() #큐의 크기 출력

data_queue.get() #먼저 삽입된 데이터 추출

data_queue.qsize() #큐의 크기 출력(데이터는 빠져나갔기 때문에 0임.)

#3.2 LifoQueue()로 큐 만들기 (LIFO)

data_queue = queue.LifoQueue()
data_queue.put("funcoding")
data_queue.put(1)

data_queue.get() # 마지막에 들어온 데이터가 추출.

#3.3 PriorityQueue()로 큐 만들기

data_queue = queue.PriorityQueue()
data_queue.put((10, "korea"))
data_queue.put((5, 1))
data_queue.put((15, "china"))

data_queue.qsize() # 3
data_queue.get() # 우선순위가 가장 높은 5 -> 10 -> 15 순서로 나옴.

#4 리스트 변수로 큐를 다루는 enqueue, dequeue기능 구현해보기
queue_list = list()

def enqueue(data)
	queue_list.append(data)
	
def dequeue()
	data = queue_list[0]
	del queue_list[0]
	return data

for index in range(10):
	enqueue(index)
	
len(queue_list) # 10

dequeue() # 0
